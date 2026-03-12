#ifndef DATA_HPP
#define DATA_HPP

class Data {
	public:
		Data() = default;
		~Data() = default;
		Data(const Data &other) = default;
		Data &operator=(const Data &other) = delete;
};

#endif