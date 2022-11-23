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

void InitDynamicArray(DynamicArray *dynamicArray)
{
    CreateDynamicArray(dynamicArray);
    cout << "Array created!" << endl;
}

void AddElement(DynamicArray *dynamicArray)
{
    int element;
    bool run = true;
    while (run)
    {
        cout << "Enter the element: ";
        cin >> element;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Error! Enter the number!" << endl;
        }
        else
        {
            run = false;
        }
    }
    Add(dynamicArray, element);
    PrintDynamicArray(dynamicArray);
}

void RemoveElement(DynamicArray *dynamicArray)
{
    int index;

    cout << "Enter the index of the item to delete: ";
    cin >> index;

    RemoveAt(dynamicArray, index);
    PrintDynamicArray(dynamicArray);
}

void InsertElement(DynamicArray *dynamicArray)
{
    int element;
    int index;

    cout << "Enter the numeric value to insert: ";
    cin >> element;
    cout << "Enter the index: ";
    cin >> index;

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
    int element;
    int indexOfFoundElement;

    cout << "Enter the item to search for: ";
    cin >> element;

    indexOfFoundElement = LinearSearch(dynamicArray, element);

    cout << "The desired value: " << element << " Element index: " << indexOfFoundElement << endl;
}

void BinarySearchElement(DynamicArray *dynamicArray)
{
    if (!dynamicArray->IsSorted)
    {
        cout << "The dynamic array must be sorted!" << endl;
        return;
    }

    int element;
    int indexOfFoundElement;

    cout << "Enter the desired element: ";
    cin >> element;

    indexOfFoundElement = BinarySearch(dynamicArray, element);

    cout << "The desired element: " << element << " Element index:  " << indexOfFoundElement << endl;
}

void RecreateDynamicArray(DynamicArray *dynamicArray)
{
    delete[] dynamicArray->Array;
    CreateDynamicArray(dynamicArray);
}