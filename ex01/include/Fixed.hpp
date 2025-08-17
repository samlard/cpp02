#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed {
private:
    int _value;
    static const int _fractionalBits = 8;
public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed &other);
    Fixed& operator=(const Fixed& other);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    Fixed(const int i);
    Fixed(const float i);
    float toFloat(void) const;
    int toInt(void) const;
};
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif