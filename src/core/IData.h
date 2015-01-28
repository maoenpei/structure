#ifndef __BASE_I_DATA_H__
#define __BASE_I_DATA_H__

#include "IRef.h"

namespace core{
	
	class IData : public virtual IRef
	{
	public:
		virtual unsigned int getSize() = 0;
		virtual const unsigned char * getBytes() = 0;
	};
	
}

#endif

