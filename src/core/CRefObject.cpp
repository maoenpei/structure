

#include "CRefObject.h"
#include <assert.h>

namespace core{

CRefObject::CRefObject()
: ReferenceCount(0)
{}

CRefObject::~CRefObject()
{
	assert(ReferenceCount == 0);
}

IRef *CRefObject::grab()
{
	++ ReferenceCount;
	return this;
}

IRef *CRefObject::drop()
{
	if (--ReferenceCount == 0){
		delete this;
		return 0;
	}
	return this;
}

};


