#ifndef __PNG_IMAGE_CREATER_H__
#define __PNG_IMAGE_CREATER_H__

#include "IImageCreater.h"
#include "core/CRefObject.h"

namespace model{

	class PNGImageCreater : public core::CRefObject, public virtual IImageCreater
	{
	public:
		virtual void encoderFromFile(core::TAuto<IImageDecoder> &decoder, IFileInput *file);
		
	};
	
};

#endif

