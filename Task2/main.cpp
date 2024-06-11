#include "arrmethods.h"
#include "checkerfunc.h"
#include "vectmethods.h"
#include <iostream>

// раскомментировать строку ниже, чтобы отключить assert()
// #define NDEBUG
#include <cassert> // для assert

void arrExec() {
	
	using namespace dynarr;

	int n;
	int min;
	int max;

	std::cout << "Введите натуральное число n: ";
	std::cin >> n;
	std::cout << "Введите нижний предел генерации случайных чисел: ";
	std::cin >> min;
	std::cout << "Введите верхний предел генерации случайных чисел: ";
	std::cin >> max;

	int* rand_arr = new int[n];
	int* fact_arr = new int[n];

	arrRandom(rand_arr, n, min, max);
	std::cout << "Массив случайных чисел. ";
	std::cout << "Элементы массива: ";
	outputArray(rand_arr, n);

	arrFactorial(fact_arr, n);
	std::cout << "Массив факториалов. ";
	std::cout << "Элементы массива: ";
	outputArray(fact_arr, n);

}

void vectExec() {

	using namespace vect;

	int n;
	int min;
	int max;

	std::cout << "Введите натуральное число n: ";
	std::cin >> n;
	std::cout << "Введите нижний предел генерации случайных чисел: ";
	std::cin >> min;
	std::cout << "Введите верхний предел генерации случайных чисел: ";
	std::cin >> max;

	std::vector<int> rand_vect(n);
	std::vector<int> fact_vect(n);

	arrRandom(rand_vect, min, max);
	std::cout << "Массив случайных чисел. ";
	std::cout << "Элементы массива: ";
	outputArray(rand_vect);

	arrFactorial(fact_vect);
	std::cout << "Массив факториалов. ";
	std::cout << "Элементы массива: ";
	outputArray(fact_vect);

}

int main() {

	{
		std::vector<int> test_vect(5);
		assert(checkVectRandom(test_vect));
		assert(checkVectFactorial(test_vect));
	}

	{
		size_t test_arr_size = 5;
		int* test_arr = new int[test_arr_size];
		assert(checkArrRandom(test_arr, test_arr_size));
		assert(checkArrFactorial(test_arr, test_arr_size));
	}

	setlocale(LC_ALL, "Russian");

	std::cout << "Выберите режим работы:" << '\n';
	std::cout << "1. Динамические массивы." << '\n';
	std::cout << "2. Векторы." << '\n';
	std::cout << "0. Выход." << '\n';

	int input;
	std::cin >> input;
	switch (input) {
	case 1:
		system("cls");
		arrExec();
		break;
	case 2:
		system("cls");
		vectExec();
		break;
	case 0:
		exit(1);
	}

	return 0;

}