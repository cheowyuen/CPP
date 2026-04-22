#include "Span.hpp"
#include <iostream>
#include <random>
#include <ctime>
#include <exception>
#include <algorithm>

int main()
{
	Span sp = Span(5);

	sp.addNumber(3);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() <<"\n";
	std::cout << sp.longestSpan() << "\n";

	try {
		sp.addNumber(1);
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
	}

	std::cout << "---- 10000 numbers ----\n";
	Span spLarge = Span(10000);
	std::vector<int> nums(10000);
	for (int i = 0; i < 10000; i++)
		nums[i] = i;
	spLarge.addMultiple(nums.begin(), nums.end());
	std::cout << spLarge.shortestSpan() << "\n";
	std::cout << spLarge.longestSpan() << "\n";

	std::cout << "---- 10 random numbers ----\n";
	Span spRand = Span(10);
	std::vector<int> nums2(10);
	std::srand(std::time(nullptr));
	for (int i = 0; i < 10; i++)  {
		nums2[i] = std::rand() % 100;
		std::cout << nums2[i] << " ";
	}
	std::cout << "\n";
	spRand.addMultiple(nums2.begin(), nums2.end());
	std::cout << spRand.shortestSpan() << "\n";
	std::cout << spRand.longestSpan() << "\n";
	std::cout << "sorted: ";
	std::sort(nums2.begin(), nums2.end());
	for (int i = 0; i < 10; i++)  {
		std::cout << nums2[i] << " ";
	}
	std::cout << "\n";

	std::cout << "---- 0 number ----\n";
	Span spZero= Span(0);
	try {
		std::cout << spZero.shortestSpan() <<"\n";
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
	}
	try {
		std::cout << spZero.longestSpan() << "\n";
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
	}

	std::cout << "---- 1 number ----\n";
	Span spOne = Span(1);
	spOne.addNumber(1);
	try {
		std::cout << spOne.shortestSpan() <<"\n";
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
	}
	try {
		std::cout << spOne.longestSpan() << "\n";
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
	}

	return 0;
}
