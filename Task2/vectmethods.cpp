﻿#include "randminmax.h" // Подключение заголовочного файла, содержащего функцию randMinMax для генерации случайных чисел
#include <cmath>
#include <iostream>
#include <vector> // Подключение библиотеки для работы с STL-векторами

namespace vect { // Определение пространства имен vect для работы с векторами

    // Процедура заполнения вектора случайными числами в заданном диапазоне.
    void arrRandom(std::vector<int>& vect, int min, int max) {
        for (int i = 0; i < vect.size(); ++i) { // Цикл по всем элементам вектора
            vect[i] = randMinMax(min, max); // Возвращает случайное число из промежутка между min и max и записывает его в i-й элемент вектора
        }
    }

    // Процедура заполнения вектора факториалами.
    void arrFactorial(std::vector<int>& vect) {
        for (int i = 0; i < vect.size(); ++i) { // Цикл по всем элементам вектора
            if (i == 0) { // Если индекс 0, значение фактора равен 1 (0! = 1)
                vect[i] = 1;
            }
            else if (i == 1) { // Если индекс 1, значение фактора равен 2 (1! = 1, но в массив записывается 2)
                vect[i] = 2;
            }
            else { // Для всех остальных индексов, вычисляем факториал по формуле n! = (n-1)! * n
                vect[i] = vect[i - 1] * (i + 1); // (i + 1) - это текущее значение фактора
            }
        }
    }

    // Процедура вывода вектора в консоль.
    void outputArray(std::vector<int>& vect) {
        for (int i = 0; i < vect.size(); ++i) { // Цикл по всем элементам вектора
            std::cout << vect[i] << " "; // Вывод каждого элемента вектора, разделенного пробелом
        }
        std::cout << '\n'; // Печать новой строки после вывода всех элементов
    }
}