#include "randminmax.h"
#include <cmath>
#include <iostream>
#include <vector>

namespace vect {

	// Процедура заполнения вектора случайными числами в заданном диапазоне.
	void arrRandom(std::vector<int>& vect, int min, int max) {
		for (int i = 0; i < vect.size(); ++i) {
			vect[i] = randMinMax(min, max);
		}
	}

	// Процедура заполнения вектора факториалами.
	void arrFactorial(std::vector<int>& vect) {
		for (int i = 0; i < vect.size(); ++i) {
			if (i == 0) {
				vect[i] = 1;
			}
			else if (i == 1) {
				vect[i] = 2;
			}
			else {
				vect[i] = vect[i - 1] * (i + 1);
			}
		}
	}

	// Процедура вывода вектора в консоль.
	void outputArray(std::vector<int>& vect) {
		for (int i = 0; i < vect.size(); ++i) {
			std::cout << vect[i] << " ";
		}
		std::cout << '\n';
	}
}