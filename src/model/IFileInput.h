#ifndef __BASE_I_FILE_INPUT_H__
#define __BASE_I_FILE_INPUT_H__

#include "core/IRef.h"

namespace model{

	class IFileInput : public virtual core::IRef
	{
	public:
		virtual unsigned int read(unsigned char *rBuf, unsigned int siz) = 0;
		virtual unsigned int available() = 0;
		virtual unsigned int seek(int off) = 0;
	};
	
};

#define SEEK_INVALID			(-1)

#endif

