#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int value;
		static const int fract = 8;
	public:
		Fixed();
		Fixed(const Fixed &point);
		Fixed&	operator=(Fixed const &point);
		~Fixed();

		int getRawBits() const;
		void setRawBits(int const raw);
};

#endif