#pragma once
#include "../Model/Stack/Stack.h"

/**
 * @brief Очередь на основе стека
 * 
 */
struct StackQueue
{
    /**
     * @brief Входной стек
     * 
     */
	Stack* InputStack;

    /**
     * @brief Выходной стек
     * 
     */
	Stack* OutputStack;
};

/**
 * @brief Инициализация очереди на основе стека
 * 
 * @param size Размер стека
 * @return StackQueue* Указатель на очередь
 */
StackQueue* InitStackQueue(int size);

/**
 * @brief Добавление элемента в очередь
 * 
 * @param queue Указатель на очередь
 * @param data Добавляемый элемент
 */
void Enqueue(StackQueue* queue, int data);

/**
 * @brief Извлечение элемента из очереди
 * 
 * @param queue Указатель на очередь
 * @return int Извлеченный элемент
 */
int Dequeue(StackQueue* queue);

/**
 * @brief Получение количества элементов в очереди
 * 
 * @param queue Указатель на очередь
 * @return int Количество элементов
 */
int LengthStackQueue(StackQueue* queue);

/**
 * @brief Удаление очереди
 * 
 * @param queue Указатель на очередь
 */
void DeleteStackQueue(StackQueue* queue);