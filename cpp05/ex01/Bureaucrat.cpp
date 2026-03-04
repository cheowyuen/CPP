#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : Bureaucrat("Bureaucrat", 150) {}
		
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}
		
Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade) {}
		
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other)
		_grade = other._grade;
	return *this;
}
		
const std::string &Bureaucrat::getName() const {
	return _name;
}
		
int Bureaucrat::getGrade() const {
	return _grade;
}
		
void Bureaucrat::decrement() {
	if (_grade >= 150)
		throw GradeTooLowException();
	else
		_grade++;
}
		
void Bureaucrat::increment() {
	if (_grade <= 1)
		throw GradeTooHighException();
	else
		_grade--;
}
		
const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}
		
const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}
		
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	return os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
}

void Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	}
	catch(std::exception &e) {
		std::cout << getName() << " couldn't sign " << form.getName() << " because " 
			<< e.what();
	}
}
