#ifndef __BASE_I_ENGINE_H__
#define __BASE_I_ENGINE_H__

#include "core/IRef.h"
#include "model/IImage.h"

namespace engine{

	class ITexture;
	class IGraphics : public virtual core::IRef
	{
	public:
		virtual ITexture *loadTexture(model::IImage *image) = 0;
		
		virtual void pipeline() = 0;
	};
	
};

#endif

