#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

AForm* Intern::makeForm(const std::string& name, const std::string& target) const {
	std::string names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (*creators[])(const std::string&) = {createShrubbery, createRobotomy, createPresidential};
	for (int i = 0; i < 3; i++) {
		if (name == names[i]) {
			AForm* form = creators[i](target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return form;
		}
	}
	std::cout << "Form name does not exist" << std::endl;
	return nullptr;
}

AForm* Intern::createShrubbery(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target) {
	return new PresidentialPardonForm(target);
}
