#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
	Form a("A", 1, 1);
	Form b("B", 75, 75);
	try {
		Form c("C", 0, 1);
	} 
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try {
		Form d("D", 1, 151);
	} 
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	Bureaucrat cantik("Cantik", 1);
	Bureaucrat manis("Manis", 150);
	manis.signForm(a);
	std::cout << a << std::endl;
	cantik.signForm(b);
	std::cout << b << std::endl;
}
