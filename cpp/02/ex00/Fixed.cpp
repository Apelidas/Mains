#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "The Default constructor" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed &point)
{
	std::cout << "The copy Constructor" << std::endl;
	*this = point;
}
Fixed::~Fixed()
{
	std::cout << "The Destructor" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits called" << std::endl;
	this->value = raw;
}

Fixed&	Fixed::operator=(Fixed const &point)
{
	std::cout << "Operator Overload" << std::endl;
	this->value = point.getRawBits();
	return (*this);
}

