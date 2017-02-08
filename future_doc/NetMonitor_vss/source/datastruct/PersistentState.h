#ifndef __PERSISTENTSTATE_H_
#define __PERSISTENTSTATE_H_

/**�����ʵ���˽�һ���������л���һ���ļ��ϣ���һ��ģ���� 
*/
template<class  TState>
class CPersistentState
{
public:
	
	/**���캯��
	* @param state �����Ӧ��
	*/
	CPersistentState(TState &state)
	{
		m_fp = NULL;
		m_State = state;
	}
	
	/**���캯������ʼ����������
	*/
	CPersistentState()
	{
		m_fp = NULL;
		memset(&m_State, 0, sizeof(TState));
	}

	/**�����������ر��ļ�
	*/
	~CPersistentState()
	{
		Close();
	}

	/**������ļ������ȡ�ļ�������
	* @param filename �ļ���
	* @return true �ɹ�
	* @return true ʧ��
	*/
	bool Open(char *pszFilename)
	{
		m_fp = mfopen(pszFilename,"r+b");
		if(m_fp == NULL)
		{
			m_fp = mfopen(pszFilename, "wb");
			if(m_fp == NULL)
			{
				return false;
			}
			return Write();
		}
		else
		{
			return Read();
		}
		return true;
	}

	/**�ر��ļ�
	*/
	void Close()
	{
		if(m_fp != NULL)
		{
			fclose(m_fp);
			m_fp = NULL;
		}
	}

	/**�������ļ��еĶ���
	* @param pState ��������ָ��
	* @return true �ɹ�
	* @return true ʧ��
	*/
	bool UpdateState(TState *pState)
	{
		m_State = *pState;
		return Write();
	}

	/**����������
	* @return ������������ָ��
	*/
	inline  TState *GetState()
	{
		return &m_State;
	}

protected:

	/**���ļ��ж�ȡ����
	* @return true �ɹ�
	* @return true ʧ��
	*/	
	bool Read()
	{
		if(m_fp==NULL)
		{
			return false;
		}
		
		if(fread(&m_State, sizeof(TState), 1, m_fp) != 1)
		{
			return false;
		}
		return true;
	}

	/**�Ѷ���д���ļ���
	* @return true �ɹ�
	* @return true ʧ��
	*/
	bool Write()
	{
		if(m_fp==NULL)
		{
			return false;
		}
		
		fseek(m_fp, 0, SEEK_SET);
		if(fwrite(&m_State, sizeof(TState), 1, m_fp) != 1)
		{
			return false;
		}
		fflush(m_fp);
		
		return true;
	}
	
protected:
	FILE * m_fp;	/**< ����ļ���ָ�� */
	TState m_State;	/**< Ҫд���ļ��Ķ��� */
};
#endif
