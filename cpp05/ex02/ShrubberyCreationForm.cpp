#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() : 
	AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : 
	AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

void ShrubberyCreationForm::executeAction() const {
	std::ofstream outFile(_target + "_shrubbery");
	if (!outFile.is_open()) {
		std::cout << "Error opening file " + _target + "_shrubbery" << std::endl;
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
}
