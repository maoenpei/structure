#ifndef __BASE_LOOP_MANAGER_H__
#define __BASE_LOOP_MANAGER_H__

#include "ILoopManager.h"
#include "core/CRefObject.h"
#include "core/TAuto.h"
#include <map>
#include <list>

namespace view{

	class CLoopManager : public core::CRefObject, public virtual ILoopManager
	{
	public:
		virtual unsigned int addLoopItem(core::IRunnable *runnable);
		virtual unsigned int addLoopItem(core::IRunnableInt *irunnable, float dt, bool repeat);
		virtual void removeLoopKey(unsigned int key);

		void doLoop(int milliKey);
		CLoopManager();

	private:
		int lastMilli;
		
		struct LoopEntry;
		struct LoopEntryNone;
		struct LoopEntryInt;
		typedef std::map<unsigned int, core::TAuto<LoopEntry> > LoopMap;
		typedef std::list<core::TAuto<LoopEntry> > LoopList;
		LoopMap MapDatas;
		LoopList ListDatas;
		unsigned int appendEntry(LoopEntry *entry);
	};
	
};

#endif

