#include "Point.hpp"
#include <iostream>

int main(void) { 
	Point const a = {0,0};
	Point const b = {3,3};
	Point const c = {6,0};
	Point const point = {3,2};

	if (bsp(a, b, c, point))
		std::cout << "Point is inside triangle\n";
	else
		std::cout << "Point is outside triangle\n";
	
	return 0; 
}
