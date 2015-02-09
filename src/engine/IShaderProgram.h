#ifndef __BASE_I_SHADER_PROGRAM_H__
#define __BASE_I_SHADER_PROGRAM_H__

#include "core/IRef.h"

namespace engine{

	class IShaderDrawer;
	class IShaderProgram : public virtual core::IRef
	{
	public:
		virtual void setTransformName(const char *name) = 0;
		virtual unsigned int getUniformIndex(const char *name) = 0;
		virtual unsigned int getVertexArrayIndex(const char *name) = 0;
		virtual IShaderDrawer *createDrawer() = 0;
		
	};
	
};

#endif


