#include "bigint.hpp"
#include <algorithm>
#include <sstream>

bigint::bigint() : digits("0") {}

bigint::bigint(unsigned int n)
{
	std::stringstream ss;
	ss << n;
	this->digits = ss.str();
}

bigint::bigint(const bigint &other)
{
    digits = other.digits;
}
bigint::~bigint() {}

const std::string &bigint::getDigits() const
{
    return digits;
}

bigint &bigint::operator=(const bigint &other)
{
    if (this != &other)
        digits = other.digits;
    return *this;
}

void bigint::normalize()
{
    size_t pos = digits.find_first_not_of('0');
    if (pos == std::string::npos)
        digits = "0";
    else if (pos > 0)
        digits.erase(0, pos);
}

std::string bigint::add_strings(const std::string &a, const std::string &b)
{
    std::string res;
    int carry = 0;

    int i = a.size() - 1;
    int j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;

        if (i >= 0)
            sum += a[i--] - '0';

        if (j >= 0)
            sum += b[j--] - '0';

        res.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    std::reverse(res.begin(), res.end());
    return res;
}

size_t bigint::to_size_t() const
{
    size_t n = 0;

    for (size_t i = 0; i < digits.size(); i++)
        n = n * 10 + (digits[i] - '0');

    return n;
}

bigint bigint::operator+(const bigint &other) const
{
    bigint result;
    result.digits = add_strings(digits, other.digits);
    result.normalize();
    return result;
}

bigint &bigint::operator+=(const bigint &other)
{
    digits = add_strings(digits, other.digits);
    normalize();
    return *this;
}

bigint &bigint::operator++()
{
    *this += bigint(1);
    return *this;
}

bigint bigint::operator++(int)
{
    bigint temp(*this);
    ++(*this);
    return temp;
}

bigint bigint::operator<<(size_t n) const
{
    if (digits == "0")
        return *this;

    bigint result(*this);
    result.digits.append(n, '0');
    return result;
}

bigint &bigint::operator<<=(size_t n)
{
    if (digits != "0")
        digits.append(n, '0');
    return *this;
}

bigint bigint::operator>>(size_t n) const
{
    bigint result(*this);

    if (n >= result.digits.size())
        result.digits = "0";
    else
        result.digits.erase(result.digits.size() - n);

    return result;
}

bigint &bigint::operator>>=(size_t n)
{
    if (n >= digits.size())
        digits = "0";
    else
        digits.erase(digits.size() - n);

    return *this;
}

bigint bigint::operator>>(const bigint &other) const
{
    return (*this) >> other.to_size_t();
}

bigint &bigint::operator>>=(const bigint &other)
{
    return (*this) >>= other.to_size_t();
}

bigint bigint::operator<<(const bigint &other) const
{
    return (*this) << other.to_size_t();
}

bigint &bigint::operator<<=(const bigint &other)
{
    return (*this) <<= other.to_size_t();
}

bool bigint::operator<(const bigint &other) const
{
    if (digits.size() != other.digits.size())
        return digits.size() < other.digits.size();

    return digits < other.digits;
}

bool bigint::operator>(const bigint &other) const
{
    return other < *this;
}

bool bigint::operator<=(const bigint &other) const
{
    return !(*this > other);
}

bool bigint::operator>=(const bigint &other) const
{
    return !(*this < other);
}

bool bigint::operator==(const bigint &other) const
{
    return digits == other.digits;
}

bool bigint::operator!=(const bigint &other) const
{
    return !(*this == other);
}

std::ostream &operator<<(std::ostream &os, const bigint &b)
{
    os << b.getDigits();
    return os;
}