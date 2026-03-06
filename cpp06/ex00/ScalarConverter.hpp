#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
	private:
		ScalarConverter() = default;
		~ScalarConverter() = default;
		ScalarConverter(const ScalarConverter &other) = default;
		ScalarConverter &operator=(const ScalarConverter &other) = delete;
		enum inputType {
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			PSEUDO_FLOAT,
			PSEUDO_DOUBLE,
			INVALID,
		};
		static inputType detectType(const std::string& s);
		static void handleChar(char c);
		static void handleInt(int i);
		static void handleFloat(float f);
		static void handleDouble(double d);
		static void handlePseudoFloat(const std::string& s);
		static void handlePseudoDouble(const std::string& s);

	public:
		static void convert(const std::string& s);
};

#endif