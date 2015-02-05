

#include "CFileLoader.h"
#include "core/TConstructor.h"
#include "core/IRegistry.h"
#include "CFileInput.h"
#include "CFileOutput.h"
#include "CFileInputFile.h"
#include "CFileInputMem.h"

namespace model{

void CFileLoader::readFileByPath(core::TAuto<IFileInput> &file, const char *path)
{
	CFileInput *cfile = new CFileInput(path);
	if (cfile->isValid()){
		file = cfile;
	}else{
		delete cfile;
	}
}

void CFileLoader::writeFileByPath(core::TAuto<IFileOutput> &file, const char *path)
{
	CFileOutput *cfile = new CFileOutput(path);
	if (cfile->isValid()){
		file = cfile;
	}else{
		delete cfile;
	}
}

void CFileLoader::readFileByFile(core::TAuto<IFileInput> &file, IFileInput *infile, unsigned int off, unsigned int len)
{
	if (infile->available() >= off + len){
		file = new CFileInputFile(infile, off, len);
	}
}

void CFileLoader::readFileByMem(core::TAuto<IFileInput> &file, const unsigned char *data, unsigned int len)
{
	file = new CFileInputMem(data, len);
}

};

__construct_global(FILE_LOADER, {
	core::IRegistry *reg = getRegistry();
	static model::CFileLoader loader;
	reg->regist(&loader, FILE_LOADER_NAME);
});



