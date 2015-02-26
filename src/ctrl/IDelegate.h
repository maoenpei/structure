#ifndef __BASE_I_DELEGATE_H__
#define __BASE_I_DELEGATE_H__

#include "core/IRef.h"
#include "view/IPlatform.h"

namespace ctrl{

	class IDelegate : public virtual core::IRef
	{
	public:
		virtual void onInitialized(view::IPlatform *platform) = 0;
		virtual void onReadytoQuit() = 0;
	};
	
};

#define DELEGATE_NAME		"::DelegateInstance"

#endif

