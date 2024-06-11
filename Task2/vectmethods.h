#pragma once

#include <vector>

namespace vect {

	/// @brief Процедура заполнения вектора случайными числами в заданном диапазоне.
	/// @param vect Целевой вектор.
	/// @param min Нижний порог генерации случайных чисел (включительно).
	/// @param max Верхний порог генерации случайных чисел (включительно).
	void arrRandom(std::vector<int>& arr, int a, int b);

	/// @brief Процедура заполнения вектора факториалами.
	/// @param vect Целевой вектор.
	void arrFactorial(std::vector<int>& arr);

	/// @brief Процедура вывода вектора в консоль.
	/// @param vect Целевой вектор.
	void outputArray(std::vector<int>& arr);
}
