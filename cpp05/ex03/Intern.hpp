#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern {
	private:
		static AForm* createShrubbery(const std::string& target);
		static AForm* createRobotomy(const std::string& target);
		static AForm* createPresidential(const std::string& target);
		
	public:
		Intern() = default;
		~Intern() = default;
		Intern(const Intern &other) = default;
		Intern& operator=(const Intern& other) = default; 
		AForm* makeForm(const std::string& name, const std::string& target) const;
};

#endif