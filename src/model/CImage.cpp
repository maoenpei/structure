

#include "CImage.h"

namespace model{

CImage::CImage(int w, int h, int channel)
	: SizeOfImage(w, h)
	, Channel(channel)
{
	Data = new unsigned char [w*h*channel] ();
}

CImage::~CImage()
{
	delete [] Data;
}

const Sizei &CImage::getSize()
{
	return SizeOfImage;
}

int CImage::getChannel()
{
	return Channel;
}

unsigned char *CImage::getData()
{
	return Data;
}


};


