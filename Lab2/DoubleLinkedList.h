/**
 * @file List.h
 * @author Tarodictrl
 * @version 0.1
 * @date 2022-11-29
 *
 * @copyright Copyright (c) 2022
 *
 */

/**
 * @brief Представляет структуру данных - Двусвязный списосписок.
 */

#pragma once

struct ListItem
{
    /**
     * @brief Следующий элемент.
     * 
     */

    ListItem *Next;
    
    /**
     * @brief Преыдущий элемент.
     * 
     */
    ListItem *Prev;
    
    /**
     * @brief Значение элемента.
     * 
     */
    int Value = 0;
};


struct List
{
    /**
     * @brief Указатель на первый элемент списка.
     */
    ListItem *Head;

    /**
     * @brief Указатель на последний элемент списка.
     */
    ListItem *Tail;

    /**
     * @brief Длина списка.
     */
    int Length = 0;
};

/**
 * @brief Создает новый спискок.
 * 
 * @param list - указатель на список.
 */
void InitList(List *list);

/**
 * @brief Добавляет элемент в начало списка.
 * 
 * @param list - указатель на список.
 * @param value - значение элемента.
 */
void Add(List *list, int value);

/**
 * @brief Удаляет элемент из списка.
 * 
 * @param list - указатель на список.
 * @param index - Указатель на элемент.
 */
void Remove(List *list, int index);

/**
 * @brief Выводит список на экран.
 * 
 * @param list - указатель на список.
 */
void PrintList(List *list);

/**
 * @brief Добавляет элемент в начало списка.
 * 
 * @param list - указатель на список.
 * @param value - значение элемента.
 */
void InsertInBegin(List *list, int value);

/**
 * @brief Добавляет элемент в конец списка.
 * 
 * @param list - указатель на список.
 * @param value - значение элемента.
 */
void InsertInEnd(List *list, int value);

/**
 * @brief Добавляет элемент в список по индексу.
 * 
 * @param list - указатель на список.
 * @param index - индекс элемента.
 * @param value - значение элемента.
 */
void InsertAfter(List *list, int index, int value);

/**
 * @brief Добавляет элемент в список перед индексом.
 * 
 * @param list - указатель на список.
 * @param index - индекс элемента.
 * @param value - значение элемента.
 */
void InsertBefore(List *list, int index, int value);

/**
 * @brief Линейный поиск элемента в списке.
 * 
 * @param list - указатель на список.
 * @param value - значение элемента.
 * @return int - индекс элемента.
 */
int LinearSearch(List *list, int value);

/**
 * @brief Сортировка вставками списка.
 * 
 * @param list - указатель на список.
 */
void InsertionSort(List *list);

/**
 * @brief Очищает список.
 * 
 * @param list - указатель на список.
 */
void Clear(List *list);