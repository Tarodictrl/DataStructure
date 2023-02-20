#pragma once
#include "../Model/HashTable/HashTable.h"
#include <string>

using namespace std;

/**
 * Хранит данные о словаре.
 */
struct Dictionary
{
	/**
	 * хэш-таблица.
	 */
	HashTable* Table = new HashTable;
};

/**
 * Добавляет элемент в словарь.
 */
bool AddItem(Dictionary* dict, string value, string key);

/**
 * Удаляет элемент из словаря.
 */
int RemoveItem(Dictionary* dict, string key);

/**
 * Находит элемент в словаре.
 */
string FindItem(Dictionary* dict, string key);

/**
 * Удаляет словарь.
 */
void DeleteDictionary(Dictionary* dict);