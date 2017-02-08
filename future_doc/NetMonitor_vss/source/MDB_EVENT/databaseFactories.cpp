/////////////////////////////////////////////////////////////////////////
///@system 执行引擎系统
///@company 上海期货信息技术有限公司
///@file databaseFactories.pp
///@brief实现了若干个内存数据库的对象工厂
///@history 
///20060127	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#include "BaseDataStruct.h"
#include "databaseFactories.h"
#include "databaseResources.h"
#include "monitorIndex.h"

//#define COUNT_OPERATION

///强制进行复制，不理会const标记
///@param	target	复制的目标地址
///@param	source	复制的源地址
///@param	size	复制的空间大小
static void forceCopy(const void *target, const void *source, int size)
{
	if ((source==NULL)||(target==NULL))
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","copy from or to null");
		return;
	}
	memcpy((void *)target,source,size);
}

extern int compareForKeyIndexinMonitorEntity(const void *pV1, const void *pV2);
#ifdef COUNT_OPERATION
int addActionForMonitorEntity=0;
int updateWithIndexActionForMonitorEntity=0;
int updateWithoutIndexActionForMonitorEntity=0;
int removeActionForMonitorEntity=0;
int addCommitForMonitorEntity=0;
int updateCommitForMonitorEntity=0;
int removeCommitForMonitorEntity=0;
#endif
void CMonitorEntityFactory::init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly)
{
	if (runLevel>=0) {
		if(!reuse) {
			pKeyIndex=new CAVLTree(maxUnit,compareForKeyIndexinMonitorEntity,pAllocator,reuse,reuseID,readOnly);
			if(pIndexMap != NULL)
				pIndexMap->insert(map<string,int>::value_type("MonitorEntity_KeyIndex",pKeyIndex->getReuseID()));
		}
		else {
			map<string,int>::iterator it = pIndexMap->find("MonitorEntity_KeyIndex");
			if(it != pIndexMap->end()) {
				pKeyIndex=new CAVLTree(maxUnit,compareForKeyIndexinMonitorEntity,pAllocator,reuse,it->second,readOnly);
			}
		}
		if (pKeyIndex==NULL)
			RAISE_RUNTIME_ERROR("Insufficient memory space");
	}
	pLastFoundInSearchByTime=NULL;
	pLastFoundInSearchByAll=NULL;
	pActionTriggers=new vector<CMonitorEntityActionTrigger *>;
	pCommitTriggers=new vector<CMonitorEntityCommitTrigger *>;
	m_activeCommitTrigger=true;
}

CMonitorEntityFactory::CMonitorEntityFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly) :
	CDatabaseDataFactory(sizeof(CMonitorEntity),maxUnit,pAllocator,reuse,reuseID, readOnly)
{
	m_pConfig=NULL;
	init(maxUnit,pAllocator,pIndexMap,reuse,reuseID,readOnly);
}

CMonitorEntityFactory::CMonitorEntityFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly) :
	CDatabaseDataFactory(sizeof(CMonitorEntity),MDB_DEFAULT_BLOCK_SIZE,pAllocator,reuse,reuseID,readOnly)
{
	m_pConfig=pConfig;
	init(MDB_DEFAULT_BLOCK_SIZE,pAllocator,pIndexMap,reuse,reuseID,readOnly);		
}

CMonitorEntityFactory::~CMonitorEntityFactory(void)
{
	if (runLevel>=0) {
		if (pKeyIndex!=NULL)
			delete pKeyIndex;
	}
	if (pActionTriggers!=NULL)
		delete pActionTriggers;
	if (pCommitTriggers!=NULL)
		delete pCommitTriggers;
}

void CMonitorEntityFactory::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CMonitorEntityFactory");
	CDatabaseDataFactory::output(pLogger,indent+1);
	if (runLevel>=0) {
		pKeyIndex->output(pLogger,indent+1);
	}
}

int CMonitorEntityFactory::readCSV(char *filename)
{
	FILE *input;
	CWriteableMonitorEntity thisMonitorEntity;
	char buffer[1025];
	vector<char *> *pNames;
	char *token;
	input=mfopen(filename,"rt");
	if (input==NULL)
		return 0;
	pNames=new vector<char *>;
	fgets(buffer,1024,input);
	token=getNextToken(buffer);
	while (token!=NULL) {
		pNames->push_back(token);
		token=getNextToken(NULL);
	}
	while (thisMonitorEntity.readCSV(input,pNames))
		add(&thisMonitorEntity);
	fclose(input);
	delete pNames;
	return 1;
}

int CMonitorEntityFactory::readCSV(CConfig *pConfig)
{
	char szFileName[300];
	strcpy(szFileName, pConfig->getConfig("CSVReadPath"));
	strcat(szFileName, "MonitorEntity.csv");
	return readCSV(szFileName);
}

int CMonitorEntityFactory::writeCSV(char *filename)
{
	FILE *output;
	CWriteableMonitorEntity *pMonitorEntity;
	output=mfopen(filename,"wt");
	if (output==NULL)
		return 0;
	CWriteableMonitorEntity::writeCSVHead(output);
	pMonitorEntity=(CWriteableMonitorEntity *)(pMem->getFirst());
	while (pMonitorEntity!=NULL) {
		if (!pMonitorEntity->writeCSV(output)) {
			pMem->endGet();
			fclose(output);
			return 0;
		}
		pMonitorEntity=(CWriteableMonitorEntity *)(pMem->getNext());
	}
	pMem->endGet();
	fclose(output);
	return 1;
}

int CMonitorEntityFactory::writeCSV(CConfig *pConfig)
{
	char szFileName[300];
	strcpy(szFileName, pConfig->getConfig("CSVWritePath"));
	strcat(szFileName, "MonitorEntity.csv");
	return writeCSV(szFileName);
}

void CMonitorEntityFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename,"w+b");
	dump(fp);
	if (fp!=NULL) fclose(fp);
}	

void CMonitorEntityFactory::dump(FILE *fp)
{
	int index=0; ///下标
	CWriteableMonitorEntity *pMonitorEntity;
	if(fp==NULL) fp=stdout;
	pMem->dump(fp);
	fprintf(fp,"CMonitorEntityFactory={       Total Count=%d\n", pMem->getCount());
	pMonitorEntity=(CWriteableMonitorEntity *)(pMem->getFirst());
	while (pMonitorEntity!=NULL) {
		pMonitorEntity->dump(fp,index++);
		pMonitorEntity=(CWriteableMonitorEntity *)(pMem->getNext());
	}
	fprintf(fp,"}\n");
	pMem->endGet();
}

void CMonitorEntityFactory::clearAll(void)
{
	CDatabaseDataFactory::clearAll();
	if (runLevel>=0) {
		pKeyIndex->removeAll();
	}
}

CMonitorEntity *CMonitorEntityFactory::internalAdd(CWriteableMonitorEntity *pMonitorEntity, bool bNoTransaction)
{	
#ifdef COUNT_OPERATION
	addActionForMonitorEntity++;
#endif
	CMonitorEntity *pTarget;	
	beforeAdd(pMonitorEntity);
	pTarget=(CMonitorEntity *)createObject();
	if (pTarget==NULL) {
		RAISE_DESIGN_ERROR("Can not alloc enough MonitorEntity in memory database");
		return NULL;
	}
	forceCopy(pTarget, pMonitorEntity, sizeof(CMonitorEntity));
	pMem->updateObject(pTarget);
	if (runLevel>=0) {
		pKeyIndex->addObject(pTarget);
	}
	afterAdd(pTarget);
	if (bNoTransaction) {
		commitAdd(pTarget);
	}
	return pTarget;
}

CMonitorEntity *CMonitorEntityFactory::add(CWriteableMonitorEntity *pMonitorEntity, CTransaction *pTransaction)
{
	pMonitorEntity->calAllHash();
	if (pTransaction==NULL) {
		return internalAdd(pMonitorEntity,true);
	}
	else {
		CMonitorEntity *pNewMonitorEntity;
		pNewMonitorEntity = internalAdd(pMonitorEntity,false);
		pTransaction->addResource(CMonitorEntityResource::alloc(CREATE_ACTION,this,pNewMonitorEntity,NULL));
		return pNewMonitorEntity;
	}
}

void CMonitorEntityFactory::internalUpdate(CMonitorEntity *pMonitorEntity, CWriteableMonitorEntity *pNewMonitorEntity, bool updateIndex,bool bNoTransaction)
{
#ifdef COUNT_OPERATION
	if (updateIndex) {
		updateWithIndexActionForMonitorEntity++;
	}
	else {
		updateWithoutIndexActionForMonitorEntity++;
	}
#endif
	CWriteableMonitorEntity theOldMonitorEntity;
	beforeUpdate(pMonitorEntity,pNewMonitorEntity);
	if (bNoTransaction) {
		forceCopy(&theOldMonitorEntity,pMonitorEntity,sizeof(CMonitorEntity));
	}
	CAVLNode *pKeyIndexNode=NULL;
	if (updateIndex) {
		if (runLevel>=0) {
			pKeyIndexNode=pKeyIndex->findObject(pMonitorEntity);
		}
	}

	forceCopy(pMonitorEntity,pNewMonitorEntity,sizeof(CMonitorEntity));
	pMem->updateObject(pMonitorEntity);
	if (updateIndex) {
		if (runLevel>=0) {
			pKeyIndex->updateNode(pKeyIndexNode);
		}
	}
	afterUpdate(pMonitorEntity);
	if (bNoTransaction) {
		commitUpdate(pMonitorEntity,&theOldMonitorEntity);
	}
}

void CMonitorEntityFactory::update(CMonitorEntity *pMonitorEntity, CWriteableMonitorEntity *pNewMonitorEntity, CTransaction *pTransaction, bool updateIndex)
{
	pNewMonitorEntity->updateAllHash();
	if (pTransaction==NULL) {
		internalUpdate(pMonitorEntity,pNewMonitorEntity,updateIndex,true);
	}
	else {
		pTransaction->addResource(CMonitorEntityResource::alloc(UPDATE_ACTION,this,pMonitorEntity,pNewMonitorEntity,updateIndex));
		internalUpdate(pMonitorEntity,pNewMonitorEntity,updateIndex,false);
	}
}

void CMonitorEntityFactory::internalRemove(CMonitorEntity *pMonitorEntity, bool bNoTransaction)
{
#ifdef COUNT_OPERATION
	removeActionForMonitorEntity++;
#endif
	CWriteableMonitorEntity theOldMonitorEntity;
	beforeRemove(pMonitorEntity);
	if (bNoTransaction) {
		forceCopy(&theOldMonitorEntity,pMonitorEntity,sizeof(CMonitorEntity));
	}
	if (runLevel>=0) {
		pKeyIndex->removeObject(pMonitorEntity);
	}
	pMem->free(pMonitorEntity);
	if(bNoTransaction) {
		commitRemove(&theOldMonitorEntity);
	}
}

void CMonitorEntityFactory::remove(CMonitorEntity *pMonitorEntity, CTransaction *pTransaction)
{
	if (pTransaction==NULL) {
		internalRemove(pMonitorEntity,true);
	}
	else {
		pTransaction->addResource(CMonitorEntityResource::alloc(DELETE_ACTION,this,pMonitorEntity,NULL));
		internalRemove(pMonitorEntity,false);		
	}
}

CMonitorEntity* CMonitorEntityFactory::addOrUpdate(CMonitorEntity *pMonitorEntity, CWriteableMonitorEntity *pNewMonitorEntity, CTransaction *pTransaction, bool updateIndex)
{
	if(pMonitorEntity == NULL) {
		return add(pNewMonitorEntity,pTransaction);
	}
	else {
		update(pMonitorEntity,pNewMonitorEntity,pTransaction,updateIndex);
		return pMonitorEntity;
	}
}

void CMonitorEntityFactory::retrieve(CMonitorEntity *pMonitorEntity, CWriteableMonitorEntity *pTargetMonitorEntity)
{
	forceCopy(pTargetMonitorEntity, pMonitorEntity, sizeof(CMonitorEntity));
}
	
int CMonitorEntityFactory::addActionTrigger(CMonitorEntityActionTrigger *pActionTrigger)
{
	pActionTrigger->setFactory(this);
	pActionTriggers->push_back(pActionTrigger);
	return 1;
}

int CMonitorEntityFactory::removeActionTrigger(CMonitorEntityActionTrigger *pActionTrigger)
{
	for (int i=0;i<(int)pActionTriggers->size();i++) {
		if (pActionTriggers->at(i)==pActionTrigger) {
			pActionTriggers->erase(pActionTriggers->begin()+i);
			return 1;
		}
	}
	return 0;
}

int CMonitorEntityFactory::addCommitTrigger(CMonitorEntityCommitTrigger *pCommitTrigger)
{
	pCommitTrigger->setFactory(this);
	pCommitTriggers->push_back(pCommitTrigger);
	return 1;
}

int CMonitorEntityFactory::removeCommitTrigger(CMonitorEntityCommitTrigger *pCommitTrigger)
{
	for (int i=0;i<(int)pCommitTriggers->size();i++) {
		if (pCommitTriggers->at(i)==pCommitTrigger) {
			pCommitTriggers->erase(pCommitTriggers->begin()+i);
			return 1;
		}
	}
	return 0;
}

CMonitorEntity *CMonitorEntityFactory::getFirst(void)
{
	CMonitorEntity *pResult=(CMonitorEntity *)(pMem->getFirst());
	return pResult;
}
	
CMonitorEntity *CMonitorEntityFactory::getNext(void)
{
	CMonitorEntity *pResult=(CMonitorEntity *)(pMem->getNext());
	return pResult;
}
	
void CMonitorEntityFactory::endGet(void)
{
	pMem->endGet();
}

void CMonitorEntityFactory::beforeAdd(CWriteableMonitorEntity *pMonitorEntity)
{
	for (int i=pActionTriggers->size()-1;i>=0;i--) {
		pActionTriggers->at(i)->beforeAdd(pMonitorEntity);
	}
}
	
void CMonitorEntityFactory::afterAdd(CMonitorEntity *pMonitorEntity)
{
	for (int i=0;i<(int)pActionTriggers->size();i++) {
		pActionTriggers->at(i)->afterAdd(pMonitorEntity);
	}
}

void CMonitorEntityFactory::beforeUpdate(CMonitorEntity *pMonitorEntity, CWriteableMonitorEntity *pNewMonitorEntity)
{
	for (int i=pActionTriggers->size()-1;i>=0;i--) {
		pActionTriggers->at(i)->beforeUpdate(pMonitorEntity,pNewMonitorEntity);
	}
}
	
void CMonitorEntityFactory::afterUpdate(CMonitorEntity *pMonitorEntity)
{
	for (int i=0;i<(int)pActionTriggers->size();i++) {
		pActionTriggers->at(i)->afterUpdate(pMonitorEntity);
	}
}
	
void CMonitorEntityFactory::beforeRemove(CMonitorEntity *pMonitorEntity)
{
	for (int i=pActionTriggers->size()-1;i>=0;i--) {
		pActionTriggers->at(i)->beforeRemove(pMonitorEntity);
	}
}

void CMonitorEntityFactory::commitAdd(CMonitorEntity *pMonitorEntity)
{
	if (!m_activeCommitTrigger) return;
#ifdef COUNT_OPERATION
	addCommitForMonitorEntity++;
#endif
	for (int i=0;i<(int)pCommitTriggers->size();i++) {
		pCommitTriggers->at(i)->commitAdd(pMonitorEntity);
	}
}

void CMonitorEntityFactory::commitUpdate(CMonitorEntity *pMonitorEntity, CWriteableMonitorEntity *pOldMonitorEntity)
{
	if (!m_activeCommitTrigger) return;
#ifdef COUNT_OPERATION
	updateCommitForMonitorEntity++;
#endif
	for (int i=0;i<(int)pCommitTriggers->size();i++) {
		pCommitTriggers->at(i)->commitUpdate(pMonitorEntity,pOldMonitorEntity);
	}
}
	
void CMonitorEntityFactory::commitRemove(CWriteableMonitorEntity *pMonitorEntity)
{
	if (!m_activeCommitTrigger) return;
#ifdef COUNT_OPERATION
	removeCommitForMonitorEntity++;
#endif
	for (int i=0;i<(int)pCommitTriggers->size();i++) {
		pCommitTriggers->at(i)->commitRemove(pMonitorEntity);
	}
}

void CMonitorEntityFactory::activeCommitTrigger(bool activation)
{
	m_activeCommitTrigger=activation;
}

extern int compareForKeyIndexinEventEntity(const void *pV1, const void *pV2);
extern int compareForKeyObjectinEventEntity(const void *pV1, const void *pV2);
#ifdef COUNT_OPERATION
int addActionForEventEntity=0;
int updateWithIndexActionForEventEntity=0;
int updateWithoutIndexActionForEventEntity=0;
int removeActionForEventEntity=0;
int addCommitForEventEntity=0;
int updateCommitForEventEntity=0;
int removeCommitForEventEntity=0;
#endif
void CEventEntityFactory::init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly)
{
	if (runLevel>=0) {
		if(!reuse) {
			pKeyIndex=new CAVLTree(maxUnit,compareForKeyIndexinEventEntity,pAllocator,reuse,reuseID,readOnly);
			if(pIndexMap != NULL)
				pIndexMap->insert(map<string,int>::value_type("EventEntity_KeyIndex",pKeyIndex->getReuseID()));
		}
		else {
			map<string,int>::iterator it = pIndexMap->find("EventEntity_KeyIndex");
			if(it != pIndexMap->end()) {
				pKeyIndex=new CAVLTree(maxUnit,compareForKeyIndexinEventEntity,pAllocator,reuse,it->second,readOnly);
			}
		}
		if (pKeyIndex==NULL)
			RAISE_RUNTIME_ERROR("Insufficient memory space");
	}
	if (runLevel>=0) {
		if(!reuse) {
			pKeyObject=new CAVLTree(maxUnit,compareForKeyObjectinEventEntity,pAllocator,reuse,reuseID,readOnly);
			if(pIndexMap != NULL)
				pIndexMap->insert(map<string,int>::value_type("EventEntity_KeyObject",pKeyObject->getReuseID()));
		}
		else {
			map<string,int>::iterator it = pIndexMap->find("EventEntity_KeyObject");
			if(it != pIndexMap->end()) {
				pKeyObject=new CAVLTree(maxUnit,compareForKeyObjectinEventEntity,pAllocator,reuse,it->second,readOnly);
			}
		}
		if (pKeyObject==NULL)
			RAISE_RUNTIME_ERROR("Insufficient memory space");
	}
	pLastFoundInSearchByKey=NULL;
	pLastFoundInSearchByObject=NULL;
	pActionTriggers=new vector<CEventEntityActionTrigger *>;
	pCommitTriggers=new vector<CEventEntityCommitTrigger *>;
	m_activeCommitTrigger=true;
}

CEventEntityFactory::CEventEntityFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly) :
	CDatabaseDataFactory(sizeof(CEventEntity),maxUnit,pAllocator,reuse,reuseID, readOnly)
{
	m_pConfig=NULL;
	init(maxUnit,pAllocator,pIndexMap,reuse,reuseID,readOnly);
}

CEventEntityFactory::CEventEntityFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly) :
	CDatabaseDataFactory(sizeof(CEventEntity),MDB_DEFAULT_BLOCK_SIZE,pAllocator,reuse,reuseID,readOnly)
{
	m_pConfig=pConfig;
	init(MDB_DEFAULT_BLOCK_SIZE,pAllocator,pIndexMap,reuse,reuseID,readOnly);		
}

CEventEntityFactory::~CEventEntityFactory(void)
{
	if (runLevel>=0) {
		if (pKeyIndex!=NULL)
			delete pKeyIndex;
	}
	if (runLevel>=0) {
		if (pKeyObject!=NULL)
			delete pKeyObject;
	}
	if (pActionTriggers!=NULL)
		delete pActionTriggers;
	if (pCommitTriggers!=NULL)
		delete pCommitTriggers;
}

void CEventEntityFactory::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CEventEntityFactory");
	CDatabaseDataFactory::output(pLogger,indent+1);
	if (runLevel>=0) {
		pKeyIndex->output(pLogger,indent+1);
	}
	if (runLevel>=0) {
		pKeyObject->output(pLogger,indent+1);
	}
}

int CEventEntityFactory::readCSV(char *filename)
{
	FILE *input;
	CWriteableEventEntity thisEventEntity;
	char buffer[1025];
	vector<char *> *pNames;
	char *token;
	input=mfopen(filename,"rt");
	if (input==NULL)
		return 0;
	pNames=new vector<char *>;
	fgets(buffer,1024,input);
	token=getNextToken(buffer);
	while (token!=NULL) {
		pNames->push_back(token);
		token=getNextToken(NULL);
	}
	while (thisEventEntity.readCSV(input,pNames))
		add(&thisEventEntity);
	fclose(input);
	delete pNames;
	return 1;
}

int CEventEntityFactory::readCSV(CConfig *pConfig)
{
	char szFileName[300];
	strcpy(szFileName, pConfig->getConfig("CSVReadPath"));
	strcat(szFileName, "EventEntity.csv");
	return readCSV(szFileName);
}

int CEventEntityFactory::writeCSV(char *filename)
{
	FILE *output;
	CWriteableEventEntity *pEventEntity;
	output=mfopen(filename,"wt");
	if (output==NULL)
		return 0;
	CWriteableEventEntity::writeCSVHead(output);
	pEventEntity=(CWriteableEventEntity *)(pMem->getFirst());
	while (pEventEntity!=NULL) {
		if (!pEventEntity->writeCSV(output)) {
			pMem->endGet();
			fclose(output);
			return 0;
		}
		pEventEntity=(CWriteableEventEntity *)(pMem->getNext());
	}
	pMem->endGet();
	fclose(output);
	return 1;
}

int CEventEntityFactory::writeCSV(CConfig *pConfig)
{
	char szFileName[300];
	strcpy(szFileName, pConfig->getConfig("CSVWritePath"));
	strcat(szFileName, "EventEntity.csv");
	return writeCSV(szFileName);
}

void CEventEntityFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename,"w+b");
	dump(fp);
	if (fp!=NULL) fclose(fp);
}	

void CEventEntityFactory::dump(FILE *fp)
{
	int index=0; ///下标
	CWriteableEventEntity *pEventEntity;
	if(fp==NULL) fp=stdout;
	pMem->dump(fp);
	fprintf(fp,"CEventEntityFactory={       Total Count=%d\n", pMem->getCount());
	pEventEntity=(CWriteableEventEntity *)(pMem->getFirst());
	while (pEventEntity!=NULL) {
		pEventEntity->dump(fp,index++);
		pEventEntity=(CWriteableEventEntity *)(pMem->getNext());
	}
	fprintf(fp,"}\n");
	pMem->endGet();
}

void CEventEntityFactory::clearAll(void)
{
	CDatabaseDataFactory::clearAll();
	if (runLevel>=0) {
		pKeyIndex->removeAll();
	}
	if (runLevel>=0) {
		pKeyObject->removeAll();
	}
}

CEventEntity *CEventEntityFactory::internalAdd(CWriteableEventEntity *pEventEntity, bool bNoTransaction)
{	
#ifdef COUNT_OPERATION
	addActionForEventEntity++;
#endif
	CEventEntity *pTarget;	
	beforeAdd(pEventEntity);
	pTarget=(CEventEntity *)createObject();
	if (pTarget==NULL) {
		RAISE_DESIGN_ERROR("Can not alloc enough EventEntity in memory database");
		return NULL;
	}
	forceCopy(pTarget, pEventEntity, sizeof(CEventEntity));
	pMem->updateObject(pTarget);
	if (runLevel>=0) {
		pKeyIndex->addObject(pTarget);
	}
	if (runLevel>=0) {
		pKeyObject->addObject(pTarget);
	}
	afterAdd(pTarget);
	if (bNoTransaction) {
		commitAdd(pTarget);
	}
	return pTarget;
}

CEventEntity *CEventEntityFactory::add(CWriteableEventEntity *pEventEntity, CTransaction *pTransaction)
{
	pEventEntity->calAllHash();
	if (pTransaction==NULL) {
		return internalAdd(pEventEntity,true);
	}
	else {
		CEventEntity *pNewEventEntity;
		pNewEventEntity = internalAdd(pEventEntity,false);
		pTransaction->addResource(CEventEntityResource::alloc(CREATE_ACTION,this,pNewEventEntity,NULL));
		return pNewEventEntity;
	}
}

void CEventEntityFactory::internalUpdate(CEventEntity *pEventEntity, CWriteableEventEntity *pNewEventEntity, bool updateIndex,bool bNoTransaction)
{
#ifdef COUNT_OPERATION
	if (updateIndex) {
		updateWithIndexActionForEventEntity++;
	}
	else {
		updateWithoutIndexActionForEventEntity++;
	}
#endif
	CWriteableEventEntity theOldEventEntity;
	beforeUpdate(pEventEntity,pNewEventEntity);
	if (bNoTransaction) {
		forceCopy(&theOldEventEntity,pEventEntity,sizeof(CEventEntity));
	}
	CAVLNode *pKeyIndexNode=NULL;
	CAVLNode *pKeyObjectNode=NULL;
	if (updateIndex) {
		if (runLevel>=0) {
			pKeyIndexNode=pKeyIndex->findObject(pEventEntity);
		}
		if (runLevel>=0) {
			pKeyObjectNode=pKeyObject->findObject(pEventEntity);
		}
	}

	forceCopy(pEventEntity,pNewEventEntity,sizeof(CEventEntity));
	pMem->updateObject(pEventEntity);
	if (updateIndex) {
		if (runLevel>=0) {
			pKeyIndex->updateNode(pKeyIndexNode);
		}
		if (runLevel>=0) {
			pKeyObject->updateNode(pKeyObjectNode);
		}
	}
	afterUpdate(pEventEntity);
	if (bNoTransaction) {
		commitUpdate(pEventEntity,&theOldEventEntity);
	}
}

void CEventEntityFactory::update(CEventEntity *pEventEntity, CWriteableEventEntity *pNewEventEntity, CTransaction *pTransaction, bool updateIndex)
{
	pNewEventEntity->updateAllHash();
	if (pTransaction==NULL) {
		internalUpdate(pEventEntity,pNewEventEntity,updateIndex,true);
	}
	else {
		pTransaction->addResource(CEventEntityResource::alloc(UPDATE_ACTION,this,pEventEntity,pNewEventEntity,updateIndex));
		internalUpdate(pEventEntity,pNewEventEntity,updateIndex,false);
	}
}

void CEventEntityFactory::internalRemove(CEventEntity *pEventEntity, bool bNoTransaction)
{
#ifdef COUNT_OPERATION
	removeActionForEventEntity++;
#endif
	CWriteableEventEntity theOldEventEntity;
	beforeRemove(pEventEntity);
	if (bNoTransaction) {
		forceCopy(&theOldEventEntity,pEventEntity,sizeof(CEventEntity));
	}
	if (runLevel>=0) {
		pKeyIndex->removeObject(pEventEntity);
	}
	if (runLevel>=0) {
		pKeyObject->removeObject(pEventEntity);
	}
	pMem->free(pEventEntity);
	if(bNoTransaction) {
		commitRemove(&theOldEventEntity);
	}
}

void CEventEntityFactory::remove(CEventEntity *pEventEntity, CTransaction *pTransaction)
{
	if (pTransaction==NULL) {
		internalRemove(pEventEntity,true);
	}
	else {
		pTransaction->addResource(CEventEntityResource::alloc(DELETE_ACTION,this,pEventEntity,NULL));
		internalRemove(pEventEntity,false);		
	}
}

CEventEntity* CEventEntityFactory::addOrUpdate(CEventEntity *pEventEntity, CWriteableEventEntity *pNewEventEntity, CTransaction *pTransaction, bool updateIndex)
{
	if(pEventEntity == NULL) {
		return add(pNewEventEntity,pTransaction);
	}
	else {
		update(pEventEntity,pNewEventEntity,pTransaction,updateIndex);
		return pEventEntity;
	}
}

void CEventEntityFactory::retrieve(CEventEntity *pEventEntity, CWriteableEventEntity *pTargetEventEntity)
{
	forceCopy(pTargetEventEntity, pEventEntity, sizeof(CEventEntity));
}
	
int CEventEntityFactory::addActionTrigger(CEventEntityActionTrigger *pActionTrigger)
{
	pActionTrigger->setFactory(this);
	pActionTriggers->push_back(pActionTrigger);
	return 1;
}

int CEventEntityFactory::removeActionTrigger(CEventEntityActionTrigger *pActionTrigger)
{
	for (int i=0;i<(int)pActionTriggers->size();i++) {
		if (pActionTriggers->at(i)==pActionTrigger) {
			pActionTriggers->erase(pActionTriggers->begin()+i);
			return 1;
		}
	}
	return 0;
}

int CEventEntityFactory::addCommitTrigger(CEventEntityCommitTrigger *pCommitTrigger)
{
	pCommitTrigger->setFactory(this);
	pCommitTriggers->push_back(pCommitTrigger);
	return 1;
}

int CEventEntityFactory::removeCommitTrigger(CEventEntityCommitTrigger *pCommitTrigger)
{
	for (int i=0;i<(int)pCommitTriggers->size();i++) {
		if (pCommitTriggers->at(i)==pCommitTrigger) {
			pCommitTriggers->erase(pCommitTriggers->begin()+i);
			return 1;
		}
	}
	return 0;
}

CEventEntity *CEventEntityFactory::getFirst(void)
{
	CEventEntity *pResult=(CEventEntity *)(pMem->getFirst());
	return pResult;
}
	
CEventEntity *CEventEntityFactory::getNext(void)
{
	CEventEntity *pResult=(CEventEntity *)(pMem->getNext());
	return pResult;
}
	
void CEventEntityFactory::endGet(void)
{
	pMem->endGet();
}

void CEventEntityFactory::beforeAdd(CWriteableEventEntity *pEventEntity)
{
	for (int i=pActionTriggers->size()-1;i>=0;i--) {
		pActionTriggers->at(i)->beforeAdd(pEventEntity);
	}
}
	
void CEventEntityFactory::afterAdd(CEventEntity *pEventEntity)
{
	for (int i=0;i<(int)pActionTriggers->size();i++) {
		pActionTriggers->at(i)->afterAdd(pEventEntity);
	}
}

void CEventEntityFactory::beforeUpdate(CEventEntity *pEventEntity, CWriteableEventEntity *pNewEventEntity)
{
	for (int i=pActionTriggers->size()-1;i>=0;i--) {
		pActionTriggers->at(i)->beforeUpdate(pEventEntity,pNewEventEntity);
	}
}
	
void CEventEntityFactory::afterUpdate(CEventEntity *pEventEntity)
{
	for (int i=0;i<(int)pActionTriggers->size();i++) {
		pActionTriggers->at(i)->afterUpdate(pEventEntity);
	}
}
	
void CEventEntityFactory::beforeRemove(CEventEntity *pEventEntity)
{
	for (int i=pActionTriggers->size()-1;i>=0;i--) {
		pActionTriggers->at(i)->beforeRemove(pEventEntity);
	}
}

void CEventEntityFactory::commitAdd(CEventEntity *pEventEntity)
{
	if (!m_activeCommitTrigger) return;
#ifdef COUNT_OPERATION
	addCommitForEventEntity++;
#endif
	for (int i=0;i<(int)pCommitTriggers->size();i++) {
		pCommitTriggers->at(i)->commitAdd(pEventEntity);
	}
}

void CEventEntityFactory::commitUpdate(CEventEntity *pEventEntity, CWriteableEventEntity *pOldEventEntity)
{
	if (!m_activeCommitTrigger) return;
#ifdef COUNT_OPERATION
	updateCommitForEventEntity++;
#endif
	for (int i=0;i<(int)pCommitTriggers->size();i++) {
		pCommitTriggers->at(i)->commitUpdate(pEventEntity,pOldEventEntity);
	}
}
	
void CEventEntityFactory::commitRemove(CWriteableEventEntity *pEventEntity)
{
	if (!m_activeCommitTrigger) return;
#ifdef COUNT_OPERATION
	removeCommitForEventEntity++;
#endif
	for (int i=0;i<(int)pCommitTriggers->size();i++) {
		pCommitTriggers->at(i)->commitRemove(pEventEntity);
	}
}

void CEventEntityFactory::activeCommitTrigger(bool activation)
{
	m_activeCommitTrigger=activation;
}


#ifdef COUNT_OPERATION

#define clearCount(name)						\
	addActionFor ## name =0;					\
	updateWithIndexActionFor ## name =0;		\
	updateWithoutIndexActionFor ## name =0;		\
	removeActionFor ## name =0;					\
	addCommitFor ## name=0;						\
	updateCommitFor ## name =0;					\
	removeCommitFor ## name =0;

void initAllOperationCount(void)
{
	clearCount(MonitorEntity);
	clearCount(EventEntity);
}

#define display(id)						\
	if (id!=0)							\
	{									\
		printf("\t" #id ":%d\n", id);	\
	}

#define displayAll(name)							\
	display(addActionFor ## name);					\
	display(updateWithIndexActionFor ## name);		\
	display(updateWithoutIndexActionFor ## name);	\
	display(removeActionFor ## name);				\
	display(addCommitFor ## name);					\
	display(updateCommitFor ## name);				\
	display(removeCommitFor ## name);

void showAllOperationCount(void)
{
	displayAll(MonitorEntity);
	displayAll(EventEntity);
}
#endif

