#include "iostream"
#include "Services/Validator.h"
#include "Model/Stack/Stack.h"
#include "Menu/MenuStack.h"
#include "Menu/MenuRingBuffer.h"

using namespace std;

int main()
{
    while (true)
    {
        system("cls");
        cout << "1. Working with the stack" << endl;
        cout << "2. Working with the ring buffer" << endl;
        cout << "3. Working with a queue based on a ring buffer." << endl;
        cout << "4. Working with a queue on two stacks." << endl;

        int choise = CheckingForDigit("Enter the number of the task you want to solve: ");
        switch (choise)
        {
            case 1:
                system("cls");
                MenuStack();
                break;
            case 2:
                system("cls");
                MenuRingBuffer();
                break;
            case 3:
                system("cls");
                break;
            case 4:
                system("cls");
                break;
            default:
                cout << "Incorrect number!" << endl;
                break;
        }
    }
}