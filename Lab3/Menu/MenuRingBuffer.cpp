#include "MenuRingBuffer.h"
#include "../Model/RingBuffer/RingBuffer.h"
#include "Validator.h"
#include <iostream>

using namespace std;

void PrintRingBuffer(RingBuffer* buffer)
{
	int index = buffer->IndexOutput;

	for (int i = 0; i < buffer->UsedMemory; i++)
	{
		cout << buffer->Buffer[index++] << " -> ";

		if (index > buffer->Size - 1)
		{
			index = 0;
		}
	}

	cout << endl;
	cout << "Buffer size: " << buffer->Size << endl;
}

void MenuRingBuffer()
{ 
    system("cls");
    RingBuffer* buffer = nullptr;
    while (true)
    {
        cout << "0. Clear console" << endl;
        cout << "1. Create buffer" << endl;
        cout << "2. Add element" << endl;
        cout << "3. Get element" << endl;
        cout << "4. Get free memory info" << endl;
        cout << "5. Get used memory info" << endl;
        cout << "6. Delete buffer" << endl;
        cout << "7. Back" << endl;

        if (buffer != nullptr)
        {
            PrintRingBuffer(buffer);
        }

        int choise = CheckingForDigit("Enter the number of the task: ");
        switch (choise)
        {
            //TODO: Done
            case 0:
            {
                system("cls");
                break;
            }
            case 1:
            {
                if (buffer != nullptr)
                {
                    system("cls");
                    cout << "Buffer already exists!" << endl;
                    break;
                }
                buffer = InitRingBuffer(4);
                system("cls");
                cout << "Buffer created" << endl;
                break;
            }
            case 2:
            {
                if (buffer == nullptr)
                {
                    system("cls");
                    cout << "Buffer does not exist!" << endl;
                    break;
                }
                int value = CheckingForDigit("Enter the value: ");
                system("cls");
                cout << "Value added" << endl;
                PushRingBuffer(buffer, value);
                break;
            }
            case 3:
            {
                if (buffer == nullptr)
                {
                    system("cls");
                    cout << "Buffer does not exist!" << endl;
                    break;
                }
                int value = PopRingBuffer(buffer);
                system("cls");
                cout << "Value: " << value << endl;
                break;
            }
            case 4:
            {
                if (buffer == nullptr)
                {
                    system("cls");
                    cout << "Buffer does not exist!" << endl;
                    break;
                }
                system("cls");
                cout << "Free memory: " << FreeMemoryInfo(buffer) << endl;
                break;
            }
            case 5:
            {
                if (buffer == nullptr)
                {
                    system("cls");
                    cout << "Buffer does not exist!" << endl;
                    break;
                }
                system("cls");
                cout << "Used memory: " << UsedMemoryInfo(buffer) << endl;
                break;
            }
            case 6:
            {
                delete[] buffer;
                buffer = nullptr;
                system("cls");
                cout << "Buffer deleted" << endl;
                break;
            }
            
            case 7: return;
        }
    }
    
}