#include "Bureaucrat.hpp"

int main() {
	Bureaucrat Default;
	Bureaucrat Cantik("Cantik", 1);
	Bureaucrat Manis("Manis", 150);
	try {
		Bureaucrat Ayu("Ayu", 0);
	} 
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try {
		Bureaucrat Molek("Molek", 151);
	} 
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << Cantik << std::endl;
	std::cout << Manis << std::endl;

	try {
		Cantik.increment();
	} 
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try {
		Manis.decrement();
	} 
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	Cantik.decrement();
	Manis.increment();
	std::cout << Cantik << std::endl;
	std::cout << Manis << std::endl;
}
