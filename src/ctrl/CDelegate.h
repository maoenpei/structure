#ifndef __BASE_DELEGATE_H__
#define __BASE_DELEGATE_H__

#include "IDelegate.h"
#include "core/CRefObject.h"

namespace ctrl{

	class CDelegate : public core::CRefObject, public virtual IDelegate
	{
	public:
		virtual void onInitialized(view::IPlatform *platform);
		virtual void onReadytoQuit();

		CDelegate();
	};
	
};

#endif

