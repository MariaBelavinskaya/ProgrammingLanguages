#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

/**
*\brief Выполняет задание.
*\return Возращает значение функции y.
*\param x - параметр x
**/
void getY(double x);

/**
*\brief Математическая функция, рассчитывающая значение функции y.
*\return Возращает значение функции y.
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
