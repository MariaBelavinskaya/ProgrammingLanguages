#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include<limits>
using namespace std;

/**
*\brief Проверка y при заданном x.
*\param x Параметр функции.
*\return true Если y существует при заданном x.
*/
bool IsExists(const double x);

/**
*\brief Функция рассчета по заданной формуле.
*\param x Параметр функции.
*\return Возвращает значение функции.
*/
double Calculation(const double x);

/**
*\brief Точка входа в программу.
*\return Возвращает 0 в случае успешного выполнения.
*/
int main()
{
	const double xStart=0.4;
	const double xFinish=1.00;
	const double step=0.05;
	double x = xStart;

		while (x < xFinish + step)
		{
            if (IsExists(x))
            {
                const double y = Calculation(x);
                cout << x << " " << y << "\n";
            }
            else
            {
                cout << x << " " << "Нет значения \n";
            }
            x += step;
        }

    return 0;
}

bool IsExists(const double x)
{
    return (abs(x)) > numeric_limits<double>::min();
}

double Calculation(const double x)
{
    return x + sqrt(x) + cbrt(x) - 2.5;
}
