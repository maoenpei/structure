#ifndef __BASE_I_SHADER_PROGRAM_H__
#define __BASE_I_SHADER_PROGRAM_H__

#include "core/IRef.h"
#include "core/TAuto.h"

namespace graphics{
	
	class IShaderDrawer;
	class IShaderProgram : public virtual core::IRef
	{
	public:
		virtual void setTransformName(const char *name) = 0;
		virtual unsigned int getUniformIndex(const char *name) = 0;
		virtual unsigned int getAttributeIndex(const char *name) = 0;
		virtual void createDrawer(core::TAuto<IShaderDrawer> &drawer) = 0;
	};
	
};

#endif


