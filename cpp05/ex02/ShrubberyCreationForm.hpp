#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {
	private:
		const std::string _target;

	public:
		ShrubberyCreationForm(const std::string &target);
		~ShrubberyCreationForm() = default;
		ShrubberyCreationForm(const ShrubberyCreationForm &other) = default;
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other) = delete; 
		void createFile();
};

#endif