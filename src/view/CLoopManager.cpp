

#include "CLoopManager.h"

namespace view{

struct CLoopManager::LoopEntry : public core::CRefObject
{
	unsigned int key; // loop key
	core::TAuto<core::IRef> runnable; // loop item
	float iterm; // loop interval
	float timeleft; // loop time left
	bool repeat; // is loop repeat
	bool delMark; // is marked to delete
	bool addMark; // is marked to add

	LoopEntry(core::IRef *_runnable) : runnable(_runnable), key(0), iterm(0), timeleft(0), repeat(false), delMark(false), addMark(true) {}
	virtual void run(int v1){}
};

struct CLoopManager::LoopEntryNone : public CLoopManager::LoopEntry
{
	core::IRunnable *nRun;
	virtual void run(int v1){
		nRun->run();
	}
	LoopEntryNone(core::IRunnable *_run) : LoopEntry(_run), nRun(_run){}
};

struct CLoopManager::LoopEntryInt : public CLoopManager::LoopEntry
{
	core::IRunnableInt *nRun;
	virtual void run(int v1){
		nRun->run(v1);
	}
	LoopEntryInt(core::IRunnableInt *_run): LoopEntry(_run), nRun(_run){}
};

CLoopManager::CLoopManager()
	: lastMilli(0)
{}

unsigned int CLoopManager::appendEntry(LoopEntry * entry)
{
	static unsigned int baseKey = 1;
	unsigned int key = baseKey++;
	entry->key = key;
	MapDatas[key] = entry;
	ListDatas.push_back(entry);
	return key;
}

unsigned int CLoopManager::addLoopItem( core::IRunnable * runnable)
{
	LoopEntry *entry = new LoopEntryNone(runnable);
	return appendEntry(entry);
}

unsigned int CLoopManager::addLoopItem( core::IRunnableInt * irunnable, float dt, bool repeat)
{
	LoopEntry *entry = new LoopEntryInt(irunnable);
	entry->iterm = (dt < 0 ? 0 : dt);
	entry->repeat = repeat;
	return appendEntry(entry);
}

void CLoopManager::removeLoopKey(unsigned int key)
{
	LoopMap::iterator it = MapDatas.find(key);
	if (it != MapDatas.end()){
		it->second->delMark = true;
		MapDatas.erase(it);
	}
}

void CLoopManager::doLoop(int milliKey)
{
	lastMilli = (lastMilli == 0 ? milliKey : lastMilli);
	float dt = (milliKey - lastMilli) / 1000.0f;
	lastMilli = milliKey;

	LoopList::iterator it;
	for (it = ListDatas.begin(); it != ListDatas.end(); it++){
		(*it)->addMark = false;
	}

	int counter;
	for (it = ListDatas.begin(); it != ListDatas.end(); it++){
		LoopEntry *entry = (*it);
		if (! entry->addMark){
			entry->timeleft -= dt;
			if (entry->timeleft <= 0){
				if (entry->iterm == 0){
					counter = 1;
					entry->timeleft = 0;
				}else{
					counter = (int)((-entry->timeleft) / entry->iterm) + 1;
					entry->timeleft += entry->iterm * counter;
				}
				if (entry->runnable){
					entry->run(counter);
				}
				if (! entry->repeat){
					removeLoopKey(entry->key);
				}
			}
		}
	}

	for (it = ListDatas.begin(); it != ListDatas.end();){
		LoopEntry *entry = (*it);
		if (entry->delMark){
			it = ListDatas.erase(it);
		}else{
			it++;
		}
	}
	
}

};


