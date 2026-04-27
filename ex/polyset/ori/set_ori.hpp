#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"

class set {
private:
    searchable_bag *bag_ptr;

public:
    set(searchable_bag &b);
    set(const set &other);
    set &operator=(const set &other);
    ~set();

    void insert(int value);
    void insert(int *array, int size);
    
    bool has(int value) const;
    void print() const;
    void clear();

    searchable_bag &get_bag();
    const searchable_bag &get_bag() const;
};

#endif