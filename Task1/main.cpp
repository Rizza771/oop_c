#include <iostream>
#include "trianglecalc.h"

// раскомментировать строку ниже, чтобы отключить assert()
// #define NDEBUG
#include <cassert> // для assert

#define _USE_MATH_DEFINES

int main(){

	// Проверка функции расчета длины отрезка
	assert(triangleSideLength(0.0, 0.0, 0.0, 0.0) < FLT_EPSILON); // Проверка отрезка в нулевых координатах
	assert((triangleSideLength(5.0, 5.0, -5.0, 5.0) - 10.0) < FLT_EPSILON); // Проверка отрезка в I - II четвертях
	assert((triangleSideLength(7.0, 9.0, -11.0, -13.0) - 28.42534080710379) < FLT_EPSILON); // Проверка I - III четверти

	// Проверка функции расчета периметра
	assert((trianglePerimeter(10.0, 20.0, 30.0) - 60.0) < FLT_EPSILON); // Ровные значения
	assert((trianglePerimeter(10.123456, 20.987987, 30.456654) - 61.568097) < FLT_EPSILON); // Значения с частью после запятой
	assert((trianglePerimeter(-16.666665, -16.666665, 66.66666) - 33.33333) < FLT_EPSILON); // Отрицательные числа

	// Проверка функции расчета площади
	assert(triangleArea(1.0, 1.0, 0.0) < FLT_EPSILON); // Площадь равна 0 при любой стороне равной 0
	assert(triangleArea(10.0, 20.0, 30.0) < FLT_EPSILON); // Если сумма двух сторон равна третьей, площадь равна 0
	assert((triangleArea(42.0, 21.0, 56.0) - 374.577678859) < FLT_EPSILON); // Проверка на обычных значениях

	setlocale(LC_ALL, "Russian"); // Для русского языка в консоли
	
	float ax, ay, bx, by, cx, cy; // Координаты вершин треугольника
	
	std::cout << "Введите координаты x, y точки A: ";
	std::cin >> ax >> ay;
	std::cout << "Введите координаты x, y точки B: ";
	std::cin >> bx >> by;
	std::cout << "Введите координаты x, y точки C: ";
	std::cin >> cx >> cy;

	std::cout << "Заданы вершины треугольника ABC: ";
	std::cout << "A(" << ax << ", " << ay << "), ";
	std::cout << "B(" << bx << ", " << by << "), ";
	std::cout << "C(" << cx << ", " << cy << ")" << '\n';

	// Вычисление длин сторон треугольника
	float sideA = triangleSideLength(ax, ay, bx, by);
	float sideB = triangleSideLength(bx, by, cx, cy);
	float sideC = triangleSideLength(cx, cy, ax, ay);

	std::cout << "Периметр треугольника ABC: " << trianglePerimeter(sideA, sideB, sideC) << '\n';
	std::cout << "Площадь треугольника ABC: " << triangleArea(sideA, sideB, sideC) << '\n';
	return 0;

}