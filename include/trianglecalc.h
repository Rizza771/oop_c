#pragma once

/*
	Модуль с функциями для вычисления параметров треугольника
*/

/// @brief Вычисляет длину отрезка по координатам x1, y1 первой точки и координатам x2, y2 второй точки.
/// @param x1 Координата x начала отрезка.
/// @param y1 Координата y начала отрезка.
/// @param x2 Координата x конца отрезка.
/// @param y2 Координата y конца отрезка.
/// @return Длину отрезка в float.
float triangleSideLength(float x1, float y1, float x2, float y2);

/// @brief Вычисляет периметр треугольника по трем его сторонам.
/// @param sideA Сторона A.
/// @param sideB Сторона B.
/// @param sideC Сторона C.
/// @return Периметр треугольника в float.
float trianglePerimeter(float sideA, float sideB, float sideC);

/// @brief Вычисляет площадь треугольника по трем его сторонам.
/// @param sideA Сторона A.
/// @param sideB Сторона B.
/// @param sideC Сторона C.
/// @return Площадь треугольника в float.
float triangleArea(float sideA, float sideB, float sideC);