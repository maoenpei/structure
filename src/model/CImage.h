#ifndef __BASE_IMAGE_H__
#define __BASE_IMAGE_H__

#include "IImage.h"
#include "core/CRefObject.h"

namespace model{

	class CImage : public core::CRefObject, public virtual IImage
	{
	public:
		CImage(int w, int h, int channel);
		virtual ~CImage();
		
		virtual const Sizei &getSize();
		virtual int getChannel();
		virtual unsigned char *getData();

	private:
		unsigned char * Data;
		int Channel;
		Sizei SizeOfImage;
	};
	
};

#endif

