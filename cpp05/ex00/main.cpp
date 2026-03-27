#include "Bureaucrat.hpp"

int main() {
	Bureaucrat birokrat;
	Bureaucrat cantik("Cantik", 1);
	Bureaucrat manis("Manis", 150);
	try {
		Bureaucrat ayu("Ayu", 0);
	} 
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
	}
	try {
		Bureaucrat molek("Molek", 151);
	} 
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
	}
	std::cout << birokrat << "\n";
	std::cout << cantik << "\n";
	std::cout << manis << "\n";

	try {
		cantik.increment();
	} 
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
	}
	try {
		manis.decrement();
	} 
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
	}
	cantik.decrement();
	manis.increment();
	std::cout << cantik << "\n";
	std::cout << manis << "\n";
}
