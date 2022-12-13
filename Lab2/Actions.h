#include "DoubleLinkedList.h"

/**
 * @brief Добавляет элемент в начало списка.
 * 
 * @param list 
 */
void AddElement(List* list);

/**
 * @brief Выводит список на экран.
 * 
 * @param list - указатель на список.
 */
void OutputList(List* list);

/**
 * @brief Проверяет вводимое значение на корректность.
 * 
 * @return int - возвращает введенное значение.
 */
int CheckForDigit();

/**
 * @brief Удаляет элемент из списка.
 * 
 * @param list - указатель на список.
 */

void RemoveElement(List* list);

/**
 * @brief Добавляет элемент в начало списка.
 * 
 * @param list - указатель на список.
 */
void InsertElementInBegin(List* list);

/**
 * @brief Добавляет элемент в конец списка.
 * 
 * @param list - указатель на список.
 */
void InsertElementInEnd(List* list);

/**
 * @brief Добавляет элемент после указанного индекса.
 * 
 * @param list - указатель на список.
 */
void InsertElementAfter(List* list);

/**
 * @brief Добавляет элемент перед указанным индексом.
 * 
 * @param list - указатель на список.
 */
void InsertElementBefore(List* list);

/**
 * @brief Сортировка списка.
 * 
 * @param list - указатель на список.
 */
void SortList(List* list);

/**
 * @brief Линейный поиск элемента в списке.
 * 
 * @param list - указатель на список.
 */
void LinearSearchElement(List* list);

/**
 * @brief Заполняет список случайными числами.
 * 
 * @param list - указатель на список.
 * @param count - количество элементов.
 */
void RandomValues(List* list, int count);

/**
 * @brief Исследование.
 * 
 */
void ConductResearch();