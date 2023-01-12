#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
class Harl
{
	private:
		void debug();
		void info();
		void warning();
		void error();

	public:
		void complain(std::string lvl);
		void harlfilter(std::string lvl);
};

#endif