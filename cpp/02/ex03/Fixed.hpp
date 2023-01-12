#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <math.h>

class Fixed
{
	private:
		int value;
		static const int fract = 8;
	public:
		Fixed();
		Fixed(const int in);
		Fixed(const float in);
		Fixed(const Fixed &point);

		Fixed&	operator=(Fixed const &point);
		bool operator>(Fixed &input) const;
		bool operator<(Fixed &input) const;
		bool operator>=(Fixed &input) const;
		bool operator<=(Fixed &input) const;
		bool operator==(Fixed &input) const;
		bool operator!=(Fixed &input) const;
		Fixed operator+(Fixed const &input) const;
		Fixed operator-(Fixed const &input) const;
		Fixed operator*(Fixed const &input) const;
		Fixed operator/(Fixed const &input) const;
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		~Fixed();

		static Fixed& min(Fixed& one, Fixed& two);
		static Fixed const& min(Fixed const &one, Fixed const &two);
		static Fixed& max(Fixed& one, Fixed& two);
		static Fixed const& max(Fixed const &one, Fixed const &two);

		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream& operator<<(std::ostream &out, Fixed const &input);

#endif