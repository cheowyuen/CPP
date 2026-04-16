#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() : 
	AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : 
	AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

const char* ShrubberyCreationForm::FileOpenException::what() const noexcept {
	return "could not open file";
}

void ShrubberyCreationForm::executeAction() const {
	std::ofstream outFile;
	outFile.open(_target + "_shrubbery");
	if (!outFile) {
		throw FileOpenException();
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

