#ifndef __BASE_STATIC_OBJECT_H__
#define __BASE_STATIC_OBJECT_H__

#include "IRef.h"

namespace core{

	class CStaticObject : public virtual IRef
	{
	public:
		virtual IRef * grab();
		virtual IRef * drop();

		CStaticObject();
		virtual ~CStaticObject();

	private:
		static void *operator new(size_t siz);
		static void *operator new[](size_t siz);
	};
};

#endif

