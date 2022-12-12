#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	int random;

	srand(time(NULL));
	random = rand();
	if (random % 3 == 0)
		return (new A());
	else if (random % 3 == 1)
		return (new B());
	else
		return (new C());
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "It is type A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "It is type B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "It is type C" << std::endl;
}

void identify(Base& p)
{
	Base a;
	try
	{
		a = dynamic_cast<A&>(p);
		std::cout << "It is type A" << std::endl;
	}
	catch(const std::bad_cast &e)
	{
	}
	try
	{
		a = dynamic_cast<B&>(p);
		std::cout << "It is type B" << std::endl;
	}
	catch(const std::bad_cast &e)
	{
	}
	try
	{
		a = dynamic_cast<C&>(p);
		std::cout << "It is type C" << std::endl;
	}
	catch(const std::bad_cast &e)
	{
	}
}

int main()
{
	Base *d	= new A;

	std::cout << "Original Type A" << std::endl;
	identify(d);
	identify(*d);
	delete(d);

	d = new B;
	std::cout << "Original Type B" << std::endl;
	identify(d);
	identify(*d);
	delete(d);

	d = new C;
	std::cout << "Original Type C" << std::endl;
	identify(d);
	identify(*d);
	delete(d);

	d = generate();
	std::cout << "Original Type Random" << std::endl;
	identify(d);
	identify(*d);
	delete(d);
}

