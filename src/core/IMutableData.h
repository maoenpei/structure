#ifndef __BASE_I_MUTABLE_DATA_H__
#define __BASE_I_MUTABLE_DATA_H__

#include "IRef.h"

namespace core{
	
	class IMutableData : public virtual IRef
	{
	public:
		virtual void input(unsigned char *bytes, unsigned int len) = 0;
		virtual unsigned int getSize() = 0;
		virtual unsigned char * getBytes() = 0;
	};
	
};

#endif

