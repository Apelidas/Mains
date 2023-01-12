#include "Point.hpp"

Fixed gradient(Point const &a, Point const &b)
{
	Fixed m((a.gety().toFloat() - b.gety().toFloat()) / (a.getx().toFloat() - b.getx().toFloat()));
	return (m);
}

Fixed inter(Point const &a, Fixed const &grad)
{
	Fixed out(a.gety() - (a.getx() * grad));
	return (out);
}

bool side(Point const &test, Point const &a, Fixed const &grad, Fixed const &n)
{
	bool b;
	bool c;

	if (test.gety().toFloat() < (test.getx().toFloat() * grad.toFloat() + n.toFloat()))
		b = true;
	else
		b = false;
	if (a.gety().toFloat() < (a.getx().toFloat() * grad.toFloat() + n.toFloat()))
		c = true;
	else
		c = false;
	if (b == c)
		return (true);
	return (false);
}

bool safety(Point const a, Point const b, Point const c, Point const p)
{
	Fixed grad;

	if (a.getx().toFloat() == b.getx().toFloat())
	{
		if (c.getx().toFloat() > a.getx().toFloat() && p.getx().toFloat() > a.getx().toFloat())
			return (true);
		else if (c.getx().toFloat() < a.getx().toFloat() && p.getx().toFloat() < a.getx().toFloat())
			return (true);
		else
		return (false);
	}
	else
	{
		grad = gradient(a, b);
		return (side(p, c, grad, inter(a, grad)));
	}
}

bool checkPossible(Point const a, Point const b, Point const c)
{
	if (a.getx().toFloat() == b.getx().toFloat() && a.gety().toFloat() == b.gety().toFloat())
		return (false);
	if (c.getx().toFloat() == b.getx().toFloat() && c.gety().toFloat() == b.gety().toFloat())
		return (false);
	if (c.getx().toFloat() == a.getx().toFloat() && c.gety().toFloat() == a.gety().toFloat())
		return (false);


	Fixed grad;

	grad = gradient(a, b);
	if (c.gety().toFloat() == (grad * c.getx() + inter(a, grad)).toFloat())
		return (false);
	grad = gradient(a, c);
	if (b.gety().toFloat() == (grad * b.getx() + inter(a, grad)).toFloat())
		return (false);
	grad = gradient(c, b);
	if (a.gety().toFloat() == (grad * a.getx() + inter(b, grad)).toFloat())
		return (false);
	return (true);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	bool ba;
	bool bb;
	bool bc;
	Fixed grad;

	if (!checkPossible(a, b, c))
		return (false);
	ba = safety(a, b, c, point);
	bb = safety(a, c, b, point);
	bc = safety(b, c, a, point);
	if (ba && bb && bc)
		return (true);
	return (false);
}

int main()
{
	test_inside();
	std::cout << "____________________________________________" << std::endl;
	test_outside();
}