#ifndef __BASE_I_IMAGE_LOADER_H__
#define __BASE_I_IMAGE_LOADER_H__

#include "core/IRef.h"
#include "core/TAuto.h"

namespace model{

	class IImage;
	class IFileInput;
	class IImageCreater;
	class IImageLoader : public virtual core::IRef
	{
	public:
		virtual void loadImage(core::TAuto<IImage> &img, IFileInput *file) = 0;

		virtual void addImageCreater(IImageCreater *creater) = 0;
	};
	
};

#define IMAGE_LOADER_NAME		"::IImageLoaderInstance"

#endif

