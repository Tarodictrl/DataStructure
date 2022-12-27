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
 * @brief Инициализирует кольцевой буфер.
 * 
 * @param sizeBuffer Размер буфера.
 * @return RingBuffer* Указатель на буфер.
 */
RingBuffer* InitRingBuffer(int sizeBuffer);

/**
 * @brief Добавляет в кольцевой буфер.
 * 
 * @param buffer Указатель на буфер.
 * @param data Значение которое нужно добавить.
 */
void PushRingBuffer(RingBuffer* buffer, int data);

/**
 * @brief Удаляет из кольцевого буфера.
 * 
 * @param buffer Указатель на буфер.
 * @return int Значение которое было удалено.
 */
int PopRingBuffer(RingBuffer* buffer);

/**
 * @brief Возвращает информацию о свободном месте в кольцевом буфере.
 * 
 * @param buffer Указатель на буфер.
 * @return int Свободное место в буфере.
 */
int FreeMemoryInfo(RingBuffer* buffer);

/**
 * @brief Возвращает информацию о занятом месте в кольцевом буфере.
 * 
 * @param buffer Указатель на буфер.
 * @return int Занятое место в буфере.
 */
int UsedMemoryInfo(RingBuffer* buffer);

/**
 * @brief Изменяет размер кольцевого буфера.
 * 
 * @param buffer Указатель на буфер. 
 */
void ResizeRingBuffer(RingBuffer* buffer);