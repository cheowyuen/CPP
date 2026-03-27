#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : AForm("Default", 1, 1) {}

AForm::AForm(const std::string& name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade)
, _execGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

const std::string& AForm::getName() const {
	return _name;
}
		
bool AForm::getIsSigned() const {
	return _isSigned;
}
		
int AForm::getSignGrade() const {
	return _signGrade;
}
		
int AForm::getExecGrade() const {
	return _execGrade;
}
		
void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (_isSigned)
		throw FormSigned();
	if (bureaucrat.getGrade() <= _signGrade)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const noexcept {
	return "grade too high";
}
		
const char* AForm::GradeTooLowException::what() const noexcept {
	return "grade too low";
}

const char* AForm::FormSigned::what() const noexcept {
	return "form is already signed";
}

const char* AForm::FormNotSigned::what() const noexcept {
	return "form is not signed";
}
		
std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << form.getName() << ", is signed " << form.getIsSigned() << ", sign grade " << form.getSignGrade() 
		<< ", exec grade " << form.getExecGrade();
	return os;
}

void AForm::execute(Bureaucrat const& executor) const {
	if (!_isSigned)
		throw FormNotSigned();
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
	executeAction();
}
