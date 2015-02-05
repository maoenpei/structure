

#include "PNGImageCreater.h"
#include "IImageDecoder.h"
#include "png.h"
#include <string>

#define PNG_HEAD_LEN		(8)

namespace model{

class PNGImageDecoderImpl : public core::CRefObject, public virtual IImageDecoder
{
public:
	Sizei siz;
	int channel;
	png_structp png_ptr;
	png_infop info_ptr;
	png_size_t rowbytes;
	core::TAuto<IFileInput> File;
	unsigned int total_bytes;
	
	virtual const Sizei &getImageSize()
	{
		return siz;
	}
	virtual int getBytesPerPixel()
	{
		return channel;
	}
	
	virtual void readLines(unsigned char *pxs)
	{
		png_bytep *lines = new png_bytep[siz.h];
		for (int i = 0; i<siz.h; i++){
			lines[i] = pxs + i * rowbytes;
		}
		png_read_image(png_ptr, lines);
		png_read_end(png_ptr, 0);
		delete [] lines;
	}

	static void pngfn_read_from_file(png_structp png_ptr, png_bytep data, png_size_t length)
	{
		PNGImageDecoderImpl *self = (PNGImageDecoderImpl *)png_get_io_ptr(png_ptr);
		self->readFromFile(data, length);
	}
	void readFromFile(png_bytep data, png_size_t length)
	{
		if (length <= total_bytes){
			File->read(data, length);
			total_bytes -= length;
		}else{
			File->read(data, total_bytes);
			memset(data + total_bytes, 0, length - total_bytes);
			total_bytes = 0;
		}
	}

	PNGImageDecoderImpl(IFileInput *file)
		: File(file)
	{
		total_bytes = File->available();
		
		png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, 0, 0, 0);
		info_ptr = png_create_info_struct(png_ptr);
		png_set_read_fn(png_ptr, this, pngfn_read_from_file);
		png_set_sig_bytes(png_ptr, 8);
		png_read_info(png_ptr, info_ptr);

		siz.w = png_get_image_width(png_ptr, info_ptr);
		siz.h = png_get_image_height(png_ptr, info_ptr);
		rowbytes = png_get_rowbytes(png_ptr, info_ptr);
		channel = rowbytes / siz.w;
	}
	virtual ~PNGImageDecoderImpl()
	{
		png_destroy_read_struct(&png_ptr, &info_ptr, 0);
	}
};

void PNGImageCreater::encoderFromFile(core::TAuto<IImageDecoder> &decoder, IFileInput *file)
{
	decoder = 0;
	
	unsigned char head[PNG_HEAD_LEN] = {0};
	file->seek(0);
	file->read(head, PNG_HEAD_LEN);
	if (png_check_sig(head, PNG_HEAD_LEN)){
		decoder = new PNGImageDecoderImpl(file);
	}
}

};


