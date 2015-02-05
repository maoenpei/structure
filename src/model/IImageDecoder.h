#ifndef __BASE_I_IMAGE_DECODER_H__
#define __BASE_I_IMAGE_DECODER_H__

#include "core/IRef.h"
#include "TGeometry.h"

namespace model{
	
	class IImageDecoder : public virtual core::IRef
	{
	public:
		virtual const Sizei &getImageSize() = 0;
		virtual int getBytesPerPixel() = 0;

		virtual void readLines(unsigned char *pxs) = 0;
	};
	
};

#endif

