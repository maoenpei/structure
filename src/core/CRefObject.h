#ifndef __BASE_REF_OBJECT_H__
#define __BASE_REF_OBJECT_H__

#include "IRef.h"

namespace core{

	class CRefObject : public virtual IRef
	{
		unsigned int ReferenceCount;
	public:
		virtual IRef * grab();
		virtual IRef * drop();

		CRefObject();
		virtual ~CRefObject();
	};
	
};

#endif

