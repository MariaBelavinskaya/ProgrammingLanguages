#include <cmath>
#include <iostream>
using namespace std;
/**
* \brief Функция расета по заданной формуле.
* \param x Первый параметр функции.
* \param y Второй параметр функции.
* \return Значение функции.
*/
const double getA(const double x, const double y);

/**
* \brief
* \param x Первый параметр функции.
* \param y Второй параметр функции.
* \return Значение функции.
*/
const double getB(const double x, const double y);
/**
* \brief Точка входа в программу.
* \return Возращает 0 в случае успеха
*/
int main()
{
	const double x = 0.335;
	const auto y = 0.025;
	const auto a = getA(x, y);
	const auto b = getB(x, y);
	cout << " x = " << x << endl;
	cout << " y = " << y << endl;
	cout << " a = " << a << endl;
	cout << " b = " << b << endl;
	return 0;
}
const double getA(const double x, const double y)
{
	return (1 + x + x * x / 2 + x * x * x / 3 + x * x * x * x / 4);
}
const double getB(const double x, const double y)
{
	return (x * (sin(pow(x, 3)) + pow(cos(y), 2)));
}
