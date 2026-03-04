#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
	Form Default;
	Form A("A", 1, 1);
	Form B("B", 75, 75);
	try {
		Form C("C", 0, 1);
	} 
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try {
		Form D("D", 1, 151);
	} 
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << A << std::endl;
	std::cout << B << std::endl;

	Bureaucrat Cantik("Cantik", 1);
	Bureaucrat Manis("Manis", 150);
	Manis.signForm(A);
	std::cout << A << std::endl;
	Cantik.signForm(B);
	std::cout << B << std::endl;
}
