#include "Harl.hpp"

void testhal()
{
	Harl test;

	test.harlfilter("DEBUG");
	std::cout << "__________________________\n";
	test.harlfilter("INFO");
	std::cout << "__________________________\n";
	test.harlfilter("WARNING");
	std::cout << "__________________________\n";
	test.harlfilter("ERROR");
}
void run_input(std::string in)
{
	Harl run;

	run.harlfilter(in);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	run_input(argv[1]);
}