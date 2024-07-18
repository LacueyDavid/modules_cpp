#include "dynamic_cast.hpp"
#include "iostream"
#include <exception>
#include <cstdlib>
#include <ctime>

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "i'ts a A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "i'ts a B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "i'ts a C\n";
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "i'ts a A\n";
	}
	catch (const std::exception&)
	{}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "i'ts a B\n";
	}
	catch (const std::exception&)
	{}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "i'ts a C\n";
	}
	catch (const std::exception&)
	{}
}

Base * generate(void)
{
	int r = rand() % 3;
	if (r == 0)
		return new A();
	if (r == 1)
		return new B();
	return new C();
}

int main()
{
	Base *base1 = new A();
	Base *base2 = new B();
	Base *base3 = new C();
	A a;
	B b;
	C c;
	identify(base1);
	identify(base2);
	identify(base3);
	identify(a);
	identify(b);
	identify(c);
	srand(time(0));
	for (std::size_t i = 0; i < 10; ++i)
	{
		Base *base = generate();
		identify(base);
		delete base;
	}
	delete base1;
	delete base2;
	delete base3;
}
