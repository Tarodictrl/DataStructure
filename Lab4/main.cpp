#include <iostream>
#include "Services/Validator.h"
#include "Model/Dictionary/Dictionary.h"
#include "string"

using namespace std;

void PrintDictionary(Dictionary* dict)
{
	Node* current;
	for (int i = 0; i < dict->Table->Capacity; i++)
	{
		current = dict->Table->Array[i];

		if (current == nullptr)
		{
			cout << "";
			continue;
		}

		while (current != nullptr)
		{
			cout << "[" << i << "]" << "Key: " << current->Key << "\t Value: " << current->Value;
			current = current->Next;
			cout << endl;
		}
	}
}

void PrintHashTable(HashTable* table)
{
	cout << table->Count << endl;
	Node* current;
	for (int i = 0; i < table->Capacity; i++)
	{
		current = table->Array[i];
		if (current == nullptr)
		{
			cout << "[" << i << "]" << "NULL\n";
			continue;
		}
		if (current->Next == nullptr)
		{
			cout << "[" << i << "]" << "Key: " << current->Key << "\t Value: " << current->Value << endl;
			continue;
		}
		while (current != nullptr)
		{
			cout << "[" << i << "]" << "Key: " << current->Key << "\t Value: " << current->Value << " -> ";
			current = current->Next;
		}
		cout << endl;
	}
}

void PrintInfo(Dictionary* dictionary, HashTable* table) 
{
	cout << endl;
	cout << "HashTable" << endl;
	cout << "______________________________________________________" << endl;
	PrintHashTable(table);
	cout << "______________________________________________________" << endl;
	cout << endl;
	cout << "Dictionary" << endl;
	cout << "______________________________________________________" << endl;
	PrintDictionary(dictionary);
	cout << "______________________________________________________" << endl;
}

int main()
{
	setlocale(LC_ALL, "ru");

	Dictionary* dictionary = new Dictionary;
	HashTable* hashTable = new HashTable;
	hashTable = InitHashTable(4);
	dictionary->Table = InitHashTable(4);
    system("cls");
	while (true)
	{
        
		cout << "1. Add." << endl;
		cout << "2. Delete." << endl;
		cout << "3. Entere information." << endl;
		cout << "4. Find." << endl;
		cout << "5. Exit." << endl;

		int number = AssertIsDigit("Select actions: ");

		switch (number)
		{
			case 1: 
			{
				string key = AssertIsNotEmptyString("Enter key: ");
				string value = AssertIsNotEmptyString("Enter value: ");
				AddItem(dictionary, value, key);
				AddElement(hashTable, key, value);
				
				float maxOccupancyDictionary =
					dictionary->Table->Capacity * dictionary->Table->CoefficientOccupancy;

				if (dictionary->Table->Count >= maxOccupancyDictionary)
				{
					dictionary->Table = Rehashing(dictionary->Table);
					
				}

				float maxOccupancyTable =
					hashTable->Capacity * hashTable->CoefficientOccupancy;

				if (hashTable->Count >= maxOccupancyTable)
				{
					hashTable = Rehashing(hashTable);
				}
                system("cls");
				PrintInfo(dictionary, hashTable);

				break;
			}
			case 2:
			{
				string key = AssertIsNotEmptyString("Enter key: ");
				
				if (RemoveItem(dictionary, key) == -1)		
				{
                    system("cls");
					cout << "Error! Not found key in dictionary!" << endl;
				}
				if (RemoveElement(hashTable, key) == -1)
				{
                    system("cls");
					cout << "Error! Not found key in hashtable!" << endl;
				}

                system("cls");
				PrintInfo(dictionary, hashTable);

				break;
			}
			case 3:
			{
                system("cls");
				PrintInfo(dictionary, hashTable);
				break;
			}   
			case 4:
			{
                system("cls");
				string key = AssertIsNotEmptyString("Enter key: ");

				string searchValueDictionary = FindItem(dictionary, key);

				string searchValueTable = FindElement(hashTable, key);

				if (searchValueDictionary == "")
				{
					cout << "Value not found in dictionary!" << endl;
				}
				else
				{
					cout << "Value in dictionary: " << searchValueDictionary << endl;
				}

				if (searchValueTable == "")
				{
					cout << "Value not found in hashtable!" << endl;
				}
				else 
				{
					cout << "Value in hashtable: " << searchValueTable << endl;
				}
				break;
			}
			case 5:
			{
				DeleteDictionary(dictionary);
				delete dictionary;
				return 0;
			}
			default:
			{
                system("cls");
				cout << "Incorrect number!" << endl;
				break;
			}
		}
	}
}