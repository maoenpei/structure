

#include "CStaticObject.h"

namespace core{

CStaticObject::CStaticObject()
{
}

CStaticObject::~CStaticObject()
{
}

IRef *CStaticObject::grab()
{
	return this;
}

IRef *CStaticObject::drop()
{
	return this;
}

};


