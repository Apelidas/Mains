#include "Point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0))
{
}

Point::Point(const float one, const float two) : x(one), y(two)
{
}

Point::Point(const Point &copy) : x(copy.x), y(copy.y)
{
}

Point& Point::operator=(Point const &)
{
	return (*this);
}

Point::~Point()
{
}

Fixed const& Point::getx() const
{
	return (this->x);
}

Fixed const& Point::gety() const
{
	return (this->y);
}

