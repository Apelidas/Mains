#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void test()
{
	Animal* meta = new Animal();
	Animal* j = new Dog();
	Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete(meta);
	delete(j);
	delete(i);
}

void test_negative()
{
	WrongAnimal* a = new WrongAnimal();
	WrongAnimal* b = new WrongCat();

	std::cout << a->getType() << " " << std::endl;
	std::cout << b->getType() << " " << std::endl;
	a->makeSound();
	b->makeSound();

	delete(a);
	delete(b);

}

int main()
{
	test();
	std::cout << std::endl;
	test_negative();
}