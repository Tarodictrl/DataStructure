#pragma once
#include "../Model/HashTable/HashTable.h"
#include <string>

using namespace std;

/**
 * Õðàíèò äàííûå î ñëîâàðå.
 */
struct Dictionary
{
	/**
	 * Õåø-òàáëèöà.
	 */
	HashTable* Table = new HashTable;
};

/**
 * Äîáàâëÿåò ýëåìåíò â ñëîâàðü.
 */
bool AddItem(Dictionary* dict, string value, string key);

/**
 * Óäàëÿåò ýëåìåíò èç ñëîâàðÿ.
 */
int RemoveItem(Dictionary* dict, string key);

/**
 * Ïîèñê ýëåìåíòà â ñëîâàðå.
 */
string FindItem(Dictionary* dict, string key);

/**
 * Óäàëåíèå ñëîâàðÿ.
 */
void DeleteDictionary(Dictionary* dict);