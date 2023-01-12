#ifndef EASY_HPP
#define EASY_HPP

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <list>

class Nope: public std::exception
{
	const char *what() const throw() {return ("That value doesn´t occur in Container");}
};

template<typename T> typename T::iterator easyfind(T cont, int tofind)
{
	typename T::iterator it;
	for (it = cont.begin(); it != cont.end(); it++)
	{
		if (*it == tofind)
			return (it);
	}
	throw(Nope());
	return (it);
}

#endif