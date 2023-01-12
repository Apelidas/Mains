#ifndef IMATERIA_HPP
#define IMATERIA_HPP

#include "AMateria.hpp"

class AMateria;

class MateriaSource
{
	private:
		AMateria *known[2];

	public:
	MateriaSource();
	MateriaSource(const MateriaSource &copy);
	virtual MateriaSource	&operator=(const MateriaSource &copy);
	virtual ~MateriaSource();
	virtual void learnMateria(AMateria *learn);
	virtual AMateria* createMateria(std::string const & type);
};

#endif