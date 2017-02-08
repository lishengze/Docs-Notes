/////////////////////////////////////////////////////////////////////////
///@system	������ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CRegexConfig.h
///@brief	�����˹���������ʽ������Ϣ����
///@history
///20110927	κ�� �������ļ�
#ifndef REF_CREGEXCONFIG_H
#define REF_CREGEXCONFIG_H

#include <string>
#include <vector>
#include <map>

using namespace std;

//��ȡ�������ݵ�һ������
class AttrNodeInfo
{
	/* */
	public:
		string	key;
		string	value;
};

//������ʽ�����
class CRegexNode
{
	/* */
	public:
		string	condition;				//��������		
		bool isloop;					//�Ƿ�ѭ��ִ�б�����
		bool ismatchsingle;				//�Ƿ���ƥ��
		bool ignorecase;				//�Ƿ���Դ�Сд
		string	notmatchattrname;		//ƥ��ʧ�ܲ�����ָ������, Ϊ�ձ�ʾ������
		vector<string>	attrnamelist;	//���ɵ�ָ������
};

//������ʽ���ù�����
class CRegexConfigManager
{
	/* */
	public:
		static CRegexConfigManager	*Instance(void);	//ʵ����������ģʽ
		CRegexConfigManager(void) :
		m_sFileName(""),
		m_tLastLoadTime(0)
		{
		}

		int LoadConfig(std::string filename);			//��������
		int ReloadConfig(void); //���¼�������
		void DumpConfig(void);

		//�ӽ����������ȡָ��ֵ
		vector<vector<AttrNodeInfo> > ParseCommandResult(
										string	command,
										string	result,
										bool addquote = true,
										string command2=string());

		//�жϸ����������Ƿ�������������, 0��ʾ�ɹ�������ʧ��
		int RegexSearch(string regexstr, string inputstr);

	/* */
	public:
		map<string, vector<CRegexNode> > m_mRegexList;

	/* */
	private:
		std::string m_sFileName;	//�����ļ���
		time_t	m_tLastLoadTime;	//�ϴμ���ʱ��
};
#endif
