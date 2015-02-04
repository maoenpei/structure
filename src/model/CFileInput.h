#ifndef __BASE_FILE_INPUT_H__
#define __BASE_FILE_INPUT_H__

#include "IFileInput.h"
#include "core/CRefObject.h"
#include <stdio.h>

namespace model{

	class CFileInput : public core::CRefObject, public virtual IFileInput
	{
	public:
		virtual unsigned int read(unsigned char *rBuf, unsigned int siz);
		virtual unsigned int available();
		virtual unsigned int seek(int off);

		bool isValid();
		
		CFileInput(const char *path);
		virtual ~CFileInput();

	private:
		FILE *FilePtr;
	};
	
};

#endif

