#ifndef _PUBLIC_H
#define _PUBLIC_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#include "CBaseObject.h"

typedef int FTRESUTLT;

const FTRESUTLT FR_OK		= 0;
const FTRESUTLT FR_ERROR	= -1;

struct ltstr
{
	bool operator()(const char* s1, const char* s2) const
	{
		return strcmp(s1, s2) < 0;
	}
};


#endif

