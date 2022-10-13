#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include<iostream>
using namespace std;

/**
*\brief Функция, рассчитывающая площадь круга
*\param r - радиус круга
**/

double getVariable(const string& message);

/**
*\brief Функция, суммирующая два числа.
*\param a Первое число.
*\param b Второе число.
*\return Значение функции.
*/

double squadCirc(const double r);

/**
*\brief Функция, рассчитывающая площадь трапеции
*\ param а - певрое основание
*\ param b - второе основание
*\ param h - высота
**/

double squadTrap(const double a, const double b, const double h);

/**
* \brief
* \точка входа в программу
* \return 0 в случае успеха
*/

enum class userInput
{
	squadCirc,
	squadTrap
};

int main()
{
	double a = getVariable("Введите значение перменной a: ");
	double b = getVariable("Введите значение перменной b: ");
	double h = getVariable("Введите значение перменной h: ");
	double r = getVariable("Введите значение перменной r: ");
	cout << "Введите число, соответствующее заданию:\n"
		<< static_cast<int>(userInput::squadCirc) << " - Вычисляет площадь круга.\n"
		<< static_cast<int>(userInput::squadTrap) << " - Вычисляет площадь трапеции.\n";
	
	int input = 0;
	cin >> input;
	const auto choice = static_cast<userInput>(input);
	cout << "\n";

	setlocale(LC_ALL, "Rus");
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

double getVariable(const string& message)
{
    cout << message;
    double variable = 0.0;
    cin >> variable;
    return variable;
}

double squadCirc(const double r) 
{
	double sqd = (M_PI) * pow(r,2);
	return sqd;
}

double squadTrap(const double a, const double b, const double h) 
{
	double sqd = (a + b)/ 2 * h;
	return sqd;
}
