#include <iostream>
#include <limits>
#include <cstdlib>

bool edge(std::string input)
{
	int i;
	std::string edge[8] = {"inf", "+inf", "-inf", "nan", "inff", "+inff", "-inff", "nanf"};
	for (i = 0; i < 8; i++)
	{
		if (input == edge[i])
			break;
	}
	if (i < 8)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float:" << input;
		if (i < 4)
			std::cout << "f";
		std::cout << std::endl;
		std::cout << "double:";
		if (i < 4)
			std::cout << input;
		else
			std::cout << input.substr(0, input.size() - 1);
		std::cout << std::endl;
		return (true);
	}
	return (false);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong amount of Arguments" << std::endl;
		return (1);
	} 

	std::string input = argv[1];
	double		help;

	if (edge(input))
		return (1);
	if (input.size() > 1 || isdigit(input[0]))
	{
		char *end;
		help = std::strtod(argv[1], &end);
		if (*end && (*end != 'f' || end[1]))
		{
			std::cout << "Invalid Input" << std::endl;
			return (1);
		}
	}
	else
		help = static_cast<double>(input[0]);
	// ###################-Char Output-###############################
	std::cout << "char: ";
	if (help < 32 || help > 126)
		std::cout << "impossible" << std::endl;
	else
		std::cout << "'" << static_cast<char>(help) << "'" << std::endl;
	// ###################-Int Output-###############################
	std::cout << "int: ";
	if (help < INT_MIN || help > INT_MAX)
		std::cout << "Out of Range" << std::endl;
	else
		std::cout << static_cast<int>(help) << std::endl;
	// ###################-float Output-###############################
	std::cout << "float: " << static_cast<float>(help);
	if (fmod(help, 1.0) > 0)
		std::cout << "f" << std::endl;
	else
		std::cout << ".0f" << std::endl;
	// ###################-double Output-###############################
	std::cout << "double: " << static_cast<float>(help);
	if (fmod(help, 1.0) == 0)
		std::cout << ".0";
	std::cout << std::endl;
}
