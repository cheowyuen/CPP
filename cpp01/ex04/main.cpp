#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 4) {
		std::cout << "Invalid number of arguments\n";
		return 1;
	}

	std::string 	filename(argv[1]);
	std::string 	s1(argv[2]);
	std::string 	s2(argv[3]);
	std::ifstream 	inFile(filename);
	std::ofstream 	outFile(filename + ".replace");

	if (s1.empty()) {
		std::cout << "String to replace cannot be empty\n";
		return 1;
	}
	if (!inFile.is_open()) {
		std::cout << "Error opening file " + filename + "\n";
		return 1;
	}
	if (!outFile.is_open()) {
		std::cout << "Error opening file " + filename + ".replace\n";
		return 1;
	}

	std::string	line;
	std::string	newLine;
	while (std::getline(inFile, line)) {
		std::size_t pos = 0;
		bool s1Found = false;
		std::size_t found;
		while ((found = line.find(s1, pos)) != std::string::npos) {
			s1Found = true;
			std::size_t	newPos = found + s1.length();
			newLine += line.substr(pos, found - pos) + s2;
			pos = newPos;
		}
		if (s1Found)
			newLine += line.substr(pos, line.length() - pos);
		else
			newLine = line;
		outFile << newLine << "\n";
		newLine = "";
	}
	
	return 0;
}
