#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <string>
#include <iostream>

class bigint {
	private:
		std::string digits;
		
		static std::string addStrings(const std::string& a, const std::string& b);
		void normalize();
		size_t toSizeT() const;

	public:
		bigint();
		bigint(unsigned int n);
		bigint(const bigint& other);
		~bigint();

		const std::string& getDigits() const;

		bigint& operator=(const bigint& other);

		bigint operator+(const bigint& other) const;
		bigint& operator+=(const bigint& other);
		bigint& operator++();
		bigint operator++(int);

		bigint operator<<(size_t n) const;
		bigint operator>>(size_t n) const;
		bigint& operator<<=(size_t n);
		bigint& operator>>=(size_t n);
		bigint operator<<(const bigint& other) const;
		bigint operator>>(const bigint& other) const;
		bigint& operator<<=(const bigint& other);
		bigint& operator>>=(const bigint& other);

		bool operator<(const bigint& other) const;
		bool operator>(const bigint& other) const;
		bool operator<=(const bigint& other) const;
		bool operator>=(const bigint& other) const;
		bool operator==(const bigint& other) const;
		bool operator!=(const bigint& other) const;
};

std::ostream& operator<<(std::ostream& os, const bigint& b);

#endif