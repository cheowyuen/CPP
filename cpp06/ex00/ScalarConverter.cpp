#include "ScalarConverter.hpp"
#include <iostream>
#include <climits>
#include <iomanip>
#include <limits>

ScalarConverter::inputType ScalarConverter::detectType(const std::string& s) {
	if (s == "nanf" || s == "+inff" || s == "-inff") 
		return PSEUDO_FLOAT;
	if (s == "nan" || s == "+inf" || s == "-inf") 
		return PSEUDO_DOUBLE;

	size_t i = 0;
	if (s.length() == 1 && !std::isdigit(s[i])) {
		return CHAR;
	}
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (i == s.length())
		return INVALID;
	while (i < s.length() && std::isdigit(s[i]))
		i++;
	if (i == s.length())
		return INT;
	if (s[i] == '.')
		i++;
	if (i == s.length())
		return INVALID;
	while (i < s.length() && std::isdigit(s[i]))
		i++;
	if (i < s.length() && s[i] == 'f' && i == s.length() - 1)
		return FLOAT;
	if (i == s.length())
		return DOUBLE;
	return INVALID;
}

void printConversion(char c, int i, float f, double d) {
	if (i < 0 || i > 127 || !isprint(static_cast<unsigned char>(i)))
		std::cout << "char: Non displayable\n";
	else 
		std::cout << "char: '" << c << "'\n";
	if (d > static_cast<double>(INT_MAX) || d < static_cast<double>(INT_MIN))
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << i << "\n";
	std::cout << std::fixed << std::setprecision(1);
	if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max())
    	std::cout << "float: impossible\n";
	else
		std::cout << "float: " << f << "f\n";
	std::cout << "double: " << d << "\n";
}

void ScalarConverter::handleChar(char c) {
	int i = static_cast<int>(c); 
	double d = static_cast<double>(c);
	float f = static_cast<float>(c);
	printConversion(c, i, f, d);
}

void ScalarConverter::handleInt(int i) {
	char c = static_cast<char>(i);
	double d = static_cast<double>(i);
	float f = static_cast<float>(i);
	printConversion(c, i, f, d);
}

void  ScalarConverter::handleFloat(float f) {
	char c = static_cast<char>(f);
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);
	printConversion(c, i, f, d);
}

void  ScalarConverter::handleDouble(double d) {
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);
	printConversion(c, i, f, d);
}

void ScalarConverter::handlePseudoFloat(const std::string& s) {
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: " << s << "\n";
	std::cout << "double: " << s.substr(0, s.length() - 1) << "\n";
}

void ScalarConverter::handlePseudoDouble(const std::string& s) {
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: " << s << "f\n";
	std::cout << "double: " << s << "\n";
}

void ScalarConverter::convert(const std::string& s) {
	inputType t = detectType(s);
	try {
		switch (t) {
			case CHAR:
				handleChar(s[0]);
				break;
			case INT:
				handleInt(std::stoi(s));
				break;
			case FLOAT:
				handleFloat(std::stof(s));
				break;
			case DOUBLE:
				handleDouble(std::stod(s));
				break;
			case PSEUDO_FLOAT:
				handlePseudoFloat(s);
				break;
			case PSEUDO_DOUBLE:
				handlePseudoDouble(s);
				break;
			default:
				std::cout << "Conversion impossible\n";
				return;
		}
	}
	catch (const std::exception& e) {
		std::cout << "Conversion impossible\n";
	}
}
