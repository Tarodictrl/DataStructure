#include "MenuRingBufferQueue.h"
#include "../Services/Validator.h"
#include <iostream>
#include "../Model/Queue/StackQueue.h"

using namespace std;

//TODO: Done
void PrintStackQueue(Stack *stack)
{
    cout << "[ ";
    for (int i = stack->Top; i >= 0; i--)
    {
        cout << stack->Buffer[i] << " ";
    }
    cout << "]" << endl;
    cout << endl;
}

void MenuStackQueue()
{
    system("cls");
    StackQueue *queue = nullptr;

    while (true)
    {
        cout << "0. Clear console" << endl;
        cout << "1. Init queue" << endl;
        cout << "2. Add element" << endl;
        cout << "3. Get element" << endl;
        cout << "4. Delete queue" << endl;
        cout << "5. Back" << endl;

        if (queue != nullptr)
        {
            cout << "Stack for input data" << endl;
            PrintStackQueue(queue->InputStack);
            cout << "Stack for output data" << endl;
            PrintStackQueue(queue->OutputStack);
        }

        int key = CheckingForDigit("Enter the number of the task: ");

        switch (key)
        {
            case 0:
            {
                system("cls");
                break;
            }
            case 1:
            {
                if (queue != nullptr)
                {
                    system("cls");
                    cout << "The queue has already been initialized" << endl;
                    break;
                }
                queue = InitStackQueue(4);
                system("cls");
                cout << "Queue initialized" << endl;
                break;
            }
            case 2:
            {
                if (queue == nullptr)
                {
                    system("cls");
                    cout << "The queue was not initialized" << endl;
                    break;
                }
                int data = CheckingForDigit("Enter the data: ");
                Enqueue(queue, data);
                system("cls");
                cout << "Data added" << endl;
                break;
            }
            case 3:
            {
                if (queue)
                {
                    if (LengthStackQueue(queue) > 0)
                    {
                        system("cls");
                        cout << "Value: " << Dequeue(queue) << endl;
                    }
                    else
                    {
                        system("cls");
                        cout << "The queue is empty!" << endl;
                    }
                }
                else
                {
                    system("cls");
                    cout << "The queue was not created." << endl;
                }
                break;
            }
            case 4:
            {
                if (queue)
                {
                    DeleteStackQueue(queue);
                    delete queue;
                    queue = nullptr;
                    system("cls");
                    cout << "The queue has been deleted." << endl;
                }
                else
                {
                    system("cls");
                    cout << "The queue was not created." << endl;
                }

                break;
            }
            case 5:
            {
                if (queue != nullptr)
                {
                    DeleteStackQueue(queue);
                    delete queue;
                    system("cls");
                }
                return;
            }
            default:
            {
                system("cls");
                cout << "Invalid number!" << endl;
                break;
            }
        }
    }
}