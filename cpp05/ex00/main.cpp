#include "Bureaucrat.hpp"

int main() {
	Bureaucrat birokrat;
	Bureaucrat cantik("Cantik", 1);
	Bureaucrat manis("Manis", 150);
	try {
		Bureaucrat ayu("Ayu", 0);
	} 
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try {
		Bureaucrat molek("Molek", 151);
	} 
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << birokrat << std::endl;
	std::cout << cantik << std::endl;
	std::cout << manis << std::endl;

	try {
		cantik.increment();
	} 
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try {
		manis.decrement();
	} 
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	cantik.decrement();
	manis.increment();
	std::cout << cantik << std::endl;
	std::cout << manis << std::endl;
}
