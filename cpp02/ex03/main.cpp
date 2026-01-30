#include "Point.hpp"

int main(void) { 
	Point const a = {0,0};
	Point const b = {3,3};
	Point const c = {6,0};
	Point const point1 = {3,1};
	Point const point2 = {3,0};
	Point const point3 = {3,4};

	std::cout << "point1: " << bsp(a, b, c, point1) << std::endl;
	std::cout << "point2: " << bsp(a, b, c, point2) << std::endl;
	std::cout << "point3: " << bsp(a, b, c, point3) << std::endl;
	
	return 0; 
}
