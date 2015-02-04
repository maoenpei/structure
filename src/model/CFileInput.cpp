

#include "CFileInput.h"

namespace model{

CFileInput::CFileInput(const char *path)
{
	FilePtr = fopen(path, "rb");
}

CFileInput::~CFileInput()
{
	if (FilePtr){
		fclose(FilePtr);
	}
}

unsigned int CFileInput::read(unsigned char * rBuf,unsigned int siz)
{
	if (FilePtr){
		return fread(rBuf, 1, siz, FilePtr);
	}
	return 0;
}

unsigned int CFileInput::available()
{
	if (FilePtr){
		size_t cur = ftell(FilePtr);
		fseek(FilePtr, 0, SEEK_END);
		size_t max = ftell(FilePtr);
		fseek(FilePtr, cur, SEEK_SET);
		return max-cur;
	}
	return 0;
}

unsigned int CFileInput::seek(int off)
{
	if (FilePtr){
		size_t cur = ftell(FilePtr);
		if (off != SEEK_INVALID){
			fseek(FilePtr, off, SEEK_SET);
		}
		return cur;
	}
	return 0;
}

bool CFileInput::isValid()
{
	return FilePtr != 0;
}

};


