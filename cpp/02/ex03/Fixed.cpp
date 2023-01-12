#include "Fixed.hpp"

Fixed::Fixed()
{
	//std::cout << "The Default constructor" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const int in)
{
	//std::cout << "The NotDefault Int-constructor" << std::endl;
	this->value = in << this->fract;
}

Fixed::Fixed(const float in)
{
	//std::cout << "The NotDefault Int-constructor" << std::endl;
	this->value = in * (1 << this->fract );
}

Fixed::Fixed(const Fixed &point)
{
	//std::cout << "The copy Constructor" << std::endl;
	*this = point;
}
Fixed::~Fixed()
{
	//std::cout << "The Destructor" << std::endl;
}

int Fixed::getRawBits() const
{
	//std::cout << "getRawBits called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits called" << std::endl;
	this->value = raw;
}

Fixed&	Fixed::operator=(Fixed const &point)
{
	//std::cout << "Operator Overload" << std::endl;
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

bool Fixed::operator>(Fixed &input) const
{
	if (this->toFloat() > input.toFloat())
		return (true);
	else
		return (false);
}

bool Fixed::operator<(Fixed &input) const
{
	if (this->toFloat() < input.toFloat())
		return (true);
	else
		return (false);
}

bool Fixed::operator>=(Fixed &input) const
{
	if (this->toFloat() >= input.toFloat())
		return (true);
	else
		return (false);
}

bool Fixed::operator<=(Fixed &input) const
{
	if (this->toFloat() <= input.toFloat())
		return (true);
	else
		return (false);
}

bool Fixed::operator==(Fixed &input) const
{
	if (this->toFloat() == input.toFloat())
		return (true);
	else
		return (false);
}

bool Fixed::operator!=(Fixed &input) const
{
	if (this->toFloat() != input.toFloat())
		return (true);
	else
		return (false);
}

Fixed Fixed::operator+(Fixed const &input) const
{
	Fixed out;
	out.setRawBits(this->getRawBits() + input.getRawBits());
	return (out);
}

Fixed Fixed::operator-(Fixed const &input) const
{
	Fixed out;
	out.setRawBits(this->getRawBits() - input.getRawBits());
	return (out);
}

Fixed Fixed::operator*(Fixed const &input) const
{
	Fixed out(this->toFloat() * input.toFloat());
	return (out);
}

Fixed Fixed::operator/(Fixed const &input) const
{
	Fixed out(this->toFloat() / input.toFloat());
	return (out);
}

Fixed& Fixed::operator++()
{
	this->value += 1;
	return (*this);
}

Fixed& Fixed::operator--()
{
	this->value -= 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed out(*this);
	out.value += 1;
	return (out);
}

Fixed Fixed::operator--(int)
{
	Fixed out(*this);
	out.value -= 1;
	return (out);
}

Fixed& Fixed::min(Fixed& one, Fixed& two)
{
	if (one < two)
		return (one);
	else
		return (two);
}

Fixed const& Fixed::min(Fixed const &one, Fixed const &two)
{
	if (one.getRawBits() < two.getRawBits())
		return (one);
	else
		return (two);
}

Fixed& Fixed::max(Fixed& one, Fixed& two)
{
	if (one > two)
		return (one);
	else
		return (two);
}

Fixed const& Fixed::max(Fixed const &one, Fixed const &two)
{
	if (one.getRawBits() > two.getRawBits())
		return (one);
	else
		return (two);
}
