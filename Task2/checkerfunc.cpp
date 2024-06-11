#include "arrmethods.h"
#include "vectmethods.h"
#include <vector>

bool checkVectRandom(std::vector<int> test_vect) { // Вектор test_vect копируется в функцию

	using namespace vect;

	arrRandom(test_vect, 0, 0); // Заполнение вектора test_vect 5 элементами со значением 0
	for (size_t i = 0; i < test_vect.size(); ++i) {
		if (test_vect[i] != 0) // Проверка, равен ли каждый элемент 0
			return false;
	}

	arrRandom(test_vect, -5, 5); // Заполнение вектора test_vect 5 элементами со случайным значением от -5 до 5
	for (size_t i = 0; i < test_vect.size(); ++i) {
		if ((test_vect[i] < -5) || (test_vect[i] > 5)) // Проверка, входят ли все элементы в диапазон [-5;5]
			return false;
	}

	return true; // Истина, если проверки пройдены

}

bool checkVectFactorial(std::vector<int> test_vect) {

	using namespace vect;

	arrFactorial(test_vect);
	std::vector<int> ref_vect = { 1, 2, 6, 24, 120 };

	for (size_t i = 0; i < test_vect.size(); ++i) {
		if (test_vect[i] != ref_vect[i])
			return false;
	}

	return true;

}

bool checkArrRandom(int* test_arr, size_t size) {

	using namespace dynarr;

	arrRandom(test_arr, size, 0, 0); // Заполнение вектора test_arr 5 элементами со значением 0
	for (size_t i = 0; i < size; ++i) {
		if (test_arr[i] != 0) // Проверка, равен ли каждый элемент 0
			return false;
	}

	arrRandom(test_arr, size, -5, 5); // Заполнение вектора test_arr 5 элементами со случайным значением от -5 до 5
	for (size_t i = 0; i < size; ++i) {
		if ((test_arr[i] < -5) || (test_arr[i] > 5)) // Проверка, входят ли все элементы в диапазон [-5;5]
			return false;
	}

	return true; // Истина, если проверки пройдены

}

bool checkArrFactorial(int* test_arr, size_t size) {

	using namespace dynarr;

	arrFactorial(test_arr, size);
	int* ref_arr = new int[5] {1, 2, 6, 24, 120};

	for (size_t i = 0; i < size; ++i) {
		if (test_arr[i] != ref_arr[i])
			return false;
	}

	return true;

}