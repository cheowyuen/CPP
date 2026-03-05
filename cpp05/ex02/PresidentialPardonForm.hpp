#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm  {
	private:
		const std::string _target;

	public:
		PresidentialPardonForm(const std::string &target);
		~PresidentialPardonForm() = default;
		PresidentialPardonForm(const PresidentialPardonForm &other) = default;
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other) = delete; 
		void executeAction() const;
};

#endif