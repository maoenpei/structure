

#include "CLoopManager.h"

namespace view{

enum {
	RunType_Runnable = 1,
	RunType_IRunnable,
	
};

struct CLoopManager::LoopEntry : public core::CRefObject
{
	unsigned int key; // loop key
	core::TAuto<core::IRef> runnable; // loop item
	float iterm; // loop interval
	float timeleft; // loop time left
	unsigned char runType; // counter
	bool repeat; // is loop repeat
	bool delMark; // is marked to delete
	bool addMark; // is marked to add

	LoopEntry() : key(0), iterm(0), timeleft(0), runType(0), repeat(false), delMark(false), addMark(true) {}
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
	LoopEntry *entry = new LoopEntry();
	entry->runnable = runnable;
	entry->runType = RunType_Runnable;
	return appendEntry(entry);
}

unsigned int CLoopManager::addLoopItem( core::IRunnableInt * irunnable, float dt, bool repeat)
{
	LoopEntry *entry = new LoopEntry();
	entry->runnable = irunnable;
	entry->runType = RunType_IRunnable;
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
					switch(entry->runType){
					case RunType_Runnable:
						entry->runnable.cast<core::IRunnable>()->run();
						break;
					case RunType_IRunnable:
						entry->runnable.cast<core::IRunnableInt>()->run(counter);
						break;
					}
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


