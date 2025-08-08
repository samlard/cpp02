#include "../include/Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "destructor called" << std::endl;
}


Fixed::Fixed(const Fixed& other) : _value(other._value)
{
    std::cout << "copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "copy assignment operator called" << std::endl;
    if (this != &other)
        this->_value = other._value;
    return (*this);
}

int Fixed:: getRawBits() const
{
    return (this->_value);
} 

void Fixed:: setRawBits(int const raw)
{
    this->_value = raw;
}