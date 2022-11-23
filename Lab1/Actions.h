/**
 * @file Actions.h
 * @author Tarodictrl
 * @version 0.1
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "DynamicArray.h"

/**
 * @brief Инициализирует динамический массив.
 * 
 * @param dynamicArray - указатель на динамический массив.
 */

void InitDynamicArray(DynamicArray* dynamicArray);

/**
 * @brief Добавляет элемент в конец динамического массива.
 * 
 * @param dynamicArray - указатель на динамический массив.
 */

void AddElement(DynamicArray* dynamicArray);

/**
 * @brief Удаляет элемент из динамического массива.
 * 
 * @param dynamicArray - указатель на динамический массив.
 */

void RemoveElement(DynamicArray* dynamicArray);

/**
 * @brief Вставка элемента в динамический массив по индексу.
 * 
 * @param dynamicArray - указатель на динамический массив.
 */

void InsertElement(DynamicArray* dynamicArray);

/**
 * @brief Сортирует динамический массив.
 * 
 * @param dynamicArray - указатель на динамический массив.
 */

void SortArray(DynamicArray* dynamicArray);

/**
 * @brief Линейный поиск элемента в динамическом массиве.
 * 
 * @param dynamicArray - указатель на динамический массив.
 */

void LinearSearchElement(DynamicArray* dynamicArray);

/**
 * @brief Бинарный поиск элемента в динамическом массиве.
 * 
 * @param dynamicArray - указатель на динамический массив.
 */

void BinarySearchElement(DynamicArray* dynamicArray);

/**
 * @brief Пересоздает динамический массив.
 * 
 * @param dynamicArray - указатель на динамический массив.
 */

void RecreateDynamicArray(DynamicArray* dynamicArray);

/**
 * @brief Проверяет вводимое значение на число.
 * 
 * @return int - возвращает число.
 */

int CheckForDigit();