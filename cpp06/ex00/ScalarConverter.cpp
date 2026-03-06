#include "ScalarConverter.hpp"
#include <iostream>
#include <climits>

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

void ScalarConverter::handleChar(char c) {
	int i = static_cast<int>(c); 
	double d = static_cast<double>(c);
	float f = static_cast<float>(c);

	if (!isprint(c))
		std::cout << "char: Non displayable\n";
	else 
		std::cout << "char: '" << c << "'\n";
	std::cout << "int: " << i << "\n";
	std::cout << "float: " << f << ".0f\n";
	std::cout << "double: " << d << ".0\n";
}

static void handleInt(int i) {
	char c = static_cast<char>(i);
	double d = static_cast<double>(i);
	float f = static_cast<float>(i);

	std::cout << "char: Non displayable\n";
	if (i > INT_MAX || i < INT_MIN)
		std::cout << "int: Non displayable\n";
	else 
		std::cout << "int: " << i << "\n";
	std::cout << "float: " << f << ".0f\n";
	std::cout << "double: " << d << ".0\n";
}

// static void handleFloat(float f) {
// c = static_cast<char>(f);
// 			i = static_cast<int>(f);
// 			d = static_cast<double>(f);
// }

// static void handleDouble(double d) {
// c = static_cast<char>(d);
// 			i = static_cast<int>(d);
// 			f = static_cast<float>(d);
// }

// static void handlePseudoFloat(const std::string& s) {
// pseudoC = "impossible";
// 			pseudoI = "impossible";
// 			pseudoD = s.substr(0, s.length() - 2);
// 			pseudoF = s;
// }

// static void handlePseudoDouble(const std::string& s) {
// pseudoC = "impossible";
// 			pseudoI = "impossible";
// 			pseudoD = s;
// 			pseudoF = s + "f";
// }

void ScalarConverter::convert(const std::string& s) {
	inputType t = detectType(s);
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
			std::cout << "Invalid input\n";
			return;
	}
}
