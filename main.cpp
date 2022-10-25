#include<iostream>
#include<ctime>
#include<random>
using namespace std;

/**
*\brief ����� ������� ����������
*\param c_filling_random - ��������� �����
*\param c_filling_manual - ���� � ����������
*/
enum class fillingarray {
	c_filling_random,
	c_filling_manual
};

/**
*\brief �������, ����������� ������ ���������� �������
*\param rows - ���������� ����� �������
*\param cols - ���������� �������� ������� 
*/
int** filling_random(const size_t rows, const size_t cols);

/**
*\brief �������, ����������� ������ ���������� �������
*\param rows - ���������� ����� � �������
*\param cols - ���������� �������� � ������
*\param arr - ��������� �� ������
*/
void filling_manual(int** arr, const size_t rows, const size_t cols);

/*
*\brief ������, ��������� �� ����� ������
*\param arr - ��������� �� ������
*\param rows - ���������� ����� � �������
*\param cols - ���������� �������� � �������
*/
void print_array(int** arr, const size_t rows, const size_t cols);



/*
*\brief ������, ��������� ������
*\param array - ��������� �� ������
*\param rows - ���������� ����� � �������
*/
void delete_array(int**& array, const size_t rows);


/*
*\brief ������ ��������� ���������� ������
*\param rows - ���-�� ����� � �������
*\param cols - ���-�� �������� � �������
*\return ���������� ��������� �� ������
*/
int** create_array(const size_t rows, const size_t cols);

/*
*\brief ������� ����������� ������� �������
*\param message - ��������� ��� ������������
*\return ���������� ������� �������
*/
size_t get_size(const string& message);



/*
*\brief ������ ����������� ������ ������
*\param arr - ��������� �� ������
*\param rows - ���-�� ����� � �������
*\param cols - ���-�� �������� � �������
*/
void filling_zeros(int** arr, const size_t rows, const size_t cols);

/*
*\brief ������ ���������� �������� ������ ���� �������� �� ����������
*\param arr - ��������� �� ������
*\param rows - ���-�� ����� � �������
*\param cols - ���-�� �������� � �������
*/
void square_three_cols(int** arr, const size_t rows, const size_t cols);

/*
*\brief ������ ����������� ������ ������ ���������� ������ ������
*\param arr - ��������� �� ������
*\param oldarr - ��������� �� ������
*\param rows - ���-�� ����� � �������
*\param cols - ���-�� �������� � �������
*/
void filling_first_row(int** arr, int** oldarr, const size_t rows, const size_t cols);

/*
*\brief ������ ��������� ������� ��� ����� ����� � �������
*\param arr - ��������� �� ������
*\param rows - ���-�� ����� � �������
*\param cols - ���-�� �������� � �������
*/
int counting_extra_rows(int** arr, const size_t rows, const size_t cols);

/*
*\brief ������ ����������� ������ ������ ���������� ������ ������
*\param arr - ��������� �� ������
*\param oldarr - ��������� �� ������
*\param oldrows - ���-�� ����� � ����������� �������
*\param rows - ���-�� ����� � �������
*\param cols - ���-�� �������� � �������
*/
void setting_new_rows(int** oldarr, int** arr, const size_t oldrows, const size_t rows, const size_t cols);

/*
*\brief ����� ����� � ���������
*\return ���������� 0 � ������ ������
*/

int main() {
	setlocale(LC_ALL, "rus");
	size_t rows = 1;
	size_t cols = 1;
	try {
		rows = get_size("������� ���-�� �����\n");
		cols = get_size("������� ���-�� ��������\n");
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what();
		return 1;
	}
	int input = 0;
	int** array = create_array(rows, cols);
	cout << "�������� ������ ���������� ������� (������ = " << static_cast<int>(fillingarray::c_filling_random) << ", �������������� = " << static_cast<int>(fillingarray::c_filling_manual) << ") " << "\n";
	cin >> input;
	const auto choise = static_cast<fillingarray>(input);
	switch (choise) {
	case(fillingarray::c_filling_random):
		array = filling_random(rows, cols);
		break;
	case(fillingarray::c_filling_manual):
		filling_manual(array, rows, cols);
		cout << "\n";
		break;
	default:
		cout << "Error! ��� ����� �������";
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
	return 0;
}
void setting_new_rows(int** oldarr, int** arr, const size_t oldrows, const size_t rows, const size_t cols) {
	size_t exrow = 0;
	bool is_odd = false;
	for (size_t i = 0; i < oldrows; i++) {
		is_odd = false;
		for (size_t j = 0; j < cols; j++) {
			if ((i + 1) % 2 != 0) {
				is_odd = true;
			}
			arr[i + exrow][j] = oldarr[i][j];
		}
		if (is_odd) {
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
	if (rows % 2 == 0) {
		return rows / 2;
	}
	else {
		return rows / 2 + 1;
	}
}
void square_three_cols(int** arr, const size_t rows, const size_t cols) {
	for (size_t i = 0; i < cols; i++) {
		for (size_t j = 0; j < rows; j++) {
			if (i < 3) {
				arr[j][i] = arr[j][i] * arr[j][i];
			}
		}
	}

}


int** filling_random(const size_t rows, const size_t cols) {
	int min, max;
	cout << "������� ����������� ��������� �����\n";
	cin >> min;
	cout << "������� ������������ ��������� �����\n";
	cin >> max;
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


void filling_manual(int** arr, const size_t rows, const size_t cols) {
	cout << "������� �������� �������" << "\n";
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