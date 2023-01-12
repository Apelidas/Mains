#include "Harl.hpp"

void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string lvl)
{
	void (Harl::*ptr[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string		arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int				i = 0;

	while (i < 4 && arr[i] != lvl)
		i++;
	if (i == 4)
	{
		std::cout << "Sry for Harls limited capabilites, but this command does not exist.\n";
		return ;
	}
	(this->*ptr[i])();
}
