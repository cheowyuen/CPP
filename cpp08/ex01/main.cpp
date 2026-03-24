#include "Span.hpp"
#include <iostream>

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span spLarge = Span(10000);
	std::vector<int> nums(10000);
	for (int i = 0; i < 10000; i++)
		nums[i] = i;
	spLarge.addMultiple(nums.begin(), nums.end());
	std::cout << spLarge.shortestSpan() << std::endl;
	std::cout << spLarge.longestSpan() << std::endl;
	return 0;
}
