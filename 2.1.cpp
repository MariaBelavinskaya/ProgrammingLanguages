#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include<iostream>
using namespace std;
/**
*\brief Функция, рассчитывающая площадь круга
*\param r - радиус круга
**/
double squadCirc(const int r);
/**
*\brief Функция, рассчитывающая площадь трапеции
*\ param а - певрое основание
*\ param b - второе основание
*\ param h - высота
**/
double squadTrap(const int a, const int b, const int h);
/**
* \brief
* \точка входа в программу
* \return 0 в случае успеха
*/
int main() {
	setlocale(LC_ALL, "Rus");
	int a, b, h, r;
	cout << "Введите  основание трапеции\n ";
	cin >> a;
	cout << "Введите второе основание трапеции\n ";
	cin >> b;
	cout << "Введите  высоту трапеции\n ";
	cin >> h;
	cout << "Введите  радиус круга\n ";
	cin >> r;
	cout << "Площадь трапеции равна " << squadTrap(a, b, h)<<endl;
	cout << "Площадь круга равна " << squadCirc(r);
	return 0;
}
double squadCirc(const int r) {
	double sqd = (M_PI) * pow(r,2);
	return sqd;
}
double squadTrap(const int a, const int b, const int h) {
	double sqd = (a + b)/ 2 * h;
	return sqd;
}