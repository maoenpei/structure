

#include "CRegistry.h"

namespace core{

void CRegistry::regist(IRef * interf,const char * name)
{
	std::string sName(name);
	Datas[sName] = interf;
}

IRef *CRegistry::find(const char * name)
{
	std::string sName(name);
	RegistryMap::iterator it = Datas.find(sName);
	if (it != Datas.end()){
		return it->second;
	}
	return 0;
}

void CRegistry::releaseAll()
{
	Datas.clear();
}

};

extern "C"
#ifdef WIN32
__declspec(dllexport)
#endif
core::IRegistry *staticGetRegistry(void)
{
	static core::CRegistry reg;
	return &reg;
}

core::IRegistry *getRegistry()
{
	return staticGetRegistry();
}



