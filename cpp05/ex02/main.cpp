#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main() {
	Bureaucrat tomNook("TomNook", 6);
	Bureaucrat wisp("Wisp", 26);
	Bureaucrat daisyMae("DaisyMae", 46);
	Bureaucrat timmy("Timmy", 73);
	Bureaucrat tommy("Tommy", 138);
	Bureaucrat isabelle("Isabelle", 146);
	
	ShrubberyCreationForm shrubForm("Trees");
	RobotomyRequestForm robotomyForm("Gulliver");
	PresidentialPardonForm pardonForm("Redd");

	std::cout << "===== Shrubbery Creation =====\n";
	tomNook.executeForm(shrubForm);
	isabelle.signForm(shrubForm);
	isabelle.increment();
	isabelle.signForm(shrubForm);
	tommy.executeForm(shrubForm);
	tommy.increment();
	tommy.executeForm(shrubForm);

	std::cout << "\n===== Robotomy Request =====\n";
	tomNook.executeForm(robotomyForm);
	timmy.signForm(robotomyForm);
	timmy.increment();
	timmy.signForm(robotomyForm);
	daisyMae.executeForm(robotomyForm);
	daisyMae.increment();
	daisyMae.executeForm(robotomyForm);

	std::cout << "\n===== Presidential Pardon =====\n";
	tomNook.executeForm(pardonForm);
	wisp.signForm(pardonForm);
	wisp.increment();
	wisp.signForm(pardonForm);
	tomNook.executeForm(pardonForm);
	tomNook.increment();
	tomNook.executeForm(pardonForm);
	
	return 0;
}
