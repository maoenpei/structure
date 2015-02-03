#ifndef __BASE_I_ENGINE_H__
#define __BASE_I_ENGINE_H__

#include "core/IRef.h"

namespace engine{

	class IGraphics : public virtual core::IRef
	{
	public:
		virtual void pipeline() = 0;
	};
	
};

#endif

