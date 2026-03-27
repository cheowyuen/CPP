#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>

class RPN {
	private:
		std::stack<int> _stack;

	public:
		RPN() = default;
		~RPN() = default;
		RPN(const RPN& other) = default;
		RPN& operator=(const RPN& other) = default;

		int calculate(const std::string& input);
};

#endif