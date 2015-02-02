#ifndef __BASE_I_ALLOCATOR_H__
#define __BASE_I_ALLOCATOR_H__

#include "IRef.h"

namespace core{

	class IAllocator : public virtual IRef
	{
	public:
		virtual void *alloc(size_t siz) = 0;
		virtual void free(void *ptr) = 0;
	};

#define IALLOCATOR_NAME		"::IALLOCATOR_RGLOBAL"
	
};

#endif

