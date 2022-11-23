/**
 * @file DynamicArray.h
 * @author Tarodictrl
 * @version 0.1
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

/**
 * @brief Предствляет объект - динамический массив целых чисел.
*/

struct DynamicArray
{
    int Length;
    int Capacity;
    int* Array;
    int Growth;
    bool IsSorted;
};

/**
 * @brief Создает динамический массив.
 * 
 * @param array - указатель на динамический массив.
 */

void CreateDynamicArray(DynamicArray* array);

/**
 * @brief Изменяет размер динамического массива.
 * 
 * @param array - указатель на динамический массив.
 */

void ResizeDynamicArray(DynamicArray* array);

/**
 * @brief Добавляет элемент в конец динамического массива.
 * 
 * @param array - указатель на динамический массив.
 * @param value - добавляемый элемент.
 */

void Add(DynamicArray* array, int value);

/**
 * @brief Выводит динамического массива в консоль.
 * 
 * @param array - указатель на динамический массив.
 */

void PrintDynamicArray(DynamicArray* array);

/**
 * @brief Сортирует динамический массив.
 * 
 * @param array - указатель на динамический массив.
 */

void SortingDynamicArray(DynamicArray* array);

/**
 * @brief Ищет элемент в динамическом массиве.
 * 
 * @param array - указатель на динамический массив.
 * @param index - индекс элемента.
 * @return int - -1, если индекс вне массива.
 */

int RemoveAt(DynamicArray* array, int index);

/**
 * @brief Вставляет элемент в динамический массив.
 * 
 * @param array - указатель на динамический массив.
 * @param element - вставляемый элемент.
 * @param index - индекс элемента.
 * @return int - -1, если индекс вне массива.
 */

int Insert(DynamicArray* array, int element, int index);

/**
 * @brief Линейный поиск элемента в динамическом массиве.
 * 
 * @param array - указатель на динамический массив.
 * @param value - искомый элемент.
 * @return int - индекс элемента.
 */

int LinearSearch(DynamicArray* array, int value);

/**
 * @brief Бинарный поиск элемента в динамическом массиве.
 * 
 * @param array - указатель на динамический массив.
 * @param element - искомый элемент.
 * @return int - индекс элемента.
 */

int BinarySearch(DynamicArray* array, int element);

/**
 * @brief Проверяет на выход за границы динамического массива.
 * 
 * @param array - указатель на динамический массив.
 * @param index - индекс элемента.
 * @return true - если индекс выходит за границы.
 * @return false - если индекс не выходит за границы.
 */

bool CheckIndexOutRange(DynamicArray* array, int index);