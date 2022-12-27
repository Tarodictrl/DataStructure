#include "MenuRingBufferQueue.h"
#include <iostream>
#include "../Services/Validator.h"
#include "MenuRingBuffer.h"
#include "../Model/Queue/RingBufferQueue.h"

using namespace std;

void PrintRingBufferQueue(QueueRingBuffer *queue)
{
    int index = queue->Buffer->IndexOutput;

    for (int i = 0; i < queue->Buffer->UsedMemory; i++)
    {
        cout << queue->Buffer->Buffer[index++] << " -> ";

        if (index > queue->Buffer->Size - 1)
        {
            index = 0;
        }
    }

    cout << endl;
}

void MenuRingBufferQueue()
{
    system("cls");
    QueueRingBuffer *queue = nullptr;

    while (true)
    {
        cout << "0. Clear console." << endl;
        cout << "1. Init queue." << endl;
        cout << "2. Add element in queue." << endl;
        cout << "3. Get element from queue." << endl;
        cout << "4. Delete queue." << endl;
        cout << "5. Back." << endl;

        if (queue != nullptr)
        {
            PrintRingBufferQueue(queue);
        }
        int key = CheckingForDigit("Enter the number of the task: ");

        switch (key)
        {
            // TODO: Done
            case 0:
            {
                system("cls");
                break;
            }
            case 1:
            {
                if (queue != nullptr)
                {
                    cout << "Queue already created!" << endl;
                }
                else
                {
                    queue = InitQueueRingBuffer(4);
                    system("cls");
                    cout << "Queue created" << endl;
                }

                break;
            }
            case 2:
            {
                if (queue != nullptr)
                {
                    int value = CheckingForDigit("Enter value: ");
                    EnqueueRingBuffer(queue, value);
                    system("cls");
                    cout << "Value added." << endl;
                }
                else
                {
                    system("cls");
                    cout << "The queue is not initialized!" << endl;
                }

                break;
            }
            case 3:
            {
                if (queue != nullptr)
                {
                    if (LenghtQueueRingBuffer(queue) > 0)
                    {
                        system("cls");
                        cout << "Value: " << DequeueRingBuffer(queue) << endl;
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
                    cout << "The queue is not initialized!" << endl;
                }

                break;
            }
            case 4:
            {
                if (queue != nullptr)
                {
                    DeleteQueueRingBuffer(queue);
                    delete queue;
                    queue = nullptr;
                    system("cls");
                    cout << "Queue deleted." << endl;
                }

                break;
            }
            case 5:
            {
                system("cls");
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