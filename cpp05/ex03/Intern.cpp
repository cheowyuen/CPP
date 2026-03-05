#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

AForm* Intern::makeForm(std::string name, std::string target) const {
	std::string names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (*creators[])(std::string) = {createShrubbery, createRobotomy, createPresidential};
	for (int i = 0; i < 3; i++) {
		if (name == names[i]) {
			std::cout << "Intern creates " << name << "\n";
			return creators[i](target);
		}
	}
	std::cout << "Form name does not exist\n";
	return nullptr;
}

AForm* Intern::createShrubbery(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(std::string target) {
	return new PresidentialPardonForm(target);
}
