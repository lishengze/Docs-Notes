#ifndef _FILEOCGUARD_H
#define _FILEOCGUARD_H

/////////////////////////////////////////////////////////////////////////
///@brief	实现对文件和管道的打开关闭的守护，减少程序书写的麻烦
///@history
///20080510	武玉波		创建该文件
/////////////////////////////////////////////////////////////////////////
#include <stdio.h>

//#include "platform.h"
//#include "mpath.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#ifdef WIN32
#define PIPE_OPEN	_popen
#define PIPE_CLOSE	_pclose
#else
#define PIPE_OPEN	popen
#define PIPE_CLOSE	pclose
#endif
#ifdef HP_UX
#define PIPE_OPEN	popen
#define PIPE_CLOSE	pclose
#endif
template<bool isPipe = false>
class CFileOCGuard
{
	/* */
	public:
		CFileOCGuard(const char *filename, const char *mode) :
		m_file(NULL)
		{
			//char actualName[MAX_PATH_LEN+1];
			//convertPath(actualName,filename);
			m_file = fopen(filename, mode);
		}

		~CFileOCGuard(void)
		{
			if (NULL != m_file)
			{
				SAFE_FCLOSE(m_file);
			}

			m_file = NULL;
		}

		FILE *GetFileHandle(void)
		{
			return m_file;
		}

	/* */
	private:
		CFileOCGuard(const CFileOCGuard &);
		CFileOCGuard *operator	=(const CFileOCGuard &);
		FILE *m_file;
};

template<>
class CFileOCGuard<true>
{
	/* */
	public:
		CFileOCGuard(const char *filename, const char *mode) :
		m_file(NULL)
		{
			m_file = PIPE_OPEN(filename, mode);
		}

		~CFileOCGuard(void)
		{
			if (NULL != m_file)
			{
				PIPE_CLOSE(m_file);
			}

			m_file = NULL;
		}

		FILE *GetFileHandle(void)
		{
			return m_file;
		}

	/* */
	private:
		FILE *m_file;
};
#endif
