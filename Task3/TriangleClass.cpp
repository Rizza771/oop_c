#include "trianglecalc.h"
#include "TriangleClass.h"
#include <stdexcept>

#define _USE_MATH_DEFINES

// Сеттер периметра
//void Triangle::setPerimeter(float _sideA, float _sideB, float _sideC) {
//	this->perimeter = trianglePerimeter(_sideA, _sideB, _sideC);
//}
//
//// Сеттер площади
//void Triangle::setArea(float _sideA, float _sideB, float _sideC) {
//	this->area = triangleArea(_sideA, _sideB, _sideC);
//}

// Конструктор
Triangle::Triangle(float _sideA, float _sideB, float _sideC) {
	if (isValid(_sideA, _sideB, _sideC)) { // Проверка на правильность
		this->sideA = _sideA; // Если isValid возвращает true, заполнить поля сторон
		this->sideB = _sideB;
		this->sideC = _sideC;
		//updateFields();
	}
}

// Проверка треугольника
bool Triangle::isValid(float _sideA, float _sideB, float _sideC) {
	if (((_sideA + _sideB) > _sideC) || ((_sideB + _sideC) > _sideA) || ((_sideC + _sideA) > _sideB)) {
		return true; // Если сумма длин двух сторон больше третьей, возвращает true
	}
	return false;
}

/*void Triangle::updateFields() {
	setPerimeter(this->sideA, this->sideB, this->sideC);
	setArea(this->sideA, this->sideB, this->sideC);
}*/

// Сеттеры сторон
void Triangle::setSides(float _sideA, float _sideB, float _sideC) {
	if (isValid(_sideA, _sideB, _sideC)) {
		this->sideA = _sideA;
		this->sideB = _sideB;
		this->sideC = _sideC;
		//updateFields();
	}
	else {
		throw std::invalid_argument("Неверные длины сторон треугольника");
	}
}

void Triangle::setSideA(float _sideA) {
	if (isValid(_sideA, this->sideB, this->sideC)) {
		this->sideA = _sideA;
		//updateFields();
	}
}

void Triangle::setSideB(float _sideB) {
	if (isValid(this->sideA, _sideB, this->sideC)) {
		this->sideB = _sideB;
		//updateFields();
	}
}

void Triangle::setSideC(float _sideC) {
	if (isValid(this->sideA, this->sideB, _sideC)) {
		this->sideC = _sideC;
		//updateFields();
	}
}

// Геттеры сторон
float Triangle::getSideA() const { return this->sideA; }
float Triangle::getSideB() const { return this->sideB; }
float Triangle::getSideC() const { return this->sideC; }

// Геттеры периметра и площади
float Triangle::getPerimeter() const { return trianglePerimeter(this->sideA, this->sideB, this->sideC); }
float Triangle::getArea() const { return triangleArea(this->sideA, this->sideB, this->sideC); }

bool checkSettersSeparate(Triangle* test_obj) {
	test_obj->setSideA(1.5);
	test_obj->setSideB(2.5);
	test_obj->setSideC(3.5);
	if (((test_obj->getSideA() - 1.5) < FLT_EPSILON) &&
		((test_obj->getSideB() - 2.5) < FLT_EPSILON) &&
		((test_obj->getSideC() - 3.5) < FLT_EPSILON) &&
		((test_obj->getPerimeter() - 7.5) < FLT_EPSILON) &&
		((test_obj->getArea() - 1.62379766) < FLT_EPSILON)) {
		return true;
	}
	return false;
}

bool checkSettersGeneral(Triangle* test_obj) {
	test_obj->setSides(2.5, 3.5, 4.5);
	if (((test_obj->getSideA() - 2.5) < FLT_EPSILON) &&
		((test_obj->getSideB() - 3.5) < FLT_EPSILON) &&
		((test_obj->getSideC() - 4.5) < FLT_EPSILON) &&
		(abs(test_obj->getPerimeter() - 10.5) < FLT_EPSILON) &&
		((test_obj->getArea() - 4.35307026) < FLT_EPSILON)) {
		return true;
	}
	return false;
}