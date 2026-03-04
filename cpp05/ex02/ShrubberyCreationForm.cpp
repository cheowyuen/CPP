#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : _target(target) {}

void ShrubberyCreationForm::createFile() {
	std::ofstream outFile(_target);
	if (!outFile.is_open()) {
		std::cout << "Error opening file " + _target + "\n";
		return;
	}
	outFile << R"(
				  \_/
                --(_)--
            .'.   / \
           / . \
          |  |. | ,-'-.
     ,-'-.\ \|  /(  .  )
    /  .  \  |, (  \|   )
   |  .|/  |_|_(    |/   )
    \._|,_/  |  '--.|..-'
 ______|_____|______|______
 credit: Laura Brown
	)";
	return;
}
