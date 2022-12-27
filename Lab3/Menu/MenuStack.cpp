#include "MenuStack.h"
#include "Validator.h"
#include "iostream"
#include "../Model/Stack/Stack.h"

using namespace std;

void PrintStack(Stack *stack)
{
    cout << "[ ";
    for (int i = stack->Top; i >= 0; i--)
    {
        cout << stack->Buffer[i] << " ";
    }
    cout << "]" << endl;
}

void MenuStack()
{
    Stack *stack = nullptr;
    system("cls");
    while (true)
    {
        cout << "0. Clear console" << endl;
        cout << "1. Create stack" << endl;
        cout << "2. Add element" << endl;
        cout << "3. Get element" << endl;
        cout << "4. Delete stack" << endl;
        cout << "5. Back" << endl;

        if (stack != nullptr)
        {
            PrintStack(stack);
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
                if (stack != nullptr)
                {
                    system("cls");
                    cout << "Stack already exists!" << endl;
                    break;
                }
                stack = InitStack(4);
                system("cls");
                cout << "Stack created" << endl;
                break;
            }
            case 2:
            {
                if (stack == nullptr)
                {
                    system("cls");
                    cout << "Stack does not exist!" << endl;
                    break;
                }
                int value = CheckingForDigit("Enter the value: ");
                Push(stack, value);
                system("cls");
                cout << "Element added" << endl;
                break;
            }
            case 3:
            {
                if (stack == nullptr)
                {
                    system("cls");
                    cout << "Stack does not exist" << endl;
                    break;
                }
                cout << Pop(stack) << endl;
                system("cls");
                cout << "Element got" << endl;
                break;
            }
            case 4:
            {
                if (stack == nullptr)
                {
                    system("cls");
                    cout << "Stack does not exist!" << endl;
                    break;
                }
                delete stack;
                stack = nullptr;
                system("cls");
                cout << "Stack deleted" << endl;
                break;
            }
            
            case 5: return;
        }
    }
}