

#include "CGraphicsCacher.h"
#include "model/IImageLoader.h"
#include "model/IFileLoader.h"
#include "model/IFileInput.h"
#include "core/IRegistry.h"

namespace graphics{

static core::TAuto<model::IImageLoader> Imgloader;
static core::TAuto<model::IFileLoader> FileLoader;

CGraphicsCacher::CGraphicsCacher(IGraphics * graph)
	: G(graph)
{
	if (! Imgloader){
		Imgloader = getRegistry()->find(IMAGE_LOADER_NAME)->cast<model::IImageLoader>();
	}
	if (! FileLoader){
		FileLoader = getRegistry()->find(FILE_LOADER_NAME)->cast<model::IFileLoader>();
	}
}

ITexture *CGraphicsCacher::cacheTexture(const char *path, const char * name)
{
	std::map<std::string, core::TAuto<ITexture> >::iterator it = Textures.find(name);
	if (it != Textures.end()){
		return it->second;
	}
	core::TAuto<model::IFileInput> fin;
	FileLoader->readFileByPath(fin, path);
	if (! fin){
		return 0;
	}
	core::TAuto<model::IImage> img;
	Imgloader->loadImage(img, fin);
	if (! img){
		return 0;
	}
	core::TAuto<ITexture> &tex = Textures[name];
	G->loadTexture(tex, img);
	return tex;
}

ITexture *CGraphicsCacher::findTexture(const char * name)
{
	std::map<std::string, core::TAuto<ITexture> >::iterator it = Textures.find(name);
	if (it != Textures.end()){
		return it->second;
	}
	return 0;
}

void CGraphicsCacher::removeTexture(const char * name)
{
	std::map<std::string, core::TAuto<ITexture> >::iterator it = Textures.find(name);
	if (it != Textures.end()){
		Textures.erase(it);
	}
}

IShaderProgram *CGraphicsCacher::cacheProgram(const char * vertex,const char * frag,const char * name)
{
	std::map<std::string, core::TAuto<IShaderProgram> >::iterator it = Programs.find(name);
	if (it != Programs.end()){
		return it->second;
	}
	core::TAuto<IShaderProgram> &pgm = Programs[name];
	G->loadProgram(pgm, vertex, frag);
	return pgm;
}

IShaderProgram *CGraphicsCacher::findProgram(const char * name)
{
	std::map<std::string, core::TAuto<IShaderProgram> >::iterator it = Programs.find(name);
	if (it != Programs.end()){
		return it->second;
	}
	return 0;
}

void CGraphicsCacher::removeProgram(const char * name)
{
	std::map<std::string, core::TAuto<IShaderProgram> >::iterator it = Programs.find(name);
	if (it != Programs.end()){
		Programs.erase(it);
	}
}

};


