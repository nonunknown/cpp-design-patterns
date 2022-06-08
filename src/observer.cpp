#include "observer.h"

using namespace DP;

Observable::Observable()
{
	current_id = 0;
	observers.clear();
}

Observable::~Observable()
{

}

void Observable::add(IObserver* observer, void* owner)
{
	observers[current_id] = observer;
	observer->id = current_id;
	observer->owner = owner;
	current_id++;
}

void Observable::remove(int id)
{
	observers.erase(id);
}

void Observable::notify()
{
	for (size_t i = 0; i < observers.size(); i++)
	{
		observers.at(i)->update();
	}
}


