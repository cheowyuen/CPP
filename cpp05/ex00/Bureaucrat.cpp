#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : Bureaucrat("Bureaucrat", 150) {}
		
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}
		
const std::string& Bureaucrat::getName() const {
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
		
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}
		
const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}
		
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	return os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
}
