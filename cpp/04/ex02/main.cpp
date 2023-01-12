#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void test_brain()
{
	Brain a;
	Brain b;
	std::cout << a.get_idea() << std::endl;
	std::cout << a.get_idea() << std::endl;
	std::cout << a.get_idea() << std::endl;
	std::cout << a.get_idea() << std::endl;
	std::cout << a.get_idea() << std::endl;
	std::cout << a.get_idea() << std::endl;
	std::cout << b.get_idea() << std::endl;
}

void test()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;
}

void test_copy()
{
	Cat a;
	{
		Cat b = a;
	}
}

void test_array()
{
	int	amount = 6;
	Animal **array = new Animal*[amount];

	for(int i = 0; i < amount; i++)
	{
		if (i % 2 == 0)
			array[i] = new Cat();
		else
			array[i] = new Dog();
	}
	std::cout << std::endl;

	for(int i = 0; i < amount; i++)
	{
		delete array[i];
	}
}



int main()
{
	test();
	std::cout << std::endl;
	test_brain();
	std::cout << std::endl;
	test_copy();
}