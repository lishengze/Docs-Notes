// Index.h: interface for the CIndex class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INDEX_H__4366595F_1D6D_49A5_9BEF_AB1FAD9EC14C__INCLUDED_)
#define AFX_INDEX_H__4366595F_1D6D_49A5_9BEF_AB1FAD9EC14C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//TCompareFunc��һ���ȽϺ���ָ������
typedef int (* TCompareFunc)(void *,void *);

//**********************************************************************
//CIndexNode��һ��ƽ�����ڵ����
//@����	���ض�
//@�汾	1.0,20020214
//**********************************************************************
class CIndexNode
{
public:
	//���汾�ڵ��а����Ķ���
	void *pObject;
	//���汾�ڵ�ĸ��ڵ㡢����ӽڵ���Ҷ��ӽڵ�
	CIndexNode *father, *left, *right;
	//ƽ��״��
	int depth;
};

//**********************************************************************
//CIndex��һ�������������������Ƕ�ĳ�����͵����ݽṹ���Լ����ϵ�һ�ֱȽϺ�����
//���ɵ�ƽ������
//@����	���ض�
//@�汾	1.0,20020214
//**********************************************************************
class CIndex
{
public:
	//���캯��������ռ䣬����һ�ÿյ�ƽ����
	//@����	compareFunc	�ȽϺ���ָ��
	CIndex(TCompareFunc compareFunc);
	
	//���������������ͷſռ�
	virtual ~CIndex(void);
	
	//�ڱ�ƽ�����м���һ���µĶ���ڵ�
	//@����	pObject	�µĶ�����׵�ַ
	//@����	������������˶���Ľڵ�
	CIndexNode *addObject(void *pObject);
	
	//��ȡ��С��һ���ڵ�
	//@����	��С��һ���ڵ㣬�����û�нڵ㣬�򷵻�NULL
	CIndexNode *getSmallest(void);
	
	//��ȡ����һ���ڵ�
	//@����	����һ���ڵ㣬�����û�нڵ㣬�򷵻�NULL
	CIndexNode *getLargest(void);

	//Ѱ�ҵ�һ�����ڵ��ڴ˶���Ľڵ�
	//@���� pObject	�Ƚ�ʱ�õĶ���
	//@����	��һ�����ڵ��ڴ˶���Ľڵ㣬��������ڴ˽ڵ㣬�򷵻�NULL
	CIndexNode *searchFirstGreatEqual(void *pObject);
	
	//Ѱ�ҵ�һ�����ڴ˶���Ľڵ�
	//@���� pObject	�Ƚ�ʱ�õĶ���
	//@����	��һ�����ڴ˶���Ľڵ㣬��������ڴ˽ڵ㣬�򷵻�NULL
	CIndexNode *searchFirstGreat(void *pObject);
	
	//Ѱ�����һ��С�ڵ��ڴ˶���Ľڵ�
	//@���� pObject	�Ƚ�ʱ�õĶ���
	//@����	���һ��С�ڵ��ڴ˶���Ľڵ㣬��������ڴ˽ڵ㣬�򷵻�NULL
	CIndexNode *searchLastLessEqual(void *pObject);
	
	//Ѱ�����һ��С�ڴ˶���Ľڵ�
	//@���� pObject	�Ƚ�ʱ�õĶ���
	//@����	���һ��С�ڴ˶���Ľڵ㣬��������ڴ˽ڵ㣬�򷵻�NULL
	CIndexNode *searchLastLess(void *pObject);
	
	//Ѱ�ҵ�һ�����ڴ˶���Ľڵ�
	//@���� pObject	�Ƚ�ʱ�õĶ���
	//@����	��һ�����ڴ˶���Ľڵ㣬��������ڴ˽ڵ㣬�򷵻�NULL
	CIndexNode *searchFirstEqual(void *pObject);
	
	//Ѱ�����һ�����ڴ˶���Ľڵ�
	//@���� pObject	�Ƚ�ʱ�õĶ���
	//@����	���һ�����ڴ˶���Ľڵ㣬��������ڴ˽ڵ㣬�򷵻�NULL
	CIndexNode *searchLastEqual(void *pObject);
	
	//Ѱ����һ���ڵ㣬�����ڴ˽ڵ�ĵ�һ���ڵ�
	//@���� pNode	Ŀǰ�ڵ�
	//@����	���ڴ˽ڵ�ĵ�һ���ڵ㣬��������ڴ˽ڵ㣬�򷵻�NULL
	CIndexNode *getNextNode(CIndexNode *pNode);
	
	//Ѱ��ǰһ���ڵ㣬��С�ڴ˽ڵ�����һ���ڵ�
	//@���� pNode	Ŀǰ�ڵ�
	//@����	С�ڴ˽ڵ�����һ���ڵ㣬��������ڴ˽ڵ㣬�򷵻�NULL
	CIndexNode *getPrevNode(CIndexNode *pNode);

	void removeNode(CIndexNode *pNode);

	void clear();
private:
	//�洢ƽ������CQueue
	deque<CIndexNode> m_Queue;
	
	//�洢�ȽϺ���ָ��
	TCompareFunc m_CompareFunc;
	
	//��������ƽ��ṹ����ָ���ڵ㿪ʼ���ϵ���
	//@����	thisNode	��ʼ�����Ľڵ�
	void alterTree(CIndexNode *thisNode);
	
	//���ñ�ƽ�����ĸ�
	//@����	pNode	Ҫ����Ϊ���Ľڵ�
	void setRoot(CIndexNode *pNode)
	{
		m_pRoot = pNode;
	}
	
	//��ȡ��ƽ�����ĸ�
	//@����	��ǰ�ĸ��ڵ�
	CIndexNode *getRoot(void)
	{
		return m_pRoot;
	}

	CIndexNode *m_pRoot;
};

#endif // !defined(AFX_INDEX_H__4366595F_1D6D_49A5_9BEF_AB1FAD9EC14C__INCLUDED_)
