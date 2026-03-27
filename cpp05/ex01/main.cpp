#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
	Form a("A", 1, 1);
	Form b("B", 150, 150);
	try {
		Form c("C", 0, 1);
	} 
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
	}
	try {
		Form d("D", 1, 151);
	} 
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
	}
	std::cout << a << "\n";
	std::cout << b << "\n";

	Bureaucrat cantik("Cantik", 1);
	Bureaucrat manis("Manis", 150);
	manis.signForm(a);
	std::cout << a << "\n";
	cantik.signForm(a);
	std::cout << a << "\n";
	try {
		cantik.signForm(a);
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
	}
}
