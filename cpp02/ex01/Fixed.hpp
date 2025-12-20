#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
	private:
		int	_value;
		static const int _bits = 8;

	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		friend std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		int toInt(void);
		float toFloat(void) const;
};

#endif
