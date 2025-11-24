#include <iostream>
#include <cctype>
#include <string>

int	main(int argc, char **argv)
{
	int			i;
	std::string	str;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	for (i = 1; i < argc; i++)
	{
		str = argv[i];
		for (char c : str)
			std::cout << (char)std::toupper(c);
	}
	std::cout << std::endl;
	return (0);
}
