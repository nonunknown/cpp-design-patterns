#include <iostream>
#include <string>

#ifndef STRATEGY
#define STRATEGY

namespace DP
{

	class IFlyBehavior
	{
	public:
		virtual void fly() = 0;
	};

	class IQuackBehavior
	{
	public:
		virtual void quack() = 0;
	};

	class IDisplayBehavior
	{
	public:
		virtual void display() = 0;
	};

	class FlyStrategyA : public IFlyBehavior
	{
		public:
			void fly()
			{
				std::cout << "Fly A" << std::endl;
			}
	};

	class FlyStrategyB : public IFlyBehavior
	{
		public:
			void fly()
			{
				std::cout << "Fly B" << std::endl;
			}
	};

	class QuackStrategyA : public IQuackBehavior
	{
		public:
			void quack()
			{
				std::cout << "QUACKA" << std::endl;
			}
	};

	class QuackStrategyB : public IQuackBehavior
	{
		public:
			void quack()
			{
				std::cout << "QUACKOB" << std::endl;
			}
	};

	class DisplayStartegyA : public IDisplayBehavior
	{
		public:
			void display()
			{
				std::cout << "DisplayVisually" << std::endl;
			}
	};

	class DisplayStartegyB : public IDisplayBehavior
	{
		public:
			void display()
			{
				std::cout << "Display as text" << std::endl;
			}
	};

	class Duck
	{
		private:
			IFlyBehavior* fb;
			IDisplayBehavior* db;
			IQuackBehavior* qb;

		public:
			Duck(IFlyBehavior* fb, IDisplayBehavior* db, IQuackBehavior* qb)
			{
				this->fb = fb;
				this->db = db;
				this->qb = qb;
			}
			void fly() { fb->fly(); }
			void quack() { qb->quack(); };
			void display() { db->display(); };

	};

	void executeStrategyPattern()
	{
		std::cout << "Starting Strategy Pattern" << std::endl;
		FlyStrategyA fsa = FlyStrategyA();
		DisplayStartegyA dsa = DisplayStartegyA();
		QuackStrategyA qsa = QuackStrategyA();
		FlyStrategyB fsb = FlyStrategyB();
		DisplayStartegyB dsb = DisplayStartegyB();
		QuackStrategyB qsb = QuackStrategyB();

		Duck duckA = Duck(&fsa, &dsa, &qsa);
		Duck duckB = Duck(&fsb, &dsb, &qsb);
		Duck duckC = Duck(&fsa, &dsb, &qsa);

		std::cout << "duck A:" << std::endl;
		duckA.display();
		duckA.fly();
		duckA.quack();

		std::cout << "duck B:" << std::endl;
		duckB.display();
		duckB.fly();
		duckB.quack();

		std::cout << "duck C:" << std::endl;
		duckC.display();
		duckC.fly();
		duckC.quack();
	}
}

#endif