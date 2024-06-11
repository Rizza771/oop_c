#include <cmath>

// Вычисляет длину отрезка по координатам x1, y1 первой точки и координатам x2, y2 второй точки.
float triangleSideLength(float x1, float y1, float x2, float y2) {
	return std::sqrt(std::pow((x2 - x1), 2) + std::pow((y2 - y1), 2));
}

// Вычисляет периметр треугольника по трем его сторонам.
float trianglePerimeter(float sideA, float sideB, float sideC) {
	return sideA + sideB + sideC;
}

// Вычисляет площадь треугольника по трем его сторонам.
float triangleArea(float sideA, float sideB, float sideC) {
	float halfPerimeter = trianglePerimeter(sideA, sideB, sideC) / 2; // Полупериметр треугольника
	return std::sqrt(halfPerimeter * (halfPerimeter - sideA) * (halfPerimeter - sideB) * (halfPerimeter - sideC)); // Нахождение площади по формуле Герона
}
