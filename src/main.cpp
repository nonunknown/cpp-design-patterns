#include <iostream>
// #include "strategy.h"
#include "observer.h"

using namespace DP;

void execObserver()
{
	class Weather
	{
		public:
			Observable observable;
			Weather()
			{
				observable = Observable();
			}

			void temperatureChanged()
			{
				observable.notify();
			}

			int getTemperature()
			{
				return 43;
			}
	};

	class Phone
	{
		public:
			IObserver observer;
			void test()
			{
				Weather* weather = (Weather*)observer.owner;
				std::cout << "Temperature is: " << weather->getTemperature() << std::endl;
			}
			Phone()
			{
				observer = IObserver();
				observer.funcref = [this](){
					test();
				};
			}
	};

	Weather weather = Weather();
	Phone phone = Phone();
	weather.observable.add(&phone.observer, &weather);
	weather.temperatureChanged();
	

}

int main() {
	execObserver();
	return 0;
}