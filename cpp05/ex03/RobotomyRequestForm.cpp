#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <random>

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
	AForm("RobotomyRequestForm", 72, 45), _target(target) {}

void RobotomyRequestForm::executeAction() const {
	std::cout << "Drilling noises\n";
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, 1);
	int randomValue = dist(gen);
	if (randomValue == 0)
		std::cout << "Robotomy failed\n";
	else
		std::cout << _target << " has been robotomized successfully\n";
}
