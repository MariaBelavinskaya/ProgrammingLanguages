#include <iostream>
#include <ctime>
#include <random>
using namespace std;

/*
*\brief Выбор способа заполнения массива
*\param c_filling_random - рандомные числа
*\param с_filling_manual - с клавиатуры
*/
enum class fillingarray {
	c_filling_random,
	c_filling_manual
};

/*
*\brief Функция реализующая заполнение массива случайными числами
*\param rows - кол-во строк массива
*\param cols - кол-во столбцов массива
*/
int** filling_random(const size_t rows, const size_t cols, const int min, const int max);

/*
*\brief Фукция заполняющая массив данными с клавиатуры
*\param arr указатель на массив
*\param rows - кол-во строк в массиве
*\param cols - кол-во столбцов в массиве
*/
int filling_manual(int** arr, const size_t rows, const size_t cols);

/*
*\brief Фукция выводящая на экран массив
*\param arr - указатель на массив
*\param rows - кол-во строк в массиве
*\param cols - кол-во столбцов в массиве
*/
void print_array(int** arr, const size_t rows, const size_t cols);

/*
*\brief Фукция удаляющая массив
*\param array - указатель на массив
*\param rows - кол-во строк в массиве
*/
void delete_array(int**& array, const size_t rows);

/*
*\brief Фукция создающая двухмерный массив
*\param rows - кол-во строк в массиве
*\param cols - кол-во столбцов в массиве
*\return Возвращает указатель на массив
*/
int** create_array(const size_t rows, const size_t cols);

/*
*\brief Функция считывающая размеры массива
*\param message - подсказка для пользователя
*\return Возвращает размеры массива
*/
size_t get_size(const string& message);

/*
*\brief Фукция заполняющая массив нулями
*\param arr - указатель на массив
*\param rows - кол-во строк в массиве
*\param cols - кол-во столбцов в массиве
*/
void filling_zeros(int** arr, const size_t rows, const size_t cols);

/*
*\brief Фукция заменяющая элементы первых трех столбцов их квадратами
*\param arr - указатель на массив
*\param rows - кол-во строк в массиве
*\param cols - кол-во столбцов в массиве
*/
void square_three_cols(int** arr, const size_t rows, const size_t cols);

/*
*\brief Фукция заполняющая пустые строки элементами первой строки
*\param arr - указатель на массив
*\param oldarr - указатель на массив
*\param rows - кол-во строк в массиве
*\param cols - кол-во столбцов в массиве
*/
void filling_first_row(int** arr, int** oldarr, const size_t rows, const size_t cols);

/*
*\brief Фукция считающая сколько доп строк нужно в массиве
*\param arr - указатель на массив
*\param rows - кол-во строк в массиве
*\param cols - кол-во столбцов в массиве
*/
int counting_extra_rows(int** arr, const size_t rows, const size_t cols);

/*
*\brief Фукция заполняющая пустые строки элементами первой строки
*\param arr - указатель на массив
*\param oldarr - указатель на массив
*\param oldrows - кол-во строк в изначальном массиве
*\param rows - кол-во строк в массиве
*\param cols - кол-во столбцов в массиве
*/
void setting_new_rows(int** oldarr, int** arr, const size_t oldrows, const size_t rows, const size_t cols);

bool isOdd(size_t i);
/*
*\brief Точка входа в программу
*\return возвращает 0 в случае успеха
*/
int main() {
	setlocale(LC_ALL, "rus");
	size_t rows = 1;
	size_t cols = 1;
	try {
		rows = get_size("Введите кол-во строк\n");
		cols = get_size("Введите кол-во столбцов\n");
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what();
		return 1;
	}
	int input = 0;
	int** array = create_array(rows, cols);
	cout << "Выберите способ заполнения массива (Рандом = " << static_cast<int>(fillingarray::c_filling_random) << ", самостоятельно = " << static_cast<int>(fillingarray::c_filling_manual) << ") " << "\n";
	cin >> input;
	const auto choise = static_cast<fillingarray>(input);
	switch (choise) {
	case(fillingarray::c_filling_random):

		int min, max;
		cout << "Введите минимальное случайное число\n";
		cin >> min;
		cout << "Введите максимальное случайное число\n";
		cin >> max;
		array = filling_random(rows,
			cols, min, max);
		break;
	case(fillingarray::c_filling_manual):
		filling_manual(array, rows, cols);
		cout << "\n";
		break;
	default:
		cout << "Error! Нет такой функции";
		return 1;
	}
	print_array(array, rows, cols);
	square_three_cols(array, rows, cols);
	print_array(array, rows, cols);
	int newrows = counting_extra_rows(array, rows, cols) + rows;
	int** array_sec = create_array(newrows, cols);
	filling_zeros(array_sec, newrows, cols);
	setting_new_rows(array, array_sec, rows, newrows, cols);
	filling_first_row(array_sec, array, newrows, cols);
	print_array(array_sec, newrows, cols);
	delete_array(array, rows);
	delete_array(array_sec, newrows);
	return 0;
}

bool isOdd(size_t i) {
	return i % 2 == 0;
}

void setting_new_rows(int** oldarr, int** arr, const size_t oldrows, const size_t rows, const size_t cols) {
	size_t exrow = 0;
	for (size_t i = 0; i < oldrows; i++) {
		for (size_t j = 0; j < cols; j++) {
			arr[i + exrow][j] = oldarr[i][j];
		}
		if (isOdd(i)) {
			exrow++;
		}
	}
}

void filling_first_row(int** arr, int** oldarr, const size_t rows, const size_t cols) {
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = oldarr[0][j];
			}
		}
	}
}

int counting_extra_rows(int** arr, const size_t rows, const size_t cols) {
	if (isOdd(rows)) {
		return rows / 2;
	}
	else {
		return rows / 2 + 1;
	}
}

void square_three_cols(int** arr, const size_t rows, const size_t cols) {
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < rows; j++) {
			arr[j][i] = arr[j][i] * arr[j][i];
		}
	}

}

int** filling_random(const size_t rows, const size_t cols, const int min, const int max) {
	int** arr = create_array(rows, cols);
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<> uniformIntDistribution(min, max);
			arr[i][j] = uniformIntDistribution(gen);
		}
	}
	return arr;
}
void filling_zeros(int** arr, const size_t rows, const size_t cols)
{
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			arr[i][j] = 0;
		}
	}
}

int filling_manual(int** arr, const size_t rows, const size_t cols) {
	cout << "Введите элементы массива" << "\n";
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			cin >> arr[i][j];
		}
	}
}

void print_array(int** arr, const size_t rows, const size_t cols) {
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			cout << arr[i][j] << "\t ";
		}
		cout << "\n";
	}
	cout << '\n';
}

size_t get_size(const string& message) {
	int size = -1;
	cout << message;
	cin >> size;
	if (size < 0)
	{
		throw out_of_range("Incorrect size");
	}
	return size;
}

int** create_array(const size_t rows, const size_t cols) {
	int** array = new int* [rows];
	for (size_t i = 0; i < rows; i++) {
		array[i] = new int[cols];
	}
	return array;
}

void delete_array(int**& array, const size_t rows) {
	if (array != nullptr) {
		for (size_t i = 0; i < rows; i++) {
			delete[] array[i];
		}
		delete array;
		array = nullptr;
	}
}
