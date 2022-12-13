#include "iostream"
#include "Actions.h"
#include "DoubleLinkedList.h"
#include "chrono"
#include <ctime>

using namespace std;

int CheckForDigit()
{
    int element;
    while (true)
    {
        cin >> element;

        if (!cin.fail()) return element;
        
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Error! Enter the number!: ";
    }
}

void AddElement(List* list)
{
    cout << "Enter value: ";
    int value = CheckForDigit();
    Add(list, value);
    PrintList(list);
}

void RemoveElement(List* list)
{
    cout << "Enter index: ";
    int index = CheckForDigit();
    if (index < 0 || index >= list->Length)
    {
        cout << "Error! Index out of range!" << endl;
        system("pause");
        return;
    }
    Remove(list, index);
    PrintList(list);
}


void InsertElementInEnd(List* list)
{
    cout << "Enter value: ";
    int value = CheckForDigit();
    InsertInEnd(list, value);
    PrintList(list);
}

void InsertElementInBegin(List* list)
{
    cout << "Enter value: ";
    int value = CheckForDigit();
    InsertInBegin(list, value);
    PrintList(list);
}


void InsertElementBefore(List* list)
{
    cout << "Enter index: ";
    int index = CheckForDigit();
    cout << "Enter value: ";
    int value = CheckForDigit();
    InsertBefore(list, index, value);
    PrintList(list);
}

void InsertElementAfter(List* list)
{
    cout << "Enter index: ";
    int index = CheckForDigit();
    cout << "Enter value: ";
    int value = CheckForDigit();
    InsertAfter(list, index, value);
    PrintList(list);
}

void SortList(List* list)
{
    InsertionSort(list);
    PrintList(list);
}

void LinearSearchElement(List* list)
{
    cout << "Enter value: ";
    int value = CheckForDigit();
    int index = LinearSearch(list, value);
    if (index == -1)
    {
        cout << "Element not found" << endl;
    }
    else
    {
        cout << "Element found at index: " << index << endl;
    }
    system("pause");
}

void OutputList(List* list)
{
    PrintList(list);
}

void RandomValues(List* list, int count)
{
	srand(time(nullptr));

	for (int i = 0; i < count; i++)
	{
		Add(list, rand() % 100);
	}
}

void ConductResearch() 
{
	List* list = new List();

	for (int step = 1000000; step <= 5000000; step += 1000000)
	{
		int randomValue = rand() % 20 - 10;
        Clear(list);
		RandomValues(list, step);
        auto start = chrono::steady_clock::now();
		//InsertBefore(list, list->Length/2, randomValue);
		//InsertInBegin(list, randomValue);
		Remove(list, list->Length / 2);
		auto end = chrono::steady_clock::now();
        auto time = chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		std::cout << time << ", " << step << endl;
	}
    system("pause");
}