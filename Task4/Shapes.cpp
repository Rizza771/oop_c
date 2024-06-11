#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include "Shapes.h"


Shape::Shape(float _pos_x, float _pos_y) {
	this->pos_x = _pos_x;
	this->pos_y = _pos_y;
}

void Shape::move(float d_x, float d_y) {
	this->pos_x += d_x;
	this->pos_y += d_y;
	}

float Shape::perimeter() const { return 0.0; }
float Shape::area() const { return 0.0; }


Square::Square(float _side) {
	if (_side != 0.0) {
		this->side = abs(_side);
	}
	else
		std::cout << "Неверно задана длина стороны";
}

float Square::perimeter() const { return this->side * 4; }
float Square::area() const { return this->side * side; }

void Square::setSide(float _side) {
	if (_side != 0.0) {
		this->side = abs(_side);
	}
	else
		std::cout << "Неверно задана длина стороны";
}

float Square::getSide() { return this->side; }


Circle::Circle(float _radius) {
	if (_radius != 0.0) {
		this->radius = abs(_radius);
	}
	else
		std::cout << "Неверно задан радиус";
}

float Circle::perimeter() const { return 2 * M_PI * this->radius; }
float Circle::area() const { return M_PI * this->radius * this->radius; }

void Circle::setRadius(float _radius) {
	if (_radius != 0.0) {
		this->radius = abs(_radius);
	}
	else
		std::cout << "Неверно задан радиус";
}
float Circle::getRadius() { return this->radius; }