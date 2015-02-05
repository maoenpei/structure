#ifndef __BASE_FILE_LOADER_H__
#define __BASE_FILE_LOADER_H__

#include "IFileLoader.h"
#include "core/CStaticObject.h"

namespace model{

	class CFileLoader : public core::CStaticObject, public virtual IFileLoader
	{
	public:
		virtual void readFileByPath(core::TAuto<IFileInput> &file, const char *path);
		virtual void writeFileByPath(core::TAuto<IFileOutput> &file, const char *path);

		virtual void readFileByFile(core::TAuto<IFileInput> &file, IFileInput *infile, unsigned int off, unsigned int len);
		virtual void readFileByMem(core::TAuto<IFileInput> &file, const unsigned char *data, unsigned int len);
	};
	
};

#endif

