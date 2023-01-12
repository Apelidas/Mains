#include <iostream>
#include <fstream>

void	reading(std::ifstream &file, std::ofstream &out, std::string replace, std::string with)
{
	std::string	red;
	std::string	buffer;
	size_t		pos;

	while (std::getline(file, red))
	{
		buffer.append(red);
		buffer.append("\n");
	}
	if (!replace.empty())
	{
		pos = buffer.find(replace);
		while (pos != std::string::npos)
		{
			buffer.erase(pos, replace.length());
			buffer.insert(pos, with);
			pos = buffer.find(replace);
		}
	}
	out << buffer;
}

int main(int argc, char **argv)
{
	if (argc != 4)
		return (1);

	std::string		help = argv[1];
	std::ifstream	file(argv[1]);
	std::ofstream	out(help + ".replace");

	if (!file || !out)
	{
		std::cout << "Could not open files\n";
		return (1);
	}
	reading(file, out, argv[2], argv[3]);
	file.close();
	out.close();
}