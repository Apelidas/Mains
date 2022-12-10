#include "IMateriasource.hpp"

MateriaSource::MateriaSource()
{
	this->known[0] = NULL;
	this->known[1] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	*this = copy;
}

MateriaSource::~MateriaSource()
{
	if (this->known[0])
		delete (this->known[0]);
	if (this->known[1])
		delete (this->known[1]);
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &copy)
{
	if (copy.known[0])
	{
		this->known[0] = copy.known[0]->clone();
	}
	if (copy.known[1])
	{
		this->known[1] = copy.known[1]->clone();
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *learn)
{
	for (int i = 0; i < 2; i++)
	{
		if (!this->known[i])
		{
			this->known[i] = learn;
			std::cout << "Materia \'" << learn->getType() << "' has been mastered" << std::endl;
			return ;
		}
	}
	std::cout << "Materia \'" << learn->getType() << "' cannot be learned" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 2; i++)
	{
		if (this->known[i] && this->known[i]->getType() == type)
			return (this->known[i]->clone());
	}
	std::cout << "This Materia is unknown" << std::endl;
	return (NULL);
}
