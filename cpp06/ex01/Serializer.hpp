#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
#include "Data.hpp"

class Serializer {
	private:
		Serializer() = default;
		~Serializer() = default;
		Serializer(const Serializer &other) = default;
		Serializer &operator=(const Serializer &other) = delete;

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif