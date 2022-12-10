#include "Character.hpp"

Character::Character()
{
	this->name = "Character";
	for (int i = 0; i < 4;i++)
	{
		this->inventory[i] = NULL;
	}
	//std::cout << "Character Default Constructor" << std::endl;
}

Character::Character(std::string name)
{
	this->name = name;
	for (int i = 0; i < 4;i++)
	{
		this->inventory[i] = NULL;
	}
	//std::cout << "Character Constructor" << std::endl;
}

Character::Character(Character const &copy): ICharacter(copy)
{
	*this = copy;
}


Character::~Character()
{
	int i = 0;
	while (i < 4 && this->inventory[i])
	{
		delete(this->inventory[i]);
		i++;
	}
	//std::cout << "Character Destructor" << std::endl;
}

std::string const & Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	int i;

	for (i = 0; i < 4;i++)
	{
		if (this->inventory[i] == NULL)
			break;
	}
	if (i == 4)
	{
		std::cout << "You cannot equip this much" << std::endl;
		return ;
	}
	this->inventory[i] = m;
	std::cout << "The Materia " << m->getType() << " has been equipped in Slot " << (i + 1) << "/4" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx > 3)
	{
		std::cout << "Your Pouch isnt that Big" << std::endl;
		return ;
	}
	if (this->inventory[idx] == NULL)
		std::cout << "There is nothing in your Pocket" << std::endl;
	else
	{
		this->inventory[idx] = NULL;
		std::cout << "You threw away your Materia" << std::endl;
	}
}
void Character::use(int idx, ICharacter& target)
{
	if (idx > 3)
	{
		std::cout << "Your Pouch isnt that Big" << std::endl;
		return ;
	}
	if (this->inventory[idx])
	{
		std::cout << this->getName() << ":";
		this->inventory[idx]->use(target);
	}
	else
		std::cout << this->getName() << ": Forgot to bring their Weapon" << std::endl;
}

AMateria* Character::getInv(int idx) const
{
	if (idx > 3)
	{
		std::cout << "Your Pouch isnt that Big" << std::endl;
		return (NULL);
	}
	return (this->inventory[idx]);
}

Character &Character::operator=(Character const &copy)
{
	this->name = copy.getName();
	for(int i = 0; i < 4; i++)
	{
		if (copy.getInv(i))
		{
			this->inventory[i] = copy.getInv(i)->clone();
		}
		else
			this->inventory[i] = NULL;
	}
	return (*this);
}
