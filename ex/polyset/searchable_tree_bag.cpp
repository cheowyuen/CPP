#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"

class set {
private:
    searchable_bag *bag;

public:
    set(searchable_bag *b);
    set(const set &other);
    set &operator=(const set &other);
    ~set();

    void insert(int value);
    void remove(int value);
    bool contains(int value) const;
};

#endif