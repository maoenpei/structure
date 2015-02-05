#ifndef __BASE_I_FILE_LOADER_H__
#define __BASE_I_FILE_LOADER_H__

#include "core/IRef.h"
#include "core/TAuto.h"

namespace model{

	class IFileInput;
	class IFileOutput;
	class IFileLoader : public virtual core::IRef
	{
	public:
		virtual void readFileByPath(core::TAuto<IFileInput> &file, const char *path) = 0;
		virtual void writeFileByPath(core::TAuto<IFileOutput> &file, const char *path) = 0;

		virtual void readFileByFile(core::TAuto<IFileInput> &file, IFileInput *infile, unsigned int off, unsigned int len) = 0;
		virtual void readFileByMem(core::TAuto<IFileInput> &file, const unsigned char *data, unsigned int len) = 0;
	};
	
};

#define FILE_LOADER_NAME		"::IFileLoaderInstance"

#endif

