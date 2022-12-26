#pragma once


/**
 * Хранит информацию о буфере.
 */
struct RingBuffer 
{
	/**
	 * Свободное место в буфере.
	 */
	int FreeMemory;

	/**
	 * Занятое место в буфере.
	 */
	int UsedMemory;

	/**
	 * Буфер.
	 */
	int* Buffer;

	/**
	 * Размер буфера.
	 */
	int Size;
	
	/**
	 * Индекс в который производится запись.
	 */
	int IndexInput;

	/**
	 * Индекс из которого производится чтение.
	 */
	int IndexOutput;

	/**
	 * Фактор роста.
	 */
	const int GrowthFactor = 2;
};

/**
 * Инициализирует кольцевой буфер.
 */
RingBuffer* InitRingBuffer(int sizeBuffer);

/**
 * Добавляет в кольцевой буфер.
 */
void PushRingBuffer(RingBuffer* buffer, int data);

/**
 * Возвращает из кольцевой буфера.
 */
int PopRingBuffer(RingBuffer* buffer);

/**
 * Вовращает информацию о свободном месте в кольцевом буфере.
 */
int FreeMemoryInfo(RingBuffer* buffer);

/**
 * Возвращает информацию о занятом месте в кольцевом буфере.
 */
int UsedMemoryInfo(RingBuffer* buffer);

/**
 * Изменяет размер буфера.
 */
void ResizeRingBuffer(RingBuffer* buffer);