#ifndef __BASE_FILE_INPUT_MEM_H__
#define __BASE_FILE_INPUT_MEM_H__

#include "IFileInput.h"
#include "core/CRefObject.h"

namespace model{

	class CFileInputMem : public core::CRefObject, public virtual IFileInput
	{
	public:
		virtual unsigned int read(unsigned char *rBuf, unsigned int siz);
		virtual unsigned int available();
		virtual unsigned int seek(unsigned int off);

		CFileInputMem(const unsigned char *mem, unsigned int len);

	private:
		const unsigned char *MemPtr;
		const unsigned char *BasePtr;
		const unsigned char *LimitPtr;
	};
	
};

#endif


