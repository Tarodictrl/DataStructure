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
	HashTable* Table = InitHashTable(4);
};

//TODO: DONE
/**
 * Добавляет элемент в словарь.
 */
bool AddItem(Dictionary* dictionary, string value, string key);

//TODO: DONE
/**
 * Удаляет элемент из словаря.
 */
int RemoveItem(Dictionary* dictionary, string key);

//TODO: DONE
/**
 * Находит элемент в словаре.
 */
string FindItem(Dictionary* dictionary, string key);

//TODO: DONE
/**
 * Удаляет словарь.
 */
void DeleteDictionary(Dictionary* dictionary);