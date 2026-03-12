#ifndef BASE_HPP
#define BASE_HPP

class Base {
	public:
		Base() = default;
		virtual ~Base() = default;
		Base(const Base &other) = default;
		Base &operator=(const Base &other) = delete;
};

#endif