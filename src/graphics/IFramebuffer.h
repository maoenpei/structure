#ifndef __BASE_I_FRAME_BUFFER_H__
#define __BASE_I_FRAME_BUFFER_H__

#include "core/IRef.h"
#include "ITexture.h"
#include "model/TGeometry.h"

namespace graphics{

	class IFramebuffer : public virtual core::IRef
	{
	public:
		// states
		virtual void setBackground(const model::Color4f &color) = 0;
		virtual void openDepth(float defDepth) = 0;
		
		// operations
		virtual void copyImage(ITexture *tex) = 0;
	};
	
};

#endif

