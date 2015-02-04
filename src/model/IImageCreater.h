#ifndef __BASE_I_IMAGE_CREATER_H__
#define __BASE_I_IMAGE_CREATER_H__

#include "core/IRef.h"
#include "IFileInput.h"
#include "IFileOutput.h"
#include "core/TAuto.h"

namespace model{

	class IImageDecoder;
	class IImageCreater : public virtual core::IRef
	{
	public:
		virtual void encoderFromFile(core::TAuto<IImageDecoder> &decoder, IFileInput *file) = 0;

		//virtual void fileFromDecoder(core::TAuto<IImageEncoder> &encoder, IFileOutput *file) = 0;
	};
	
};

#endif

