#ifndef __BASE_FILE_INPUT_FILE_H__
#define __BASE_FILE_INPUT_FILE_H__

#include "IFileInput.h"
#include "core/CRefObject.h"
#include "core/TAuto.h"

namespace model{

	class CFileInputFile : public core::CRefObject, public virtual IFileInput
	{
	public:
		virtual unsigned int read(unsigned char *rBuf, unsigned int siz);
		virtual unsigned int available();
		virtual unsigned int seek(unsigned int off);
		
		CFileInputFile(IFileInput *file, unsigned int off, unsigned int len);

	private:
		core::TAuto<IFileInput> File;
		unsigned int Start;
		unsigned int Length;
	};
	
};

#endif

