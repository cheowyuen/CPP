#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : Form("Default", 1, 1) {}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade)
, _execGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

const std::string &Form::getName() const {
	return _name;
}
		
bool Form::getIsSigned() const {
	return _isSigned;
}
		
int Form::getSignGrade() const {
	return _signGrade;
}
		
int Form::getExecGrade() const {
	return _execGrade;
}
		
void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= _signGrade)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade too high";
}
		
const char *Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
}
		
std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << form.getName() << ", is signed " << form.getIsSigned() << ", sign grade " << form.getSignGrade() 
		<< ", exec grade " << form.getExecGrade();
	return os;
}
