#ifndef __BASE_I_FILE_OUTPUT_H__
#define __BASE_I_FILE_OUTPUT_H__

#include "core/IRef.h"

namespace model{

	class IFileOutput : public virtual core::IRef
	{
	public:
		virtual unsigned int write(const unsigned char *wBuf, unsigned int siz) = 0;
	};
	
};

#endif

