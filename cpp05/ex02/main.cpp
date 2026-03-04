#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main() {
	ShrubberyCreationForm shrubForm("Trees");
	shrubForm.createFile();

	RobotomyRequestForm robotomyForm("Tom Nook");
	robotomyForm.robotomize();

	PresidentialPardonForm pardonForm("Isabelle");
	pardonForm.pardon();

	return 0;
}
