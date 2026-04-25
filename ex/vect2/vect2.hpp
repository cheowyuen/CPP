#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2
{
private:
    int data[2];

public:
    // Constructors
    vect2();
    vect2(int x, int y);
    vect2(const vect2 &other);

    // Assignment
    vect2 &operator=(const vect2 &other);

    // Access
    int &operator[](int index);
    const int &operator[](int index) const;

    // Arithmetic
    vect2 operator+(const vect2 &other) const;
    vect2 operator-(const vect2 &other) const;
    vect2 operator*(int scalar) const;

    vect2 &operator+=(const vect2 &other);
    vect2 &operator-=(const vect2 &other);
    vect2 &operator*=(int scalar);

    // Unary
    vect2 operator-() const;

    // Increment / Decrement
    vect2 &operator++();      // pre
    vect2 operator++(int);   // post
    vect2 &operator--();
    vect2 operator--(int);

    // Comparison
    bool operator==(const vect2 &other) const;
    bool operator!=(const vect2 &other) const;
};

// scalar * vect2
vect2 operator*(int scalar, const vect2 &v);

// output
std::ostream &operator<<(std::ostream &os, const vect2 &v);

#endif