#pragma once


/// @brief Базовый класс геометрических фигур, имеет поля pos_x, pos_y - координаты.
class Shape {
public:

	// Координаты
	float pos_x;
	float pos_y;

	// Конструктор, дефолтные значения 0.0
	Shape(float _pos_x = 0.0, float _pos_y = 0.0);

	// Метод перемещения
	void move(float d_x, float d_y);

	// Виртуальные методы для потомков
	virtual float perimeter() const;
	virtual float area() const;

};

/// @brief Дочерний класс Shape. Класс квадратов, имеет поле side - длину стороны.
class Square : public Shape {
private:

	// Длина сторон
	float side;

public:

	// Конструктор, дефолтное значение 1.0
	Square(float _side = 1.0);

	// Переопределение функций вычисления периметра и площади
	float perimeter() const override;
	float area() const override;

	// Сеттер длины стороны
	void setSide(float _side);

	// Геттер длины стороны
	float getSide();

};

/// @brief Дочерний класс Shape. Класс окружности, имеет поле radius - радиус окружности.
class Circle : public Shape {
private:

	// Радиус окружности
	float radius;

public:

	// Конструктор, дефолтное значение 1.0
	Circle(float _radius = 1.0);

	// Переопределение методов вычисления длины и площади окружности
	float perimeter() const override;
	float area() const override;

	// Сеттер радиуса
	void setRadius(float _radius);

	// Геттер радиуса
	float getRadius();

};