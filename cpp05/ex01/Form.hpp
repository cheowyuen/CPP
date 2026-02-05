#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form {
	private:
		const std::string _name;
		bool _isSigned;
		const int _signGrade;
		const int _execGrade;

	public:
		Form();
		Form(std::string name, int signGrade, int execGrade);
		~Form() = default;
		Form(const Form &other) = default;
		Form &operator=(const Form &other) = delete;
		const std::string &getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;
		void beSigned(const Bureaucrat &bureaucrat);
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif