
#include <iostream>

std::string mytoupper(std::string in)
{
	int	i;

	i = 0;
	while (in[i])
	{
		in[i] = std::toupper(in[i]);
		i++;
	}
	return (in);
}

int main(int argc, char **argv)
{
	int	i;
	
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	i = 1;
	while (argv[i])
	{
		
		std::cout << mytoupper(argv[i]);
		i++;
	}
	std::cout << std::endl;
	return (1);
}