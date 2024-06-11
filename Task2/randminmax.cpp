#include <random>

// Функция генерации случайного целого числа.
int randMinMax(int min, int max) {
	if (min > max) // Если нижний порог указан выше верхнего, меняет местами переменные
		std::swap(min, max);

	static std::random_device rd; // Случайное число, предоставляемое железным ГСЧ
	static std::mt19937 gen(rd()); // Полученное выше число используется в качестве сида для вихря Мерсенна
	std::uniform_int_distribution<> distr(min, max); // Распределение случайных чисел с ограничением от a до b включительно
	return distr(gen);
}