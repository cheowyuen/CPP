#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm  {
	private:
		const std::string _target;

	public:
		RobotomyRequestForm(const std::string &target);
		~RobotomyRequestForm() = default;
		RobotomyRequestForm(const RobotomyRequestForm &other) = default;
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other) = delete; 
		void robotomize();
};

#endif