#ifndef __BASE_FILE_OUTPUT_H__
#define __BASE_FILE_OUTPUT_H__

#include "IFileOutput.h"
#include "core/CRefObject.h"
#include <stdio.h>

namespace model{

	class CFileOutput : public core::CRefObject, public virtual IFileOutput
	{
	public:
		virtual unsigned int write(const unsigned char *wBuf, unsigned int siz);

		bool isValid();
		CFileOutput(const char *path);
		virtual ~CFileOutput();

	private:
		FILE * FilePtr;
	};
	
};

#endif

