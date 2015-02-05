#ifndef __BASE_IMAGE_LOADER_H__
#define __BASE_IMAGE_LOADER_H__

#include "core/CStaticObject.h"
#include "IImageLoader.h"
#include <vector>
#include "core/TAuto.h"
#include "IImageCreater.h"

namespace model{

	class CImageLoader : public core::CStaticObject, public virtual IImageLoader
	{
	public:
		virtual void loadImage(core::TAuto<IImage> &img, IFileInput *file);

		virtual void addImageCreater(IImageCreater *creater);

		CImageLoader();

	private:
		typedef std::vector<core::TAuto<IImageCreater> > CreaterArray;
		CreaterArray Creaters;
	};
	
};

#endif

