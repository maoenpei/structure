#ifndef __BASE_I_REGISTRY_H__
#define __BASE_I_REGISTRY_H__

#include "IRef.h"

namespace core{

	class IRegistry : public virtual IRef
	{
	public:
		virtual void regist(IRef *interf, const char *name) = 0;
		virtual IRef *find(const char *name) = 0;
		virtual void releaseAll() = 0;
	};

};

#define REGISTRY_FUNC_NAME		"staticGetRegistry"
typedef core::IRegistry * (*getRegistry_func)(void);

extern "C" core::IRegistry *getRegistry();

#endif

