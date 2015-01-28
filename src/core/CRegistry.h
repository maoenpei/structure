#ifndef __BASE_REGISTRY_H__
#define __BASE_REGISTRY_H__

#include "IRegistry.h"
#include "CStaticObject.h"
#include "TAuto.h"
#include <string>
#include <map>

namespace core{

	class CRegistry : public CStaticObject, public virtual IRegistry
	{
	public:
		virtual void regist(IRef *interf, const char *name);
		virtual IRef *find(const char *name);
		virtual void releaseAll();

	private:
		typedef std::map<std::string, TAuto<IRef> > RegistryMap;
		RegistryMap Datas;
	};
	
};

#endif

