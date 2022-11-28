/**
 * @file Actions.cpp
 * @author Tarodictrl
 * @version 0.1
 * @date 2022-11-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include "Actions.h"
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

void InitDynamicArray(DynamicArray *dynamicArray)
{
    CreateDynamicArray(dynamicArray);
    cout << "Array created!" << endl;
}

void AddElement(DynamicArray *dynamicArray)
{
    cout << "Enter the value to add: ";
    int element = CheckForDigit();
    Add(dynamicArray, element);
    PrintDynamicArray(dynamicArray);
}

void RemoveElement(DynamicArray *dynamicArray)
{
    cout << "Enter the index of the item to delete: ";
    int index = CheckForDigit();
    if (index > dynamicArray->Length)
    {
        cout << "Error! Index out of range!" << endl;
        return;
    }
    RemoveAt(dynamicArray, index);
    PrintDynamicArray(dynamicArray);
}

void InsertElement(DynamicArray *dynamicArray)
{
    cout << "Enter the numeric value to insert: ";
    int element = CheckForDigit();
    cout << "Enter the index: ";
    int index = CheckForDigit();
    if (index > dynamicArray->Length)
    {
        cout << "Error! Index out of range!" << endl;
        return;
    }
    Insert(dynamicArray, element, index);
    PrintDynamicArray(dynamicArray);
}

void SortArray(DynamicArray *dynamicArray)
{
    cout << "Sorted array: ";
    SortingDynamicArray(dynamicArray);
    PrintDynamicArray(dynamicArray);
    dynamicArray->IsSorted = true;
}

void LinearSearchElement(DynamicArray *dynamicArray)
{
    cout << "Enter the item to search for: ";
    int element = CheckForDigit();

    int indexOfFoundElement = LinearSearch(dynamicArray, element);

    cout << "The desired value: " << element << " Element index: " << indexOfFoundElement << endl;
}

void BinarySearchElement(DynamicArray *dynamicArray)
{
    if (!dynamicArray->IsSorted)
    {
        cout << "The dynamic array must be sorted!" << endl;
        return;
    }

    cout << "Enter the desired element: ";
    int element = CheckForDigit();

    int indexOfFoundElement = BinarySearch(dynamicArray, element);

    cout << "The desired element: " << element << " Element index:  " << indexOfFoundElement << endl;
}

void RecreateDynamicArray(DynamicArray *dynamicArray)
{
    delete[] dynamicArray->Array;
    CreateDynamicArray(dynamicArray);
}