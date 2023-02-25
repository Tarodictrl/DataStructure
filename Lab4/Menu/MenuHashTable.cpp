#include <iostream>
#include "../Services/Validator.h"
#include "../Model/Dictionary/Dictionary.h"
#include "MenuDictionary.h"
#include "string"

using namespace std;

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
			//TODO: DONE
			cout << "[" << i << "]" << "Key: " << current->
				Key << "\t Value: " << current->Value << endl;
			continue;
		}
		while (current != nullptr)
		{
			//TODO: DONE
			cout << "[" << i << "]" << "Key: " << current->
				Key << "\t Value: " << current->Value << " -> ";
			current = current->Next;
		}
	}
    cout << "\n" << endl;
}

void MenuHashTable()
{
	HashTable* table = InitHashTable(4);
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
				AddElement(table, key, value);
				
				float maxOccupancyDictionary = 
					table->Capacity * table->CoefficientOccupancy;

				if (table->Count >= maxOccupancyDictionary)
				{
					Rehashing(table);
					
				}

				float maxOccupancyTable =
					table->Capacity * table->CoefficientOccupancy;

				if (table->Count >= maxOccupancyTable)
				{
					Rehashing(table);
				}
                system("cls");
				PrintHashTable(table);
				break;
			}
			case 2:
			{
				string key = AssertIsNotEmptyString("Enter key: ");

				if (RemoveElement(table, key) == -1)
				{
                    system("cls");
					cout << "Error! Not found key in hashtable!" << endl;
				}

                system("cls");
				PrintHashTable(table);

				break;
			}
			case 3:
			{
                system("cls");
				PrintHashTable(table);
				break;
			}   
			case 4:
			{
				string key = AssertIsNotEmptyString("Enter key: ");

				string searchValueTable = FindElement(table, key);

                system("cls");
                PrintHashTable(table);
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
				delete table;
				return;
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