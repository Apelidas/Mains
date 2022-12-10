#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "IMateriasource.hpp"

void testChar()
{
	Cure a;
	Cure *help;
	Character b("Farodin");
	Character c("Nuramon");

	b.equip(a.clone());
	b.use(0, c);
	b.equip(a.clone());
	b.equip(a.clone());
	b.equip(a.clone());
	help = a.clone();
	b.equip(help);
	delete (help);
	help = (Cure *) b.getInv(3);
	b.unequip(3);
	delete(help);
}

void testCopy()
{
	Cure a;
	Character b("Farodin");
	b.equip(a.clone());
	std::cout << std::endl;
	{
		Character c(b);
		c.use(0, b);
		c.use(1, b);
		delete (c.getInv(0));
		c.unequip(0);
	}
	std::cout << std::endl;
	b.use(0, b);
}

void testCure()
{
	Cure a;
	Character b("Ollowain");
	Cure *c;

	a.use(b);
	c = a.clone();

	delete(c);
}

void testIce()
{
	Ice a;
	Character b("Ollowain");
	Ice *c;

	a.use(b);
	c = a.clone();

	delete(c);
}

void testMateriaSource()
{
	MateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}


int main(void)
{
	std::cout << "_______________________________________________________________" << std::endl;
	std::cout << "|Test:Cure                                                     |" << std::endl;
	std::cout << "_______________________________________________________________" << std::endl;
	testCure();
	std::cout << std::endl;
	std::cout << "_______________________________________________________________" << std::endl;
	std::cout << "|Test:Ice                                                      |" << std::endl;
	std::cout << "_______________________________________________________________" << std::endl;
	testIce();
	std::cout << std::endl;
	std::cout << "_______________________________________________________________" << std::endl;
	std::cout << "|Test:Character                                                |" << std::endl;
	std::cout << "_______________________________________________________________" << std::endl;
	testChar();
	std::cout << std::endl;
	std::cout << "_______________________________________________________________" << std::endl;
	std::cout << "|Test:Copy                                                     |" << std::endl;
	std::cout << "_______________________________________________________________" << std::endl;
	testCopy();
	std::cout << std::endl;
	std::cout << "_______________________________________________________________" << std::endl;
	std::cout << "|Test:MateriaSource                                            |" << std::endl;
	std::cout << "_______________________________________________________________" << std::endl;
	testMateriaSource();
}