#include "Harl.hpp"

void test()
{
	Harl karen;

	karen.complain("DEBUG");
	karen.complain("debug");
	karen.complain("INFO");
	karen.complain("info");
	karen.complain("WARNING");
	karen.complain("warning");
	karen.complain("ERROR");
	karen.complain("error");
	karen.complain("DAFUQ");
}


int main()
{
	test();
}