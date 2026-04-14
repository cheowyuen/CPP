#include "Span.hpp"
#include <stdexcept>
#include <algorithm>
#include <limits>

Span::Span() : _n(0) {}

Span::Span(unsigned int n) : _n(n) {}

void Span::addNumber(int num) {
	if (_v.size() >= _n)
		throw std::overflow_error("Span is full");
	_v.push_back(num);
}

int Span::longestSpan() {
	if (_v.size() <= 1)
		throw std::logic_error("Not enough elements");
	std::vector<int> temp = _v;
	std::sort(temp.begin(), temp.end());
	return (temp.back() - temp.front());
}

int Span::shortestSpan() {
	if (_v.size() <= 1)
		throw std::logic_error("Not enough elements");
	std::vector<int> temp = _v;
	std::sort(temp.begin(), temp.end());
	int shortest = std::numeric_limits<int>::max();
	for (size_t i = 0; i < temp.size() - 1; i++) {
		int span = temp[i + 1] - temp[i];
		if (span < shortest)
			shortest = span;
	}
	return (shortest);
}

int Span::shortestSpan() {
	if (_v.size() <= 1)
		throw std::logic_error("Not enough elements");
	std::vector<int> temp = _v;
	std::sort(temp.begin(), temp.end());
	int shortest = temp[1] - temp[0];
	for (size_t i = 1; i < temp.size() - 1; i++) {
		int span = temp[i + 1] - temp[i];
		if (span < shortest)
			shortest = span;
	}
	return (shortest);
}
