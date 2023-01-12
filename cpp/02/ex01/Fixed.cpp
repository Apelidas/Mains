#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "The Default constructor" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const int in)
{
	std::cout << "The NotDefault Int-constructor" << std::endl;
	this->value = in << this->fract;
}

Fixed::Fixed(const float in)
{
	std::cout << "The NotDefault Int-constructor" << std::endl;
	this->value = in * (1 << this->fract );
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

float Fixed::toFloat( void ) const
{
	return (this->value / roundf(1 << this->fract));
}

int Fixed::toInt( void ) const
{
	return (this->value >> this->fract);
}

std::ostream& operator<<(std::ostream &out, Fixed const &input)
{
	out << input.toFloat();
	return (out);
}
