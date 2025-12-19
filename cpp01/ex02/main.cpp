#include <string>
#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Address of str: " << &str << "\n";
	std::cout << "Address of stringPTR: " << stringPTR << "\n";
	std::cout << "Address of stringREF: " << &stringREF << "\n";

	std::cout << "Value of str: " << str << "\n";
	std::cout << "Value of stringPTR: " << *stringPTR << "\n";
	std::cout << "Value of stringREF: " << stringREF << "\n";
	
	return 0;
}
