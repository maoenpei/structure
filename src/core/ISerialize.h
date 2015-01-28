#ifndef __BASE_I_SERIALIZE_H__
#define __BASE_I_SERIALIZE_H__

#include "IRef.h"
#include "IData.h"
#include "IMutableData.h"

namespace core{
	
	class ISerialize : public virtual IRef
	{
	public:
		virtual void restore(IData *dat) = 0;
		virtual void serialize(IMutableData *dat) = 0;
	};
	
};

#endif

