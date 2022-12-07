#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string *ideas;
	
	public:
		Brain();
		~Brain();
		std::string get_idea();
};

#endif