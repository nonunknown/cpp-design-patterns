#include <iostream>
#include <unordered_map>
#include <functional>

#ifndef OBSERVER
#define OBSERVER

namespace DP
{

	class IObserver
	{
		public:
			void update()
			{
				funcref();
			}
			int id;
			void* owner;
			std::function<void()> funcref;
			
	};

	class Observable
	{
		public:
			Observable();
			~Observable();
			void add(IObserver* observer, void* owner);
			void remove(int id);
			void notify();
		
		private:
			std::unordered_map<int, IObserver*> observers;
			int current_id;
	};

}

#endif