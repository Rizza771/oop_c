﻿#include "arrmethods.h"
#include "checkerfunc.h"
#include "vectmethods.h"
#include <iostream>

// раскомментировать строку ниже, чтобы отключить assert()
// #define NDEBUG
#include <cassert> // для assert

// Объявление функции arrExec, которая работает с динамическим массивом
void arrExec() {
    
    // Использование пространства имен dynarr для доступа к его элементам
    using namespace dynarr;

    int n; // Переменная для хранения размера массива
    int min; // Переменная для хранения нижнего предела генерации случайных чисел
    int max; // Переменная для хранения верхнего предела генерации случайных чисел

    // Запрос у пользователя на ввод размера массива
    std::cout << "Введите натуральное число n: ";
    std::cin >> n; // Чтение размера массива от пользователя
    std::cout << "Введите нижний предел генерации случайных чисел: ";
    std::cin >> min; // Чтение нижнего предела
    std::cout << "Введите верхний предел генерации случайных чисел: ";
    std::cin >> max; // Чтение верхнего предела

    // Динамическое выделение памяти для массива случайных чисел
    int* rand_arr = new int[n];
    // Динамическое выделение памяти для массива факториалов
    int* fact_arr = new int[n];

    // Заполнение массива случайных чисел
    arrRandom(rand_arr, n, min, max);
    std::cout << "Массив случайных чисел. ";
    // Вывод элементов массива случайных чисел
    std::cout << "Элементы массива: ";
    outputArray(rand_arr, n); // Вызов функции для вывода массива

    // Заполнение массива факториалов значениями
    arrFactorial(fact_arr, n);
    std::cout << "Массив факториалов. ";
    // Вывод элементов массива факториалов
    std::cout << "Элементы массива: ";
    outputArray(fact_arr, n); // Вызов функции для вывода массива

}

// Объявление функции vectExec, которая работает с векторами
void vectExec() {

    // Использование пространства имен vect для доступа к его элементам
    using namespace vect;

    int n; // Переменная для хранения размера вектора
    int min; // Переменная для хранения нижнего предела генерации случайных чисел
    int max; // Переменная для хранения верхнего предела генерации случайных чисел

    // Запрос у пользователя на ввод размера вектора
    std::cout << "Введите натуральное число n: ";
    std::cin >> n; // Чтение размера вектора от пользователя
    std::cout << "Введите нижний предел генерации случайных чисел: ";
    std::cin >> min; // Чтение нижнего предела
    std::cout << "Введите верхний предел генерации случайных чисел: ";
    std::cin >> max; // Чтение верхнего предела

    // Создание векторов фиксированной длины n
    std::vector<int> rand_vect(n);
    std::vector<int> fact_vect(n);

    // Заполнение вектора случайных чисел
    arrRandom(rand_vect, min, max);
    std::cout << "Массив случайных чисел. ";
    // Вывод элементов вектора случайных чисел
    std::cout << "Элементы массива: ";
    outputArray(rand_vect); // Вызов функции для вывода вектора

    // Заполнение вектора факториалов значениями
    arrFactorial(fact_vect);
    std::cout << "Массив факториалов. ";
    // Вывод элементов вектора факториалов
    std::cout << "Элементы массива: ";
    outputArray(fact_vect); // Вызов функции для вывода вектора

}

// Основная функция программы
int main() {

    // Тестирование вектора размером 5
    {
        std::vector<int> test_vect(5); // Создание вектора для тестирования
        // Проверка, работают ли функции на случайных числах
        assert(checkVectRandom(test_vect));
        // Проверка, работают ли функции для вычисления факториалов
        assert(checkVectFactorial(test_vect));
    }

    // Тестирование динамического массива размером 5
    {
        size_t test_arr_size = 5; // Определение размера массива
        int* test_arr = new int[test_arr_size]; // Создание динамического массива
        // Проверка, работают ли функции на случайных числах
        assert(checkArrRandom(test_arr, test_arr_size));
        // Проверка, работают ли функции для вычисления факториалов
        assert(checkArrFactorial(test_arr, test_arr_size));
    }

    // Установка локали для отображения русских символов
    setlocale(LC_ALL, "Russian");

    // Вывод меню выбора режима работы программы
    std::cout << "Выберите режим работы:" << '\n';
    std::cout << "1. Динамические массивы." << '\n';
    std::cout << "2. Векторы." << '\n';
    std::cout << "0. Выход." << '\n';

    int input; // Переменная для хранения выбора пользователя
    std::cin >> input; // Чтение выбора от пользователя
    switch (input) {
        case 1: // Если пользователь выбрал динамические массивы
            system("cls"); // Очистка консоли
            arrExec(); // Вызов функции для работы с динамическими массивами
            break;
        case 2: // Если пользователь выбрал векторы
            system("cls"); // Очистка консоли
            vectExec(); // Вызов функции для работы с векторами
            break;
        case 0: // Если пользователь выбрал выход
            exit(1); // Завершение программы
    }

    return 0; // Возврат 0 при успешном завершении
}