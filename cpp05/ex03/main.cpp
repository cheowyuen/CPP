#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
	Bureaucrat tomNook("TomNook", 1);
	Intern someRandomIntern;
	AForm* form;

	std::cout << "===== Shrubbery Creation =====\n";
	form = someRandomIntern.makeForm("shrubbery creation", "Trees");
	tomNook.signForm(*form);
	tomNook.executeForm(*form);

	std::cout << "\n===== Robotomy Request =====\n";
	form = someRandomIntern.makeForm("robotomy request", "Bender");
	tomNook.signForm(*form);
	tomNook.executeForm(*form);

	std::cout << "\n===== Presidential Pardon =====\n";
	form = someRandomIntern.makeForm("presidential pardon", "Redd");
	tomNook.signForm(*form);
	tomNook.executeForm(*form);

	std::cout << "\n===== Nonexistent =====\n";
	form = someRandomIntern.makeForm("abc", "def");

	return 0;
}
