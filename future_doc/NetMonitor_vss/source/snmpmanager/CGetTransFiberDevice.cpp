/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	CGetTransFiberDevice.cpp
///@brief	实现了CGetTransFiberDevice使用的类
///@history
///20130318	LSC		创建该文件

#include "CGetTransFiberDevice.h"
#include "CSynConnector.h"

#ifdef LINUX
#include <sys/socket.h>
#include <dirent.h>
#endif

map<string, CTransFibertConfig> g_mapTransFiberConfig;

extern CTaskInfoManager g_TaskInfoManager;
extern char g_mCommunity[100];

/**虚函数，子类可做一些实例化工作
* @return true:创建成功 false:创建失败
*/
bool CGetTransFiberDevice::InitInstance(void)
{
	return true;
}

/**虚函数，子类清楚实例
*/
void CGetTransFiberDevice::ExitInstance(void)
{
}

/**线程开始运行，纯虚函数，子类必须继承实现
*/
void CGetTransFiberDevice::Run(void)
{

	while (1)
	{
		CTransFiberTaskInfo task;
		while( task_list.get(task) )
		{
			//DoTask(task);
			DoTaskNew(task);
		}
		SLEEP(2 * 1000);
	}
}

int CGetTransFiberDevice::DoTaskNew(CTransFiberTaskInfo task)
{
	int ret_flag = 0;
	char curdate[10];
	char curtime[10];
	time_t	timep;
	time(&timep);

	struct tm tm_time;
	LocalTime(&timep, &tm_time);
	strftime(curtime, 10, "%H:%M:%S", &tm_time);
	strftime(curdate, 10, "%Y%m%d", &tm_time);

	CFTDRtnNetMonitorTaskResultField field;

	field.ObjectID = task.ObjectID.c_str();
	field.Task_ID = task.TaskID;
	field.OperateTime = task.RunTimes;
	field.InstructChain = task.AttrName.c_str();
	field.MonDate = curdate;
	field.MonTime = curtime;


	//notify client
	field.Flag = TASK_DOING_EXEC;
	g_TaskInfoManager.AddTaskResult(field, "");

	//modify task status
	g_TaskInfoManager.UpdateTaskStatus(
		task.TaskID,
		task.ObjectID,
		task.AttrName,
		TASK_DOING_EXEC,
		TASK_TYPE_SNMP);

	printf("+++ TransFiberTask Init: Task%02d[%04d] [%s %s]\n\t%s %s %s\n",
		task.TaskID,
		task.RunTimes,
		task.TaskDate.c_str(),
		task.TaskTime.c_str(),
		task.IPAddress.c_str(),
		task.AttrName.c_str(),
		task.Oid_value.c_str());

	string range="";
	string result;//记录任务结果 形如：arrtname*range**locate:name*value*flag,name*value*flag;......
	//附加功率类型标识，骨干功率，客户侧功率

	if( g_mapTransFiberConfig.find(task.IPAddress) != g_mapTransFiberConfig.end() )
	{
		//附加功率类别（）
		result = task.AttrName; 
		result.append("*");
		int type;
		if( strcasecmp(task.AttrName.c_str(),"cMsDwdmIfTransportPower")==0 )
		{
			type = POWER_TYPE_MASTER;
			range = g_mapTransFiberConfig[task.IPAddress].rang_m.c_str();
		}
		else if( strcasecmp(task.AttrName.c_str(),"cOpticalParameterValue")==0 )
		{
			type = POWER_TYPE_SLAVE;
			range = g_mapTransFiberConfig[task.IPAddress].rang_s.c_str();
		}
		else if(strcasecmp(task.AttrName.c_str(),"ifInErrors")==0 )
		{
			//端口接收错包数类型
			type = -1;
		}
		//附加阀值,如果有
		if( range.length()>0 )
		{
			result.append(range.c_str());
			result.append("*");
		}

		vector<list<Power_Value> > datas;
		if( task.DevManuID == 1 ) //cisco
		{
#ifdef TEST_TRANS  // for test
			for(int itime=1;itime<3;itime++)
			{
				list<Power_Value> dpv;
				for(int i_gen = 0; i_gen < 6; i_gen++ )
				{
					Power_Value pv;
					char tmp[24] = "\0";
					sprintf(tmp,"%s%d","Giber",itime*i_gen);
					pv.p_name = tmp;
					memset(tmp, 0, 24 );
					sprintf(tmp,"%d",2*itime*i_gen);
					pv.p_value.first = tmp;
					pv.p_value.second = (i_gen%2)?1:0;
					dpv.push_back(pv);
				}
				datas.push_back(dpv);
			}
#else
			if( snmp_map.find( task.IPAddress ) == snmp_map.end())
			{
				CSnmpWrapper wrap( task.Community,task.IPAddress );
				snmp_map[task.IPAddress] = wrap;
			}

			if( type == POWER_TYPE_MASTER )
			{
				ProcessCiscoDeviceTPPower(&(snmp_map[task.IPAddress]), datas);
			}
			else if( type == POWER_TYPE_SLAVE )
			{
				ProcessCiscoDeviceOPPower(&(snmp_map[task.IPAddress]), datas);
			}
			else if ( type== -1 )
			{
				ProcessCiscoDeviceIfInErrors(&(snmp_map[task.IPAddress]),datas);
			}
#endif
		}
		else if ( task.DevManuID == 5 ) //huawei
		{
			ProcessHuaweiDevicePower(task.IPAddress, type, datas);
			//获取文件的时间信息 “OpticalPower_2013-03-26_15-50-43.csv” add by Lee 20130621
			size_t index_b = m_csv_filename.find_first_of("_");
			size_t index_e = m_csv_filename.find_first_of(".");
			if( index_b != string::npos && index_e != string::npos )
			{
				string timestr = m_csv_filename.substr(index_b+1, index_e-index_b-1);
				size_t index = timestr.find("_");
				string runtime = timestr.substr(0, index).c_str();
				for( string::iterator it_char = runtime.begin();it_char != runtime.end(); )
				{
					if(*it_char == '-')
					{
						runtime.erase(it_char);
					}
					else
					{
						it_char++;
					}
				}
				field.MonDate = runtime.c_str();

				char *p = NULL;
				runtime = timestr.substr(index + 1, timestr.length()-index).c_str(); 
				while ((p = strchr((char *)runtime.c_str(), '-')) != NULL)
				{
					*p = ':';
				}
				field.MonTime = runtime.c_str();
			}
			
		}

		if( datas.size()>0 )
		{
			for( int i = 0; i< datas.size(); i++ )
			{
				if( datas[i].size()==0 ) //过滤掉空数据
				{
					continue;
				}
				if( i>0 )
				{
					result.append(";");  //每组值（map）之间的分割符号
				}
				//附加location信息
				result.append( g_mapTransFiberConfig[ task.IPAddress ].locate.c_str() );
				if( datas.size() > 1 ) 	//TP_POWER datas.size()==1,  OP_POWER and IFSINERROR datas.size()==2
				{
					char data[10]="\0";
					list<string> numb_list = g_mapTransFiberConfig[ task.IPAddress ].in_Number[i+1];
					if(numb_list.size()>0)
					{
						int number = atoi(numb_list.begin()->c_str());
						sprintf(data,"%d", number);
					}
					result.append( data );
				}	
				result.append(":");
				string keyvalue="";
				FormatedataAccordingPro( datas[i], keyvalue );
				result.append( keyvalue.c_str() );
			}
		}
	}
	field.Flag = TASK_SUCCESS;
	g_TaskInfoManager.AddTaskResult(field,  result);

	//notify client
	field.Flag = TASK_DONE_EXEC;
	g_TaskInfoManager.AddTaskResult(field, "");

	//modify task status
	g_TaskInfoManager.UpdateTaskStatus(
		task.TaskID,
		task.ObjectID,
		task.AttrName,
		TASK_DONE_EXEC,
		TASK_TYPE_SNMP);

	return ret_flag;

}

int CGetTransFiberDevice::DoTask(CTransFiberTaskInfo task)
{
	int ret_flag = 0;
	char curdate[10];
	char curtime[10];
	time_t	timep;
	time(&timep);

	struct tm tm_time;
	LocalTime(&timep, &tm_time);
	strftime(curtime, 10, "%H:%M:%S", &tm_time);
	strftime(curdate, 10, "%Y%m%d", &tm_time);

	CFTDRtnNetMonitorTaskResultField field;

	field.ObjectID = task.ObjectID.c_str();
	field.Task_ID = task.TaskID;
	field.OperateTime = task.RunTimes;
	field.InstructChain = task.AttrName.c_str();
	field.MonDate = curdate;
	field.MonTime = curtime;

	//notify client
	field.Flag = TASK_DOING_EXEC;
	g_TaskInfoManager.AddTaskResult(field, "");

	//modify task status
	g_TaskInfoManager.UpdateTaskStatus(
		task.TaskID,
		task.ObjectID,
		task.AttrName,
		TASK_DOING_EXEC,
		TASK_TYPE_SNMP);

	printf("+++ TransFiberTask Init: Task%02d[%04d] [%s %s]\n\t%s %s %s\n",
		task.TaskID,
		task.RunTimes,
		task.TaskDate.c_str(),
		task.TaskTime.c_str(),
		task.IPAddress.c_str(),
		task.AttrName.c_str(),
		task.Oid_value.c_str());


	list<string> in_list;
	list<string>::iterator it_index;

	int index = -1; //合法取值 cMsDwdmIfTransportPower = 0; cOpticalParameterValue=1
	int loop = 0;   //记录循环次数
	string range;

	string result;//记录任务结果 形如：arrtname*range**locat:name*value*flag,name*value*flag;......
	//附加功率类型标识，骨干功率，客户侧功率

	if( g_mapTransFiberConfig.find(task.IPAddress) != g_mapTransFiberConfig.end() )
	{
		//附加功率类别（）
		result = task.AttrName; 
		result.append("*");
		if( strcasecmp(task.AttrName.c_str(),"cMsDwdmIfTransportPower")==0 )
		{
			index = 0;
			range = g_mapTransFiberConfig[task.IPAddress].rang_m.c_str();
		}
		else if( strcasecmp(task.AttrName.c_str(),"cOpticalParameterValue")==0 )
		{
			index = 1;
			range = g_mapTransFiberConfig[task.IPAddress].rang_s.c_str();
		}
		loop = 2*index;		
		//附加阀值
		result.append(range.c_str());
		result.append("*");

		if( task.DevManuID == 1 ) //cisco
		{
			map<string, CSnmpWrapper>::iterator it = snmp_map.find( task.IPAddress );
			if( it == snmp_map.end())
			{
				CSnmpWrapper wrap( task.Community,task.IPAddress );
				snmp_map[task.IPAddress] = wrap;
			}
			if ((!it->second.is_opened())
				&&	(!it->second.open_session()))
			{
				ret_flag = -1;
			}

			CDPWALK_RESULT	datamap;
			if ( ret_flag == 0 )
			{
				if( SNMP_ERROR_SUCCESS != it->second.send_sync_walk_request(task.Oid_value.c_str(),
					datamap))
				{
					printf("send oid [%s] with device IP [%s] fail.\n",task.Oid_value.c_str(),task.IPAddress.c_str());
				}
				it->second.close_session(); //取完数据之后关闭snmp-session
			}

			for(; index<=loop; index++ )
			{	//附加位置信息		
				result.append( g_mapTransFiberConfig[ task.IPAddress ].locate.c_str() );
				if( index >0 )
				{
					char data[10]="\0";
					sprintf(data,"%d", index);
					result.append( data );
				}		
				result.append(":");

				in_list = g_mapTransFiberConfig[ task.IPAddress ].in_list[index];
				for(it_index = in_list.begin(); it_index != in_list.end(); it_index++)
				{
					if( it_index != in_list.begin() )
					{
						result.append(",");
					}
					result.append( it_index->c_str() );
					result.append("*");

					char key_buff[512] = "\0";
					if( index = 0 )
					{
						sprintf( key_buff,"%s.%s", task.Oid_value.c_str(), it_index->c_str());		
					}
					else if( index>0 )
					{
						sprintf( key_buff,"%s.%s.%s", task.Oid_value.c_str(), it_index->c_str(),"1.1");
					}
					if( datamap.find( key_buff ) != datamap.end() )
					{
						double  value = atof(datamap[ key_buff ].c_str());
						value = value/10;
						char databuff[16] = "\0";
						sprintf(databuff,"%.2f",value);
						result.append( databuff );
						if( CheckRange(range, databuff) )
						{
							result.append("*1");
						}
						else
						{
							result.append("*0");
						}
					}			
				} // end in_list.end()
			} //end loop			
		}
		else if ( task.DevManuID == 5 ) //huawei
		{
			for(; index<=loop; index++ )
			{			
				result.append( g_mapTransFiberConfig[ task.IPAddress ].locate.c_str() );
				if( index >0 )
				{
					char data[10]="\0";
					sprintf(data,"%d", index);
					result.append( data );
				}		
				result.append(":");

				if( GetLastCSVFileName(m_csv_filename) )
				{
					GetCSVLine(m_csv_data,m_csv_filename.c_str());
				}

				in_list = g_mapTransFiberConfig[ task.IPAddress ].in_list[index];
				for(it_index = in_list.begin(); it_index != in_list.end(); it_index++)
				{
					if( it_index != in_list.begin() )
					{
						result.append(",");
					}					
					int row = atoi(it_index->c_str()) - 9;
					string power_key;
					string power_data;
					GetCSVData( row, 4, 5, power_key,power_data );

					result.append( power_key.c_str() );
					result.append("*");
					result.append(power_data.c_str() );
					if( CheckRange(range,power_data) )
					{
						result.append("*1");
					}
					else
					{
						result.append("*0");
					}

				} // end in_list.end()
			} //end loop				
		}
	}
	field.Flag = TASK_SUCCESS;
	g_TaskInfoManager.AddTaskResult(field,  result);

	//notify client
	field.Flag = TASK_DONE_EXEC;
	g_TaskInfoManager.AddTaskResult(field, "");

	//modify task status
	g_TaskInfoManager.UpdateTaskStatus(
		task.TaskID,
		task.ObjectID,
		task.AttrName,
		TASK_DONE_EXEC,
		TASK_TYPE_SNMP);

	return ret_flag;
}
void CGetTransFiberDevice::GetCSVData( int row, int key_col, int value_col, 
									  string& key_data, string& value_data )
{
	if( m_csv_data.size()>= row )
	{
		string row_data = m_csv_data[row-1];
		string::iterator it = row_data.begin();
		int count=0;
		int index1=0,index2=0,index3=0,index4=0;
		for(;it!=row_data.end();it++ )
		{
			if(*it==',')
				count++;
			if( count==key_col-1 && index1==0)
			{
				index1=it-row_data.begin();
			}
			else if ( count==key_col && index2==0 )
			{
				index2=it-row_data.begin();
			}
			
			if ( count==value_col-1 && index3==0 )
			{
				index3 = it-row_data.begin();
			}
			else if( count==value_col && index4==0  )
			{
				index4 = it-row_data.begin();
			}
			if( count>MAX(key_col,value_col) )
				break;
		}
		key_data = row_data.substr(index1+1,index2-index1-1);
		value_data = row_data.substr(index3+1,index4-index3-1);;
	}
	else
	{
		printf("error: row=[%d] override csv_data size=[%d].\n",row, m_csv_data.size());
		key_data="";
		value_data="";
	}

}
void CGetTransFiberDevice::GetCSVLine(vector<string> &csv_data,const char *filename)
{
	assert( filename != NULL );

	char full_filename[256] = "\0";
	sprintf(full_filename, "%s%s",CSV_DIR,filename);

	FILE *fp;
	if( (fp = fopen(full_filename,"r") ) == NULL )
	{
		printf("open csv file %s failed.\n", full_filename);
		return;
	}

	char *ret_stat = NULL;
	char buff[1024] = "\0";
	string data_tmp = "";

	ret_stat = fgets(buff, 1024, fp);

	while( ret_stat != NULL )
	{
		data_tmp.append( buff );
		if( strstr(buff,"\n")!=NULL )
		{
			if( strstr(data_tmp.c_str(), ",") != NULL )			
			{
				csv_data.push_back(data_tmp);
			}
			data_tmp = "";
		}
		memset(buff, 1024, 0);
		ret_stat = fgets(buff, 1024, fp);
	}

	printf("csv file [%s] has [%d] line record.\n",full_filename, csv_data.size());
}

bool CGetTransFiberDevice::GetLastCSVFileName( string &lastFileName)
{
	string old_fileName = lastFileName;

#ifdef WIN32
	WIN32_FIND_DATA FindFileData;
	HANDLE	hFind = INVALID_HANDLE_VALUE;
	char DirSpec[MAX_PATH + 1];						//指定路径
	DWORD dwError;

	strncpy(DirSpec, CSV_DIR, strlen(CSV_DIR) + 1);
	strncat(DirSpec, "\*", 3);

	hFind = FindFirstFile(DirSpec, &FindFileData);

	if (hFind == INVALID_HANDLE_VALUE)
	{
		printf("Invalid file handle. Error is %u ", GetLastError());
		return false;
	}
	else
	{
		//OpticalPower_03-26-2013_15-50-43.csv
		if (FindFileData.dwFileAttributes != FILE_ATTRIBUTE_DIRECTORY)
		{
			CheckCSVFileName(FindFileData.cFileName, lastFileName);
		}

		while (FindNextFile(hFind, &FindFileData) != 0)
		{
			if (FindFileData.dwFileAttributes != FILE_ATTRIBUTE_DIRECTORY)
			{
				CheckCSVFileName(FindFileData.cFileName, lastFileName);
			}
		}

		FindClose(hFind);
	}

#else
	DIR *pDir = opendir(CSV_DIR);
	if (pDir == NULL)
	{
		printf("Failed to open dir %s\n", CSV_DIR);
		return false;
	}

	struct dirent *pstDirent;
	while (pDir != NULL && (pstDirent = readdir(pDir)))
	{
		if ((strcmp(pstDirent->d_name, ".") == 0)
			||	(strcmp(pstDirent->d_name, "..") == 0))
		{
			continue;
		}

		CheckCSVFileName(pstDirent->d_name, lastFileName);
	}

	if (pDir != NULL)
	{
		closedir(pDir);
	}

#endif
	if (strcmp(lastFileName.c_str(),old_fileName.c_str()) != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//OpticalPower_2013-03-26_15-50-43.csv
void CGetTransFiberDevice::CheckCSVFileName(string newName,string &currName)
{
	string s1,s2,s3;
	int index1 = newName.find_first_of("_");
	int index2 = newName.find_first_of(".");
	s1= newName.substr(0,index1);
	s2 = newName.substr(index1+1, index2-index1-1);
	s3 = newName.substr(index2+1,newName.length()-index2);
	if(s1=="OpticalPower"&& s3=="csv"&& strcmp(newName.c_str(),currName.c_str())>0 )
	{
		currName = newName;
	}
}

void CGetTransFiberDevice::AddCTransFiberTaskInfo(
	int TaskID,
	int Times,
	string MonDate,
	string MonTime,
	CFTDSysNetDeviceField DeviceInfo,
	string AttrName,
	int TaskStatus)
{
	CTransFiberTaskInfo task;

	task.TaskID = TaskID;
	task.RunTimes = Times;
	task.TaskDate = MonDate;
	task.TaskTime = MonTime;

	task.ObjectID = DeviceInfo.ObjectID.getValue();
	task.IPAddress = DeviceInfo.IPADDR.getValue();
	task.DevManuID = DeviceInfo.MANUFACTORY_ID.getValue();
	task.Community = DeviceInfo.RCOMMUNITY.getValue();
	if( task.Community.length() == 0 )
	{
		task.Community = g_mCommunity;
	}

	task.AttrName = AttrName;
	if( task.DevManuID != 5 )
	{
		CSynConnector *pSyn = CSynConnector::GetInstancePoint();
		const char *p = pSyn->GetOIDValue( AttrName.c_str(), DeviceInfo.MANUFACTORY_ID );
		if(  p!= NULL )
		{
			task.Oid_value = p;
		}
	}

	task.TaskStatus = TASK_WAIT_EXEC;

	//notify client
	time_t timep;
	CFTDRtnNetMonitorTaskResultField field;
	char curdate[10];
	char curtime[10];

	time(&timep);

	struct tm tm_time;
	LocalTime(&timep, &tm_time);
	strftime(curtime, 10, "%H:%M:%S", &tm_time);
	strftime(curdate, 10, "%Y%m%d", &tm_time);

	field.ObjectID = task.ObjectID.c_str();
	field.Task_ID = task.TaskID;
	field.OperateTime = task.RunTimes;
	field.MonDate = curdate;
	field.MonTime = curtime;
	field.Flag = TASK_WAIT_EXEC;
	g_TaskInfoManager.AddTaskResult(field, "");

	task_list.add( task );
}

void CGetTransFiberDevice::ProcessHuaweiDevicePower(string ipaddress,int type,vector<list<Power_Value> >& datas)
{
	if( g_mapTransFiberConfig.find(ipaddress)==g_mapTransFiberConfig.end() )
	{
		return;
	}
	if( GetLastCSVFileName(m_csv_filename) )
	{
		printf("get the last csv file [%s]\n",m_csv_filename.c_str());
		m_csv_data.clear();
		GetCSVLine(m_csv_data,m_csv_filename.c_str());
	}
	list<string> index_list;
	list<string>::iterator it_index;
	list<string> number_list;
	list<string>::iterator it_number;

	string range;

	if( type == POWER_TYPE_MASTER )
	{
		range = g_mapTransFiberConfig[ipaddress].rang_m;

		index_list = g_mapTransFiberConfig[ ipaddress ].in_list[0];
		number_list = g_mapTransFiberConfig[ ipaddress ].in_Number[0];

		list<Power_Value>  data_list;

		for(it_index = index_list.begin(),it_number = number_list.begin(); 
			it_index != index_list.end(),it_number != number_list.end(); 
			it_index++,it_number++)
		{

			int row = atoi(it_index->c_str()) - CSV_NULL_LINE_NUMBER; //剔除非正常行
			string power_key;
			string power_data;
			GetCSVData( row, 4, 5, power_key,power_data );
			Power_Value pv;
			pv.p_name = *it_number;
			pv.p_value.first = power_data;
			pv.p_value.second = CheckRange(range, pv.p_value.first)?1:0;
			data_list.push_back(pv);
		}
		datas.push_back( data_list );
	}
	else if ( type == POWER_TYPE_SLAVE )
	{
		range = g_mapTransFiberConfig[ipaddress].rang_s;

		for(int i=0; i<2; i++ )
		{
			index_list = g_mapTransFiberConfig[ ipaddress ].in_list[i+1];
			list<Power_Value>  data_list;
			for(it_index = index_list.begin(); it_index != index_list.end(); it_index++)
			{
				int row = atoi(it_index->c_str()) - CSV_NULL_LINE_NUMBER; //剔除非正常行
				string power_key;
				string power_data;
				GetCSVData( row, 4, 5, power_key,power_data );
				Power_Value pv;
				pv.p_name = power_key;
				pv.p_value.first = power_data;
				pv.p_value.second = CheckRange(range, pv.p_value.first)?1:0;
				data_list.push_back(pv);
			}
			datas.push_back( data_list );
		}

	}
}

bool CGetTransFiberDevice::CheckRange(const string& range, const string& a)
{
	if ( a == "/" )
		return true;
	if( a=="-" )
		return false;
	int index = range.find("~");
	if( index != string::npos )
	{
		float f_left = atof( (range.substr(0,index)).c_str() );
		float f_right = atof( (range.substr(index+1,range.length()-index)).c_str() );
		float f_a = atof( a.c_str() );
		//if( MAX(f_a, f_left) == MIN(f_a, f_right) )
		//	return true;
		//else
		//	return false;		
		if(( f_a-f_left>=0) && (f_right-f_a>=0) )
		{
			return true;
		}
		else
		{
			printf("compare result: [%f]-[%f]=[%f] >= 0 is [%s],[%f]-[%f]=[%f] >= 0 is [%s]\n",
				f_a,f_left,f_a-f_left,(f_a-f_left)>=0?"true":"false",f_right,f_a,f_right-f_a,(f_right-f_a)>=0?"true":"false");		
			return false;
		}

	}
	return false;
}

void CGetTransFiberDevice::ProcessCiscoDeviceTPPower(
	CSnmpWrapper *wrap,
	vector<list<Power_Value> >& datas)
{
	assert( wrap != NULL );
	string TP_Oid = "1.3.6.1.4.1.3607.2.40.1.2.1.3";

	if ((!wrap->is_opened())
		&&	(!wrap->open_session()))
	{
		printf("open session fail ip[%s] with community[%s]\n",wrap->get_peer_name().c_str(),wrap->get_community().c_str());
		return;
	}

	CDPWALK_RESULT	datamap;

	if( SNMP_ERROR_SUCCESS != wrap->send_sync_walk_request(TP_Oid.c_str(),
		datamap))
	{
		printf("send oid [%s] with device IP [%s] fail.\n",TP_Oid.c_str(),wrap->get_peer_name().c_str());
		wrap->close_session();
		return;
	}
	wrap->close_session(); //取完数据之后关闭snmp-session

	list<string> index_list;
	list<string>::iterator it_index;
	list<string>    number_list;
	list<string>::iterator  it_number;
	string range;

	index_list = g_mapTransFiberConfig[ wrap->get_peer_name() ].in_list[0];
	number_list = g_mapTransFiberConfig[ wrap->get_peer_name() ].in_Number[0];
	range = g_mapTransFiberConfig[ wrap->get_peer_name() ].rang_m;

	list<Power_Value> data_list;

	for(it_index = index_list.begin(),it_number = number_list.begin(); 
		it_index != index_list.end(),it_number != number_list.end();
		it_index++,it_number++)
	{
		char key_buff[512] = "\0";
		sprintf( key_buff,"%s.%s", TP_Oid.c_str(), it_index->c_str());		
		if( datamap.find( key_buff ) != datamap.end() )
		{
			float  value = atof(datamap[ key_buff ].c_str());
			value = value/10;
			char databuff[16] = "\0";
			sprintf(databuff,"%.2f",value);
			Power_Value pv;
			pv.p_name = *it_number;
			pv.p_value.first = databuff;
			pv.p_value.second = CheckRange(range, pv.p_value.first)?1:0;
			data_list.push_back(pv);
		}			
	}
	datas.push_back( data_list );
}

void CGetTransFiberDevice::ProcessCiscoDeviceOPPower(
	CSnmpWrapper *wrap,
	vector<list<Power_Value> >& datas)
{
	assert( wrap != NULL );
	string OP_Oid = "1.3.6.1.4.1.3607.2.30.1.1.1.3";
	string alias_Oid = "1.3.6.1.2.1.31.1.1.1.18";


	if ((!wrap->is_opened())
		&&	(!wrap->open_session()))
	{
		printf("open session fail ip[%s] with community[%s]\n",wrap->get_peer_name().c_str(),wrap->get_community().c_str());
		return;
	}

	CDPWALK_RESULT	datamap_op;
	if( SNMP_ERROR_SUCCESS != wrap->send_sync_walk_request(OP_Oid.c_str(),
		datamap_op)
		)
	{
		printf("send oid [%s] with device IP [%s] fail.\n",OP_Oid.c_str(),wrap->get_peer_name().c_str());
		wrap->close_session();
		return;
	}
	CDPWALK_RESULT	datamap_alias;
	if( SNMP_ERROR_SUCCESS != wrap->send_sync_walk_request(alias_Oid.c_str(),
		datamap_alias)
		)
	{
		printf("send oid [%s] with device IP [%s] fail.\n",alias_Oid.c_str(),wrap->get_peer_name().c_str());
		wrap->close_session();
		return;
	}
	wrap->close_session(); //取完数据之后关闭snmp-session

	list<string> index_list;
	list<string>::iterator it_index;
	string range;

	range = g_mapTransFiberConfig[ wrap->get_peer_name() ].rang_s;

	for(int i=1; i<3; i++ )
	{
		list<Power_Value> data_list;
		index_list = g_mapTransFiberConfig[ wrap->get_peer_name() ].in_list[i];
		for(it_index = index_list.begin(); it_index != index_list.end(); it_index++)
		{
			char key_buff[512] = "\0";
			//获取key
			string key;
			sprintf( key_buff,"%s.%s", alias_Oid.c_str(), it_index->c_str());
			if( datamap_alias.find(key_buff)!=datamap_alias.end() )
			{
				key = datamap_alias[key_buff];
			}
			if( key.length()==0 )
			{
				CSynConnector *pSyn = CSynConnector::GetInstancePoint();
				if( pSyn != NULL )
				{
					pSyn->GetIfsName(wrap->get_peer_name(), *it_index, key);
				}
				else
				{
					//找不到端口名称
					continue;
				}
			}

			Power_Value pv;
			pv.p_name = key;

			memset(key_buff, 512, 0);
			sprintf( key_buff,"%s.%s.%s", OP_Oid.c_str(), it_index->c_str(),"1.1");
			if( datamap_op.find( key_buff ) != datamap_op.end() )
			{
				float  value = atof(datamap_op[ key_buff ].c_str());
				value = value/10;
				char databuff[16] = "\0";
				sprintf(databuff,"%.2f",value);
				pv.p_value.first = databuff;				
			}	
			else //有些端口可能取不到数据，以"/"代替
			{
				pv.p_value.first = "/";
			}
			pv.p_value.second = CheckRange(range, pv.p_value.first)?1:0;
			data_list.push_back(pv);

		}
		datas.push_back(data_list);
	}
}

//获取传输设备端口错包数 2013.8.12  by Lee 
void CGetTransFiberDevice::ProcessCiscoDeviceIfInErrors(
	CSnmpWrapper *wrap,
	vector<list<IFSINERROR_Value> >& datas)
{
	assert( wrap != NULL );
	string oid_ifs = "1.3.6.1.2.1.31.1.1.1.18";
	string oid_ifserror = "1.3.6.1.2.1.2.2.1.14";

	if ((!wrap->is_opened())
		&&	(!wrap->open_session()))
	{
		printf("open session fail ip[%s] with community[%s]\n",wrap->get_peer_name().c_str(),wrap->get_community().c_str());
		return;
	}

	CDPWALK_RESULT	datamap;
	if( SNMP_ERROR_SUCCESS != wrap->send_sync_walk_request(oid_ifserror.c_str(),
		datamap)
		)
	{
		printf("send oid [%s] with device IP [%s] fail.\n",oid_ifserror.c_str(),wrap->get_peer_name().c_str());
		wrap->close_session();
		return;
	}
	CDPWALK_RESULT	datamap_alias;
	if( SNMP_ERROR_SUCCESS != wrap->send_sync_walk_request(oid_ifs.c_str(),
		datamap_alias)
		)
	{
		printf("send oid [%s] with device IP [%s] fail.\n",oid_ifs.c_str(),wrap->get_peer_name().c_str());
		wrap->close_session();
		return;
	}
	wrap->close_session(); //取完数据之后关闭snmp-session

	list<string> index_list;
	list<string>::iterator it_index;

	for(int i=1; i<3; i++ )
	{
		list<IFSINERROR_Value> data_list;
		index_list = g_mapTransFiberConfig[ wrap->get_peer_name() ].in_list[i];
		for(it_index = index_list.begin(); it_index != index_list.end(); it_index++)
		{
			char key_buff[128] = "\0";
			int  i_index = atoi( it_index->c_str() );
			i_index += 20;
			//获取key
			string key;
			sprintf( key_buff,"%s.%d", oid_ifs.c_str(), i_index);
			if( datamap_alias.find(key_buff)!=datamap_alias.end() )
			{
				key = datamap_alias[key_buff];
			}
			if( key.length()==0 )
			{
				CSynConnector *pSyn = CSynConnector::GetInstancePoint();
				if( pSyn != NULL )
				{
					pSyn->GetIfsName(wrap->get_peer_name(), *it_index, key);
				}
				else
				{
					//找不到端口名称
					continue;
				}
			}

			memset(key_buff, 512, 0);
			sprintf( key_buff,"%s.%d", oid_ifserror.c_str(), i_index);
			if( datamap.find( key_buff ) != datamap.end() )
			{
				IFSINERROR_Value iv;
				iv.p_name = key;
				iv.p_value.first = datamap[ key_buff ];
				iv.p_value.second = (iv.p_value.first != "0") ? 0:1;
				data_list.push_back(iv);
			}			
		}
		datas.push_back(data_list);
	}
}

void CGetTransFiberDevice::FormatedataAccordingPro( list<Power_Value>& datas, string& lastresult)
{
	char buff[512];
	for(list<Power_Value>::iterator it = datas.begin(); it != datas.end(); it++)
	{
		if(lastresult.length()>0)
		{
			lastresult.append(",");
		}
		memset(buff, 512, 0);
		sprintf(buff,"%s*%s*%d",it->p_name.c_str(),it->p_value.first.c_str(),it->p_value.second);
		lastresult.append(buff);
	}
	printf("Formatedata [%s]\n",lastresult.c_str());
}

void CGetTransFiberDevice::test_ProcessCiscoDeviceIfInErrors(CSnmpWrapper *wrap,vector<list<IFSINERROR_Value> >& datas,string& lastresult)
{
	ProcessCiscoDeviceIfInErrors(wrap,datas);
	//for( int i = 0; i < datas.size(); i++ )
	//FormatedataAccordingPro( datas[i], lastresult);
	if( datas.size()>0 )
	{
		for( int i = 0; i< datas[i].size(); i++ )
		{
			if( datas[i].size()==0 ) //过滤掉空数据
			{
				continue;
			}
			if( i>0 )
			{
				lastresult.append(";");  //每组值（map）之间的分割符号
			}
			//附加location信息
			lastresult.append( g_mapTransFiberConfig[  wrap->get_peer_name() ].locate.c_str() );
			if( datas[i].size() > 1 ) 	//TP_POWER datas.size()==1,  OP_POWER and IFSINERROR datas.size()==2
			{
				char data[10]="\0";
				list<string> numb_list = g_mapTransFiberConfig[  wrap->get_peer_name() ].in_Number[i+1];
				if(numb_list.size()>0)
				{
					int number = atoi(numb_list.begin()->c_str());
					sprintf(data,"%d", number);
				}
				lastresult.append( data );
			}	
			lastresult.append(":");
			string keyvalue="";
			FormatedataAccordingPro( datas[i], keyvalue );
			lastresult.append( keyvalue.c_str() );
		}
	}
}			