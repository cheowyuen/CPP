#include "Serializer.hpp"
#include <iostream>

int main() {
	Data myData;
	Data* original = &myData;
	uintptr_t raw = Serializer::serialize(original);
	Data* restored = Serializer::deserialize(raw);

	std::cout << "Original pointer: " << original << "\n";
    std::cout << "Restored pointer: " << restored << "\n";

	if (restored == original)
		std::cout << "Success!\n";
	else
		std::cout << "Failure!\n";
}
