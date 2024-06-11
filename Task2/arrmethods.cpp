#include "randminmax.h"
#include <cmath>
#include <iostream>

namespace dynarr {

	// Процедура заполнения массива случайными числами в заданном диапазоне.
	void arrRandom(int* arr, size_t size, int min, int max) {
		for (size_t i = 0; i < size; ++i) {
			arr[i] = randMinMax(min, max);
		}
	}

	// Процедура заполнения массива факториалами
	void arrFactorial(int* arr, size_t size) {
		for (int i = 0; i < size; ++i) {
			if (i == 0) {
				arr[i] = 1;
			}
			else if (i == 1) {
				arr[i] = 2;
			}
			else {
				arr[i] = arr[i - 1] * (i + 1);
			}
		}
	}

	// Процедура вывода массива
	void outputArray(int* arr, size_t size) {
		for (int i = 0; i < size; ++i) {
			std::cout << arr[i] << " ";
		}
		std::cout << '\n';
	}
}