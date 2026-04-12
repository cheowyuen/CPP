#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <exception>
#include <cmath>

void ScalarConverter::convert(const std::string& s) {
    double d;
    char* endPtr;
    if (s.length() == 1 && !std::isdigit(static_cast<unsigned char>(s[0]))) {
        d = static_cast<double>(s[0]);
    } else {
        d = std::strtod(s.c_str(), &endPtr);
        if (endPtr && *endPtr != '\0' && !( *endPtr == 'f' && *(endPtr + 1) == '\0')) {
			std::cout << "Conversion impossible\n";
			return;
        }
    }

	std::cout << "char: ";
	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
		std::cout << "impossible\n";
	else {
		char c = static_cast<char>(d);
		if (!std::isprint(static_cast<unsigned char>(c)))
			std::cout << "Non displayable\n";
		else
			std::cout << "'" << c << "'\n";
	}

	std::cout << "int: ";
	if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<int>::min()
		|| d > std::numeric_limits<int>::max())
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(d) << "\n";

	std::cout << "float: ";
	if (std::isnan(d))
		std::cout << "nanf\n";
	else if (std::isinf(d)) 
		std::cout << (d < 0 ? "-inff" : "+inff") << "\n";
	else if (std::trunc(d) == d)
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f\n";
	else
		std::cout << static_cast<float>(d) << "f\n";
 
	std::cout << "double: ";
	if (std::isnan(d))
		std::cout << "nan\n";
	else if (std::isinf(d)) 
		std::cout << (d < 0 ? "-inf" : "+inf") << "\n";
	else if (std::trunc(d) == d)
		std::cout << std::fixed << std::setprecision(1) << d << "\n";
	else
		std::cout << d << "\n";
}
