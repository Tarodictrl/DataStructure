#pragma once

#include "../Model/RingBuffer/RingBuffer.h"

/**
 * @brief Очередь на основе кольцевого буфера
 * 
 */
struct QueueRingBuffer
{
    /**
     * @brief Указатель на кольцевой буфер
     * 
     */
	RingBuffer* Buffer;
};

/**
 * @brief Инициализация очереди на основе кольцевого буфера
 * 
 * @param sizeBuffer Размер буфера
 * @return QueueRingBuffer* Указатель на очередь
 */
QueueRingBuffer* InitQueueRingBuffer(int sizeBuffer);

/**
 * @brief Добавление элемента в очередь
 * 
 * @param queue Указатель на очередь
 * @param data Добавляемый элемент
 */
void EnqueueRingBuffer(QueueRingBuffer* queue, int data);

/**
 * @brief Удаление элемента из очереди
 * 
 * @param queue Указатель на очередь
 * @return int Удаленный элемент
 */
int DequeueRingBuffer(QueueRingBuffer* queue);

/**
 * @brief Удаление очереди
 * 
 * @param queue Указатель на очередь
 */
void DeleteQueueRingBuffer(QueueRingBuffer* queue);

/**
 * @brief Получение длины очереди
 * 
 * @param queue Указатель на очередь
 * @return int Длина очереди
 */
int LenghtQueueRingBuffer(QueueRingBuffer* queue);