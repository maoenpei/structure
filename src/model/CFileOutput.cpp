

#include "CFileOutput.h"

namespace model{

CFileOutput::CFileOutput(const char *path)
{
	FilePtr = fopen(path, "wb+");
}

CFileOutput::~CFileOutput()
{
	if (FilePtr){
		fclose(FilePtr);
	}
}

bool CFileOutput::isValid()
{
	return FilePtr != 0;
}

unsigned int CFileOutput::write(const unsigned char * wBuf,unsigned int siz)
{
	if (FilePtr){
		fwrite(wBuf, 1, siz, FilePtr);
	}
	return 0;
}

};


