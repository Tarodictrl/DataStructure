
#include <iostream>
#include "../Services/Validator.h"
#include "../Model/Dictionary/Dictionary.h"
#include "string"
#include "MenuDictionary.h"

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
			//TODO: DONE
			cout << "[" << i << "]" << "Key: " << 
				current->Key << "\t Value: " << current->Value;
			current = current->Next;
			cout << endl;
		}
	}
	cout << "\n" << endl;
}

void MenuDictionary()
{
	Dictionary* dictionary = new Dictionary;
    system("cls");
	while (true)
	{
        
		cout << "1. Add." << endl;
		cout << "2. Delete." << endl;
		cout << "4. Find." << endl;
		cout << "5. Exit." << endl;

		int number = AssertIsDigit("Select actions: ");

		switch (number)
		{
			case 1: 
			{
				string key = AssertIsNotEmptyString("Enter key: ");
				string value = AssertIsNotEmptyString("Enter value: ");
				if (!AddItem(dictionary, value, key))
                {
                    cout << "" << endl;
                }
				
                system("cls");
				PrintDictionary(dictionary);
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

                system("cls");
				PrintDictionary(dictionary);

				break;
			}
			case 3:
			{
                system("cls");
				PrintDictionary(dictionary);
				break;
			}   
			case 4:
			{
				string key = AssertIsNotEmptyString("Enter key: ");

				string searchValueDictionary = FindItem(dictionary, key);

				system("cls");
				PrintDictionary(dictionary);

				if (searchValueDictionary == "")
				{
					cout << "Value not found in dictionary!" << endl;
				}
				else
				{
					cout << "Value in dictionary: " << searchValueDictionary << endl;
				}
				break;
			}
			case 5:
			{
				DeleteDictionary(dictionary);
				delete dictionary;
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