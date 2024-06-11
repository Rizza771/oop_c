#pragma once

namespace dynarr {

	/// @brief Процедура заполнения массива случайными числами в заданном диапазоне.
	/// @param arr Целевой массив.
	/// @param size Размер массива.
	/// @param min Нижний порог генерации случайных чисел (включительно).
	/// @param max Верхний порог генерации случайных чисел (включительно).
	void arrRandom(int* arr, size_t size, int min, int max);

	/// @brief Процедура заполнения массива факториалами.
	/// @param arr Целевой массив.
	/// @param size Размер массива.
	void arrFactorial(int* arr, size_t size);

	/// @brief Процедура вывода массива в консоль.
	/// @param arr Целевой массив.
	/// @param size Размер массива.
	void outputArray(int* arr, size_t size);
}