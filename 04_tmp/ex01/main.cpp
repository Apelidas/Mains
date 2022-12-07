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

void test_Dat()
{
	Animal *array = new Animal[2];
	array[0] = Dog();
	array[1] = Cat();

	
}



int main()
{
	test();
	std::cout << std::endl;
	test_brain();
}