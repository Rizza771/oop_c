#include "TriangleClass.h"
#include <iostream>
#include <fstream>

// раскомментировать строку ниже, чтобы отключить assert()
// #define NDEBUG
#include <cassert> // для assert

// Выводит поля объекта класса Triangle 
void printObj(Triangle* obj) {
	std::cout << "Triangle" << '\n';
	std::cout << "Side A: " << obj->getSideA() << '\n';
	std::cout << "Side B: " << obj->getSideB() << '\n';
	std::cout << "Side C: " << obj->getSideC() << '\n';
	std::cout << "Perimeter: " << obj->getPerimeter() << '\n';
	std::cout << "Area: " << obj->getArea() << '\n';
}

int main() {
	Triangle* test_ptr;
	Triangle tri;
	test_ptr = &tri;

	assert(checkSettersSeparate(test_ptr));
	assert(checkSettersGeneral(test_ptr));

	Triangle *tri_obj = new Triangle(1.5, 2.5, 3.5); // указатель на динамический объект с дефолтными значениями для одиночного вывода
	// tri_obj - указатель на обьект
	printObj(tri_obj);
	std::cout << '\n';

	int arr_size = 3; // Размер массивов далее

	Triangle* tri_arr1 = new Triangle[arr_size]; // указатель на Массив для чтения из файла
	// tri_arr - указатель на массив
	Triangle* tri_arr2 = new Triangle[arr_size]; // Массив для записи

	std::cout << "tri_arr1 ref content:" << '\n'; // Вывод объектов первого массива (нужно чтобы увидеть изменения после чтения из файла)
	for (int i = 0; i < arr_size; ++i) {
		printObj(&tri_arr1[i]);
		std::cout << '\n';
	}

	std::ofstream file_obj; // Файловый объект на вывод
	file_obj.open("1.txt", std::ios::app); // Создает 1.txt в режиме append. После исполнения программы удалить

	// Цикл записи в файл
	for (int i = 0; i < arr_size; ++i) {
		tri_arr2[i].setSideA(1.5); // Задает полям sideA и sideB другие значения, чтобы после чтения были видны изменения
		tri_arr2[i].setSideB(1.5);
		file_obj.write((char*)&tri_arr2[i], sizeof(tri_arr2[i])); // Записывает в текстовый файл 
	}

	file_obj.close(); // Закрыть файл

	std::cout << "File 1.txt content:" << '\n';
	std::ifstream file_obj2; // Файловый объект на ввод
	file_obj2.open("1.txt", std::ios::in); // Открыть 1.txt в режиме чтения
	for (int i = 0; i < arr_size; ++i) {
		file_obj2.read((char*)&tri_arr1[i], sizeof(tri_arr1[i])); // Записать прочитанное в первый массив
		printObj(&tri_arr1[i]); // Вывести прочитанное
		std::cout << '\n';
	}
	file_obj2.close(); // Закрыть файл
	return 0;

}