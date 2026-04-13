#include "Serializer.hpp"
#include <iostream>

int main() {
	Data dt = {1, "abc"};
	Data* ptr = &dt;
	uintptr_t raw = Serializer::serialize(ptr);
	Data* restored = Serializer::deserialize(raw);

	std::cout << "Original pointer: " << ptr << "\n";
    std::cout << "Restored pointer: " << restored << "\n";

	if (restored == ptr) {
		std::cout << "Success!\n";
		std::cout << "int: " << restored->i << "\nstring: " << restored->s << ")\n";
	}
	else {
		std::cout << "Failure!\n";
		return 1;
	}
	return 0;
}
