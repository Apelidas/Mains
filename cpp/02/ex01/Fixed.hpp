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
		~Fixed();

		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream& operator<<(std::ostream &out, Fixed const &input);

#endif