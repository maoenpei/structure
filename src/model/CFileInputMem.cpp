

#include "CFileInputMem.h"
#include <string>

namespace model{

unsigned int CFileInputMem::read(unsigned char * rBuf,unsigned int siz)
{
	siz = (MemPtr + siz > LimitPtr ? LimitPtr - MemPtr : siz);
	memcpy(rBuf, MemPtr, siz);
	MemPtr += siz;
	return siz;
}

unsigned int CFileInputMem::available()
{
	return LimitPtr - MemPtr;
}

unsigned int CFileInputMem::seek(unsigned int off)
{
	unsigned int cur = MemPtr - BasePtr;
	if (off != SEEK_INVALID){
		MemPtr = BasePtr + off;
	}
	return cur;
}

CFileInputMem::CFileInputMem(const unsigned char * mem,unsigned int len)
	: MemPtr(mem)
	, BasePtr(mem)
	, LimitPtr(mem + len)
{}

};


