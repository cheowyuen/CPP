#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid number of arguments\n";
		return 1;
	}

	Harl h;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int index = -1;
	for (int i = 0; i < 4; i++) {
		if (levels[i] == argv[1]) {
			index = i;
			break ;
		}
	}

	switch (index) {
		case 0:
			std::cout << "[ DEBUG ]\n";
			h.complain("DEBUG");
			std::cout << "\n";
		case 1:
			std::cout << "[ DEBUG ]\n";
			h.complain("INFO");
			std::cout << "\n";
		case 2:
			std::cout << "[ WARNING ]\n";
			h.complain("WARNING");
			std::cout << "\n";
		case 3:
			std::cout << "[ ERROR ]\n";
			h.complain("ERROR");
			std::cout << "\n";
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}

	return 0;
}
