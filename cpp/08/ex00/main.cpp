#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	std::list<int> lst;

	for(int i = 0; i < 10;i++)
	{
		vec.push_back(i);
		lst.push_back(i);
	}
	std::cout << "Trying to find all the Numbers + 1 in vector" << std::endl;
	for(int i = 0; i < 11 ; i++)
	{
		try
		{
			std::cout << *(easyfind(vec, i)) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << "Trying to find all the Numbers + 1 in list" << std::endl;
	for(int i = 0; i < 11 ; i++)
	{
		try
		{
			std::cout << *(easyfind(lst, i)) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}