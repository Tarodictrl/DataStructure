#pragma once
#include "../Node/Node.h"
#include <string>

using namespace std;


struct HashTable
{
	/**
	 * @brief Growth factor for rehashing.
	 * 
	 */
	const int GrowthFactor = 2;

	/**
	 * @brief Коэффициент заполненности. 
	 * 
	 */
	float CoefficientOccupancy = 4.0 / 3.0;

	/**
	 * @brief Количество элементов в таблице.
	 * 
	 */
	int Count;

	/**
	 * @brief Размер таблицы.
	 * 
	 */
	int Capacity;

	/**
	 * @brief Массив указателей на узлы.
	 * 
	 */
	Node** Array;
};


/**
 * @brief Инициализация таблицы.
 * 
 * @param capacity Размер таблицы.
 * @return HashTable* Указатель на таблицу.
 */
HashTable* InitHashTable(int capacity);

/**
 * @brief Добавление элемента в таблицу.
 * 
 * @param table Указатель на таблицу.
 * @param key Ключ.
 * @param value Значение.
 * @return true Если добавление прошло успешно.
 * @return false Если добавление не прошло.
 */
bool AddElement(HashTable* table, string key, string value);

/**
 * @brief Удаление элемента из таблицы.
 * 
 * @param table Указатель на таблицу.
 * @param key Ключ.
 * @return int Ошибку
 */
int RemoveElement(HashTable* table, string key);

/**
 * @brief Поиск элемента в таблице.
 * 
 * @param table Указатель на таблицу.
 * @param key Ключ.
 * @return string Элемент.
 */
string FindElement(HashTable* table, string key);

/**
 * @brief Перехеширование таблицы.
 * 
 * @param table Указатель на таблицу.
 * @return HashTable* Указатель на таблицу.
 */
HashTable* Rehashing(HashTable* table); 

/**
 * @brief Функция хеширования.
 * 
 * @param capacity Вместимость таблицы.
 * @param key Ключ.
 * @return int Индекс.
 */
int HashFunction(int capacity, string key);

/**
 * @brief Разрешение коллизий.
 * 
 * @param first Первый эллемент.
 * @param node Новый эллемент.
 * @return true Если коллизия разрешена.
 * @return false Если коллизия не разрешена.
 */
bool ResolveCollisions(Node* first, Node* node);