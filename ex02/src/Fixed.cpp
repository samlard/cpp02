#include "../include/Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i) : _value(i << _fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float i) : _value(roundf(i * (1 << _fractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_value = other._value;
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
    return (((float)_value ) / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
    return (_value >> _fractionalBits);
}

int Fixed:: getRawBits() const
{
    return (this->_value);
} 

void Fixed:: setRawBits(int const raw)
{
    this->_value = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

bool Fixed::operator>(const Fixed& other) const 
{
    return this->_value > other._value;
}

bool Fixed::operator<(const Fixed& other) const 
{
    return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const 
{
    return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const 
{
    return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const 
{
    return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const 
{
    return this->_value != other._value;
}

Fixed Fixed::operator+(const Fixed& other) const 
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const 
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const 
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const 
{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() 
{
    _value += 1;  
    return *this;
}

Fixed Fixed::operator++(int) 
{
    Fixed temp(*this);
    _value += 1;
    return temp;
}

Fixed& Fixed::operator--() 
{
    _value -= 1;
    return *this;
}

Fixed Fixed::operator--(int) 
{
    Fixed temp(*this);
    _value -= 1;
    return temp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b) 
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) 
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) 
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) 
{
    return (a > b) ? a : b;
}
