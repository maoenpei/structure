

#include "CFileInputFile.h"

namespace model{

unsigned int CFileInputFile::read(unsigned char * rBuf,unsigned int siz)
{
	unsigned int cur = File->seek(SEEK_INVALID);
	if (cur + siz > Start + Length){
		siz = Start + Length - cur;
	}
	return File->read(rBuf, siz);
}

unsigned int CFileInputFile::available()
{
	return (Start + Length) - File->seek(SEEK_INVALID);
}

unsigned int CFileInputFile::seek(unsigned int off)
{
	if (off == SEEK_INVALID){
		return File->seek(SEEK_INVALID) - Start;
	}
	return File->seek(Start + off) - Start;
}

CFileInputFile::CFileInputFile(IFileInput * file,unsigned int off,unsigned int len)
	: File(file), Start(off), Length(len)
{
	File->seek(Start);
}

};


