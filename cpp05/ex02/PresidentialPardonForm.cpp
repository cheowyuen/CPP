#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : _target(target) {}

void PresidentialPardonForm::pardon() {
	std::cout << _target << " has been pardoned by Zaphod Beeblerox\n";
}
