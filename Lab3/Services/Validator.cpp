#include "Validator.h"
#include <iostream>


using namespace std;

int CheckingForDigit(const char* text)
{
	if (text != "")
	{
		cout << text;
	}

	int value;
	while (true)
	{
		cin >> value;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
            cout << "You entered not a number. Try again." << endl;
            cout << text;
			continue;
		}

		cin.ignore(32767, '\n');
		if (cin.gcount() > 1)
		{
            cout << "You entered not a number. Try again." << endl;
            cout << text;
			continue;
		}

		break;
	}

	return value;
}