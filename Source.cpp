#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

/**
*\brief ��������� �������.
*\return ��������� �������� ������� y.
*\param x - �������� x
**/
void getY(double x);

/**
*\brief �������������� �������, �������������� �������� ������� y.
*\return ��������� �������� ������� y.
**/
int main()
{
	double x = 4;
	getY(x);
}

void getY(double x)
{
	while (x < 1.1)
	{
		std::cout << "y=" << x + sqrt(x) + pow(x, 1.0 / 3) - 2.5 << "\n";
		x = x + 0.05;
	}
}
