// SCPPackageDesc.h: interface for the CSCPPackageDesc class.
//
// 20110119 ����   NT-0121��front������������
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCPPACKAGEDESC_H__C16CC87D_1BD0_4F0A_B286_BBAA19BAC3BF__INCLUDED_)
#define AFX_SCPPACKAGEDESC_H__C16CC87D_1BD0_4F0A_B286_BBAA19BAC3BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FieldDescribe.h"

#define STID_LOGIN_REQ						0x0001			//ϵͳͬ������
#define STID_LOGIN_RSP						0x0002			//ϵͳͬ����Ӧ
#define STID_LSA_REQ						0x0003			//LSA��������
#define STID_LSA_UPDATE						0x0004			//LSA��Ϣ
#define STID_LSA_COMPLETE					0x0005			//LSA�������
#define STID_SUBSCRIBE						0x0006			//��������
#define STID_UN_SUBSCRIBE					0x0007			//ȡ������
#define STID_PUBLISH						0x0008			//������������
#define STID_ACK							0x0009			//����ȷ��
#define STID_PUBLISH_REQ					0x000A			//��������
#define STID_PUBLISH_RSP					0x000B			//������Ӧ

class  CSCPLoginReqField 
{
public:
	CUFIntType	NodeID;				/**<�豸��*/
	CUFIntType	Metric;				/**<����*/
	CUFCharType	Type;				/**<�豸���� 'R'·���� 'T'�ն�*/
	/**���������Ե�����������д�������ձ�
	*/
	TYPE_DESCRIPTOR((
		TYPE_DESC(NodeID),
		TYPE_DESC(Metric),
		TYPE_DESC(Type)
	));
};

class CSCPLinkStateField 
{
public:
	CUFIntType NodeID;				/**< Ŀ���ַ*/
	CUFIntType Metric;				/**< ���� */
	CUFCharType Type;				/**< ���� 'T'�ն�, 'R'·��*/
	/**���������Ե�����������д�������ձ�
	*/
	TYPE_DESCRIPTOR((
		TYPE_DESC(NodeID),
		TYPE_DESC(Metric),
		TYPE_DESC(Type)
	));
};

class CSCPLsaHeadField 
{
public:
	CUFIntType NodeID;				/**<����LSA�Ľڵ�ID*/
	CUFCharType Type;				/**< ����LSA�Ľڵ����� 'T'�ն�, 'R'·��*/
	CUFIntType TimeStamp;			/**<ʱ���*/
	/**���������Ե�����������д�������ձ�
	*/
	TYPE_DESCRIPTOR((
		TYPE_DESC(NodeID),
		TYPE_DESC(Type),
		TYPE_DESC(TimeStamp)
	));
};

class CSCPSubscribeField 
{
public:
	CUFIntType SubscriberID;		/**<�����߱�ʶ  */
	CUFIntType SubjectID;			/**<�����ʶ*/
	CUFIntType StartID;				/**<��ʼ���*/
	CUFWordType  CommPhaseNo;		/**<ͨѶ�׶����,ÿ�θ�����ţ�SequenceNo����1���¿�ʼ */
	/**���������Ե�����������д�������ձ�
	*/
	TYPE_DESCRIPTOR((
		TYPE_DESC(SubscriberID),
		TYPE_DESC(SubjectID),
		TYPE_DESC(StartID),
		TYPE_DESC(CommPhaseNo)
	));
};

class CSCPPublishField 
{
public:
	CUFIntType SubjectID;			/**<�����ʶ*/
	CUFIntType SeqNo;				/**<����������*/
	CUFWordType  CommPhaseNo;		/**<ͨѶ�׶����,ÿ�θ�����ţ�SequenceNo����1���¿�ʼ */
	/**���������Ե�����������д�������ձ�
	*/
	TYPE_DESCRIPTOR((
		TYPE_DESC(SubjectID),
		TYPE_DESC(SeqNo),
		TYPE_DESC(CommPhaseNo)
	));
};

class  CSCPPublishReqField 
{
public:
	CUFIntType	NodeID;				/**<�豸��*/
	CUFIntType	Clock;				/**<ʱ��*/
	CUFIntType	SubjectID;			/**<�����ʶ*/
	CUFWordType	CommPhaseNo;		/**<ͨѶ�׶����,ÿ�θ�����ţ�SequenceNo����1���¿�ʼ */

	/**���������Ե�����������д�������ձ�
	*/
	TYPE_DESCRIPTOR((
		TYPE_DESC(NodeID),
		TYPE_DESC(Clock),
		TYPE_DESC(SubjectID),
		TYPE_DESC(CommPhaseNo)
	));
};

class  CSCPPublishRspField 
{
public:
	CUFIntType	NodeID;				/**<�豸��*/
	CUFIntType	Clock;				/**<ʱ��*/
	CUFIntType	SubjectID;			/**<�����ʶ*/
	CUFWordType	CommPhaseNo;		/**<ͨѶ�׶����,ÿ�θ�����ţ�SequenceNo����1���¿�ʼ */
	CUFIntType	SeqNo;				/**<����������*/

	/**���������Ե�����������д�������ձ�
	*/
	TYPE_DESCRIPTOR((
		TYPE_DESC(NodeID),
		TYPE_DESC(Clock),
		TYPE_DESC(SubjectID),
		TYPE_DESC(CommPhaseNo),
		TYPE_DESC(SeqNo)
	));
};

#endif // !defined(AFX_SCPPACKAGEDESC_H__C16CC87D_1BD0_4F0A_B286_BBAA19BAC3BF__INCLUDED_)
