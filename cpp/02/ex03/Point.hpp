
#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const x;
		Fixed const y;
	
	public:
		Point();
		Point(const float one, const float two);
		Point(const Point &copy);
		Point& operator=(Point const &copy);
		~Point();
		Fixed const& getx() const;
		Fixed const& gety() const;

};

	bool bsp( Point const a, Point const b, Point const c, Point const point);
	void test_inside();
	void test_outside();


#endif