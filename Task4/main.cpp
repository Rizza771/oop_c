#include <iostream>
#include "Shapes.h"

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	// Объявление объектов
	Shape* shape_obj = new Shape;
	Square* square_obj = new Square;
	Circle* circle_obj = new Circle;

	cout << "object Shape: " << "x: " << shape_obj->pos_x << ", " << "y: " << shape_obj->pos_y << '\n';

	shape_obj->move(1.0, -2.5);

	cout << "object Shape moved: " << "x: " << shape_obj->pos_x << ", " << "y: " << shape_obj->pos_y << '\n';
	cout << '\n';

	cout << "object Square: " << "x: " << square_obj->pos_x << ", " << "y: " << square_obj->pos_y;
	cout << ", side: " << square_obj->getSide() << ", perimeter: " << square_obj->perimeter() << ", area: " << square_obj->area();
	cout << '\n';

	square_obj->move(2.5, -5.0);
	square_obj->setSide(5.5);

	cout << "object Square resized and changed side: " << "x: " << square_obj->pos_x << ", " << "y: " << square_obj->pos_y;
	cout << ", side: " << square_obj->getSide() << ", perimeter: " << square_obj->perimeter() << ", area: " << square_obj->area();
	cout << "\n\n";

	cout << "object Circle: " << "x: " << circle_obj->pos_x << ", " << "y: " << circle_obj->pos_y;
	cout << ", radius: " << circle_obj->getRadius() << ", perimeter: " << circle_obj->perimeter() << ", area: " << circle_obj->area();
	cout << '\n';

	circle_obj->move(6.82, -9.23);
	circle_obj->setRadius(-4.2);

	cout << "object Circle moved and resized: " << "x: " << circle_obj->pos_x << ", " << "y: " << circle_obj->pos_y;
	cout << ", radius: " << circle_obj->getRadius() << ", perimeter: " << circle_obj->perimeter() << ", area: " << circle_obj->area();
	cout << '\n';

	Shape* new_ptr = square_obj;

	cout << "\n\n\n\n\n" << new_ptr->perimeter();
	square_obj->setSide(0.0);

	return 0;
}