#include "Point.hpp"

void test_inside()
{
	Point a(0, 0);
	Point b(0, 5);
	Point c(5, 0);
	Point p(1, 1);
	Point p1(1, 2);
	Point p2(2, 1);

	std::cout << "Our Points are:" << std::endl;
	std::cout << "A:" << a.getx().toFloat() << "|" << a.gety().toFloat() << std::endl;
	std::cout << "B:" << b.getx().toFloat() << "|" << b.gety().toFloat() << std::endl;
	std::cout << "C:" << c.getx().toFloat() << "|" << c.gety().toFloat() << std::endl;

	std::cout << "\tPoint:" <<  p.getx().toFloat() << "|" << p.gety().toFloat();
	if (bsp(a, b, c, p))
		std::cout << " is inside" << std::endl;
	else
		std::cout << " not inside" << std::endl;
	
	std::cout << "\tPoint:" <<  p1.getx().toFloat() << "|" << p1.gety().toFloat();
	if (bsp(a, b, c, p1))
		std::cout << " is inside" << std::endl;
	else
		std::cout << " not inside" << std::endl;

	std::cout << "\tPoint:" <<  p2.getx().toFloat() << "|" << p2.gety().toFloat();
	if (bsp(a, b, c, p2))
		std::cout << " is inside" << std::endl;
	else
		std::cout << " not inside" << std::endl;
	
}

void test_outside()
{
	Point a(0, 0);
	Point b(0, 5);
	Point c(5, 0);
	Point p(6, 6);

	std::cout << "Our Points are:" << std::endl;
	std::cout << "A:" << a.getx().toFloat() << "|" << a.gety().toFloat() << std::endl;
	std::cout << "B:" << b.getx().toFloat() << "|" << b.gety().toFloat() << std::endl;
	std::cout << "C:" << c.getx().toFloat() << "|" << c.gety().toFloat() << std::endl;

	std::cout << "\tPoint:" <<  p.getx().toFloat() << "|" << p.gety().toFloat();
	if (bsp(a, b, c, p))
		std::cout << " is inside" << std::endl;
	else
		std::cout << " not inside" << std::endl;

	std::cout << "\tPoint:" <<  a.getx().toFloat() << "|" << a.gety().toFloat();
	if (bsp(a, b, c, a))
		std::cout << " is inside" << std::endl;
	else
		std::cout << " not inside" << std::endl;

	std::cout << "\tPoint:" <<  b.getx().toFloat() << "|" << b.gety().toFloat();
	if (bsp(a, b, c, b))
		std::cout << " is inside" << std::endl;
	else
		std::cout << " not inside" << std::endl;

	std::cout << "\tPoint:" <<  c.getx().toFloat() << "|" << c.gety().toFloat();
	if (bsp(a, b, c, c))
		std::cout << " is inside" << std::endl;
	else
		std::cout << " not inside" << std::endl;
}