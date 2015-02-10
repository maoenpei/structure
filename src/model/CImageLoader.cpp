

#include "CImageLoader.h"
#include "IImageDecoder.h"
#include "CImage.h"
#include "core/TConstructor.h"
#include "core/IRegistry.h"
#include "PNGImageCreater.h"

namespace model{

CImageLoader::CImageLoader()
{
	addImageCreater(new PNGImageCreater());
}

void CImageLoader::loadImage(core::TAuto<IImage> & img, IFileInput * file)
{
	core::TAuto<IImageDecoder> decoder;
	CreaterArray::iterator it;
	for (it = Creaters.begin(); it != Creaters.end(); it++){
		file->seek(0);
		(*it)->decoderFromFile(decoder, file);
		if (decoder){
			Sizei siz = decoder->getImageSize();
			int channel = decoder->getBytesPerPixel();
			img = new CImage(siz.w, siz.h, channel);
			decoder->readLines(img->getData());
			break;
		}
	}
}

void CImageLoader::addImageCreater(IImageCreater * creater)
{
	Creaters.push_back(creater);
}

};

__construct_global(IMAGE_LOADER, {
	core::IRegistry *reg = getRegistry();
	static model::CImageLoader loader;
	reg->regist(&loader, IMAGE_LOADER_NAME);
});

