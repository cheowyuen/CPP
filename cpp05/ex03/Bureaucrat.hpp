#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		~Bureaucrat() = default;
		Bureaucrat(const Bureaucrat& other) = default;
		Bureaucrat& operator=(const Bureaucrat& other) = delete;
		const std::string& getName() const;
		int getGrade() const;
		void decrement();
		void increment();
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const noexcept;
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const noexcept;
		};
		void signForm(AForm& form);
		void executeForm(AForm const& form) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
