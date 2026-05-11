#include "RPN.hpp"
#include <sstream>
#include <iostream>
#include <climits>

int RPN::calculate(const std::string& input) {
	std::stringstream ss(input);
	std::string token;
	while (ss >> token) {
		if (token.size() == 1 && isdigit(token[0])) 
			_stack.push(token[0] - '0');
		else if (_stack.size() >= 2 && (token == "+" || token == "-" || token == "*" || token == "/")) {
			long b = _stack.top();
			_stack.pop();
			long a = _stack.top();
			_stack.pop();
			long result = 0;
			if (token == "+")
				result = a + b;
			else if (token == "-") 
				result = a - b;
			else if (token == "*") 
				result = a * b;
			else if (token == "/") {
				if (b == 0) {
					std::cerr << "Error\n";
					return -1;
				}
				result = a / b;
			}

			if (result > INT_MAX || result < INT_MIN) {
                std::cerr << "Error\n";
                return -1;
            }

			_stack.push(result);
		}
		else {
			std::cerr << "Error\n";
			return -1;
		}
	}
	if (_stack.size() != 1) {
		std::cerr << "Error\n";
		return -1;
	}
	std::cout << _stack.top() << "\n";
	return 0;
}
