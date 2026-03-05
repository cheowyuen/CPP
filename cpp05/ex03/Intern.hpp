#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern {
	private:
		static AForm* createShrubbery(std::string target);
		static AForm* createRobotomy(std::string target);
		static AForm* createPresidential(std::string target);
		
	public:
		Intern() = default;
		~Intern() = default;
		Intern(const Intern &other) = default;
		Intern &operator=(const Intern &other) = delete; 
		AForm* makeForm(std::string name, std::string target) const;
};

#endif