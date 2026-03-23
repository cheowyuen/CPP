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
	std::sort(_v.begin(), _v.end());
	return (_v.back() - _v[0]);
}

int Span::shortestSpan() {
	int shortest = std::numeric_limits<int>::max();
	if (_v.size() <= 1)
		throw std::logic_error("Not enough elements");
	std::sort(_v.begin(), _v.end());
	for (size_t i = 0; i < _v.size() - 1; i++) {
		int span = _v[i + 1] - _v[i];
		if (span < shortest)
			shortest = span;
	}
	return (shortest);
}

