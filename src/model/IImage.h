#ifndef __BASE_I_IMAGE_H__
#define __BASE_I_IMAGE_H__

#include "core/IRef.h"
#include "TGeometry.h"

namespace model{

	class IImage : public virtual core::IRef
	{
	public:
		virtual const Sizei &getSize() = 0;
		virtual int getChannel() = 0;
		virtual unsigned char *getData() = 0;
	};
	
};

#endif

