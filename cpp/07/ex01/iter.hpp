#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T> void iter(T *array, unsigned int n, void (*f)(T))
{
	for (unsigned int i = 0; i < n; i++)
	{
		f(array[i]);
	}
}

template<typename T> void printer(T in)
{
	std::cout << in << std::endl;
}



#endif