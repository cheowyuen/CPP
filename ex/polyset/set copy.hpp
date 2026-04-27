#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"

class set {
	private:
		searchable_bag *bagPtr;

	public:
		set(searchable_bag& b);
		set(const set& other);
		set& operator=(const set& other);
		~set();

		searchable_bag& get_bag();
		const searchable_bag& get_bag() const;

		void insert(int value);
		void insert(int *array, int size);
		void print() const;
		void clear();
		bool has(int value) const;
};

#endif