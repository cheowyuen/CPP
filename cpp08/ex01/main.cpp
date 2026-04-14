#include "Span.hpp"
#include <iostream>
#include <random>

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() <<"\n";
	std::cout << sp.longestSpan() << "\n";

	sp.addNumber(1);

	std::cout << "---- 10000 numbers ----\n";
	Span spLarge = Span(10000);
	std::vector<int> nums(10000);
	for (int i = 0; i < 10000; i++)
		nums[i] = i;
	spLarge.addMultiple(nums.begin(), nums.end());
	std::cout << spLarge.shortestSpan() << "\n";
	std::cout << spLarge.longestSpan() << "\n";

	std::cout << "---- 10000 random numbers ----\n";
	Span spRand = Span(10000);
	std::vector<int> nums(10000);
	for (int i = 0; i < 10000; i++)
		nums[i] = std::rand();
	spRand.addMultiple(nums.begin(), nums.end());
	std::sort(nums.begin(), nums.end());
	std::cout << "Smallest: " << nums.front() << "\nLargest: " << nums.back() << "\n";
	std::cout << spRand.shortestSpan() << "\n";
	std::cout << spRand.longestSpan() << "\n";

	std::cout << "---- 1 number ----\n";
	Span spOne = Span(1);
	spOne.addNumber(1);
	std::cout << spOne.shortestSpan() <<"\n";
	std::cout << spOne.longestSpan() << "\n";

	return 0;
}
