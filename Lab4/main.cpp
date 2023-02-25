#include <iostream>
#include "Menu/MenuDictionary.h"
#include "Menu/MenuHashTable.h"
#include "Services/Validator.h"
#include "string"

using namespace std;


int main()
{
	while (true)
	{
		system("cls");
		cout << "1. HashTable." << endl;
		cout << "2. Dictionary." << endl;
		cout << "3. Exit." << endl;

		int number = AssertIsDigit("Select actions: ");

		switch (number)
		{
			case 1:
				MenuHashTable();
				break;
			case 2:
				MenuDictionary();
				break;
			case 3:
			{
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