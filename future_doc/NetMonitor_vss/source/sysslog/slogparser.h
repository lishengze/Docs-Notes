///////////////////////////////////////////////////////////////////////////////////////
//slogparser.h
//
//20071226 �Ժ��	����ʹ��-a���������OFP����������/Ӧ��ʱ��
//20080109 �Ժ��	1.����-e������ָ����������ļ�
//					2.�޸�-a����������ָ�����RTT����Ҫ��ı�������/Ӧ��
//					3.��������Ӧ��ƥ���Ϊ�ĸ��ֶΣ�������LocalID��źͻỰ�ţ��Ա���
//					  LocalID�ظ������ڻ�Ա��MBack
//					4.�޸�Reactor������������ģʽ�����ٱ���IOList������CSlogConnection
//					  ֱ���������ٶȿ�����߼�ʮ��
//20080110 �Ժ��	1.���Ӷ�FTDЭ���֧��
//					2.RTT����֧��-fģʽ
#ifndef REF_SLOGPARSER_H
#define REF_SLOGPARSER_H

#include "public.h"
#include "FTDCSession.h"
#include "OFPSession.h"
#include "FtdPackageDesc.h"
#include "FTDCPackage.h"
#include "CSVParser.h"
#include "Storage.h"
#include "OfpData.h"
#include "FtdPackageDesc.h"
#include "CDate.h"
#include "version.h"
#include "SelectReactor.h"

#include "CPackageFilter.h"
#include "CSlogConnection.h"
#include "CDumpSession.h"
#include "COrderRttManager.h"

#define MAX_SLOG_REC_LEN	20480

#define COUNT_NEW_SLOG_FLAG 60

typedef CHashMap<int, CSlogConnection *, HashInt> CSlogConnectionMap;

#define DEFAULT_FOLLOW	true

///=== 20110907 by zhou.jj

/**Channel�¼�����־�е�ͷ
*/
struct TNewChannelLogHeader
{
	DWORD dwId;		/**< Channel�ľ��*/
	DWORD dwTime;	/**< �¼�����ʱ�� */
	WORD wType;		/**< �¼����� */
	WORD wLength;	/**< �¼����ݳ��� */

	/**�ı��ֽ���
	*/
	void ChangeEndian(void)
	{
		CHANGE_ENDIAN(dwId);
		CHANGE_ENDIAN(dwTime);
		CHANGE_ENDIAN(wType);
		CHANGE_ENDIAN(wLength);
	}
};

///20110907 by zhou.jj


/////////////////////////////////////////////////////////////////////////
///CSlogDescript�����˵���slog�ļ���ȡ������
///@author	�ܽ���
///@version	1.0,20080711
/////////////////////////////////////////////////////////////////////////
class CSlogDescript
{
	/* */
	public:
		CSlogDescript(void);

		///���캯��
			///@param	pszSlogFileName	SLog�ļ�����
			///@param	nSlogFileNameId	�ļ�����ΨһID���
		CSlogDescript(const char *pszSlogFileName, const int nSlogFileNameId);

		///���캯��
			///@param	nDataCenterId	Slog�ļ�������������ID���
			///@param	pszSlogFileName	SLog�ļ�����
			///@param	nSlogFileNameId	�ļ�����ΨһID���
		CSlogDescript(
			const int nDataCenterId,
			const char	*pszSlogFileName,
			const int nSlogFileNameId);

		///���캯��
			///@param	nDataCenterId	Slog�ļ�������������ID���
			///@param	pszSlogFileName	SLog�ļ�����
			///@param	nSlogFileNameId	�ļ�����ΨһID���
			///@param	pszDesiredIpAddress	���˵�ip��ַ
		CSlogDescript(
			const int nDataCenterId,
			const char	*pszSlogFileName,
			const int nSlogFileNameId,
			const char	*pszDesiredIpAddress);

		///���캯��
			///@param	nDataCenterId	Slog�ļ�������������ID���
			///@param	pszSlogFileName	SLog�ļ�����
			///@param	nSlogFileNameId	�ļ�����ΨһID���
			///@param	pszDesiredIpAddress	���˵�ip��ַ
			///@param	bFollow	������ȡ�ļ����
		CSlogDescript(
			const int nDataCenterId,
			const char	*pszSlogFileName,
			const int nSlogFileNameId,
			const char	*pszDesiredIpAddress,
			bool bFollow);

		///�������캯��
		CSlogDescript(const CSlogDescript &ob)
		{
			m_fpSlog = ob.m_fpSlog;
			m_strSlogFileName = ob.m_strSlogFileName;
			m_strDesiredIpAddress = ob.m_strDesiredIpAddress;
			memcpy(&m_header, &(ob.m_header), sizeof(m_header));
			m_nReadLen = ob.m_nReadLen;
			m_bFollow = ob.m_bFollow;

			INT64 mFposlong = FPOS_GET(ob.m_fposLog);
			FPOS_SET(m_fposLog, mFposlong);
			m_tLastTime = ob.m_tLastTime;
			m_nFrontID = ob.m_nFrontID;
			m_nFileID = ob.m_nFileID;
			m_cVersion = ob.m_cVersion;
			m_cWrongFlag = ob.m_cWrongFlag;
			newFileFlag = ob.newFileFlag;
		}

		///���ء�=�������
		void operator=(const CSlogDescript &ob)
		{
			m_fpSlog = ob.m_fpSlog;
			m_strSlogFileName = ob.m_strSlogFileName;
			m_strDesiredIpAddress = ob.m_strDesiredIpAddress;
			memcpy(&m_header, &(ob.m_header), sizeof(m_header));
			m_nReadLen = ob.m_nReadLen;
			m_bFollow = ob.m_bFollow;

			INT64 mFposlong = FPOS_GET(ob.m_fposLog);
			FPOS_SET(m_fposLog, mFposlong);
			m_tLastTime = ob.m_tLastTime;
			m_nFrontID = ob.m_nFrontID;
			m_nFileID = ob.m_nFileID;
			m_cVersion = ob.m_cVersion;
			m_cWrongFlag = ob.m_cWrongFlag;
			newFileFlag = ob.newFileFlag;
		}
		int getIDFrontMap(string str_slog_file_name);
	/* */
	public:
		///����򿪵��ļ�������
		FILE *m_fpSlog;

		///SLog���ݰ�ͷ
		TChannelLogHeader m_header;
		TNewChannelLogHeader m_newHeader;

		///�ļ���д������
		char m_buffer[MAX_SLOG_REC_LEN];

		///�ļ��Ѷ�ȡ����
		int m_nReadLen;

		///�ļ���ȡ���,true��ʾѭ����ȡ,false��ʾ��ȡ������ֹͣ
		bool m_bFollow;

		///�����ļ�·����
		string	m_strSlogFileName;

		///������˵�IP��ַ
		string	m_strDesiredIpAddress;

		///�ļ���дλ��
		fpos_t	m_fposLog;

		///����Slog���Ӷ���
		CSlogConnectionMap	m_mapSlogConnection;

		///������ʱ��
		time_t	m_tLastTime;

		///ǰ�õı��
		int m_nFrontID;

		///��ȡ�ļ��ı��
		int m_nFileID;

		///Э��汾��,0Ϊftd��1Ϊofp��2Ϊofp2
		char m_cVersion;

		///�ļ������ǣ�һ���ļ�����������ͣ��ȡ���ļ�
		char m_cWrongFlag;

		///=== 20110907 by zhou.jj
			///SLog�¸�ʽ���ݰ�ͷ
		int newFileFlag;

		/// 20110907 by zhou.jj
};

class CSlogReactor :
	public CReactor
{
	/* */
	public:
		~ CSlogReactor(void);

		void Clear(void)
		{
			for (m_mapIt = m_mapSlogDescript.begin();
				 m_mapIt != m_mapSlogDescript.end();
				 m_mapIt++)
			{
				CSlogConnectionMap::iterator itor = m_mapIt->second.
					m_mapSlogConnection.Begin();
				while (!itor.IsEnd())
				{
					delete(*itor);
					itor++;
				}

				m_mapIt->second.m_mapSlogConnection.Clear();

				if (m_mapIt->second.m_fpSlog != NULL)
				{
					fclose(m_mapIt->second.m_fpSlog);
					m_mapIt->second.m_fpSlog = NULL;
				}
			}

			m_mapSlogDescript.clear();
		}

		void GetSlogFileStatus(int nFrontID, char *pLogBuf);

	/* */
	protected:
		CSlogConnection *CreateSlogConnection(
							int nID,
							const char	*pszIPAddress,
							int nFrontID,
							int nFileID,
							char cVersion);
		CSlogConnection *GetSlogConnection(int nID);
		bool DelSlogConnection(int nID);

		bool ReadOne(void);
		virtual void DispatchIOs(void);

	/* */
	private:
		void PrepareIds(fd_set &readfds, fd_set &writefds, int &MaxID);
		void DispatchIO(fd_set &readfds, fd_set &writefds, int &MaxID);

	/* */
	private:
		map<string, CSlogDescript>	m_mapSlogDescript;
		map<string, CSlogDescript>::iterator m_mapIt;
};
#endif //end REF_SLOGPARSER_H
