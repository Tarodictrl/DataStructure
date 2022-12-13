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

	for (int step = 100000; step <= 4000000; step += 100000)
	{
		int randomValue = rand() % 20 - 10;
        Clear(list);
		RandomValues(list, step);
        auto start = chrono::steady_clock::now();
		//InsertBefore(list, list->Length/2, randomValue);
		InsertInBegin(list, 10);
		//Remove(list, list->Length / 2);
		auto end = chrono::steady_clock::now();
        auto time = chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
		std::cout << time << ", " << step << endl;
	}
    system("pause");
}