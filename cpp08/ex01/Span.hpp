#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
	private:
		std::vector<int> _v;
		unsigned int _n;

	public:
		Span() = default;
		Span(unsigned int n);
		~Span() = default;
		Span(const Span& other) = default;
		Span& operator=(const Span& other) = default;
		void addNumber(int num);
		int shortestSpan();
		int longestSpan();
};

#endif