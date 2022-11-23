/**
 * @file DynamicArray.cpp
 * @author Tarodictrl
 * @version 0.1
 * @date 2022-11-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "iostream"
#include "DynamicArray.h"

using namespace std;

const int capacity = 4;

void CreateDynamicArray(DynamicArray *array)
{
    array->Capacity = capacity;
    array->Length = 0;
    array->Growth = 2;
    array->Array = new int[array->Capacity];
    array->IsSorted = false;
}

void ResizeDynamicArray(DynamicArray *array)
{
    if (array->Length >= array->Capacity)
    {
        array->Capacity *= array->Growth;
    }
    else if (array->Length <= array->Capacity / array->Growth)
    {
        array->Capacity /= array->Growth;
    }

    int *temp = new int[array->Capacity];

    for (int i = 0; i < array->Length; i++)
    {
        temp[i] = array->Array[i];
    }

    delete[] array->Array;
    array->Array = temp;
}

void Add(DynamicArray *array, int value)
{
    array->Length++;
    ResizeDynamicArray(array);
    array->Array[array->Length - 1] = value;
    array->IsSorted = false;
}

void PrintDynamicArray(DynamicArray *array)
{
    cout << "[";
    for (int i = 0; i < array->Length; ++i)
    {
        cout << array->Array[i];
        if (i < array->Length - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

int LinearSearch(DynamicArray *array, int value)
{
    for (int i = 0; i < array->Length; i++)
    {
        if (array->Array[i] == value)
        {
            return i;
        }
    }
    return -1;
}

int BinarySearch(DynamicArray *array, int element)
{
    int first = 0;
    int last = array->Length - 1;
    int middle;

    while (first < last)
    {
        middle = (first + last) / 2;

        if (element <= array->Array[middle])
        {
            last = middle;
        }
        else
        {
            first = middle + 1;
        }
    }

    return (first == array->Length || array->Array[first] != element) ? -1 : first;
}

void SortingDynamicArray(DynamicArray *array)
{
    {
        for (int i = 0; i < array->Length; i++)
        {
            for (int j = i + 1; j < array->Length; j++)
            {
                if (array->Array[j] < array->Array[i])
                {
                    swap(array->Array[j], array->Array[i]);
                }
            }
        }
    }
}

int RemoveAt(DynamicArray *array, int index)
{
    if (CheckIndexOutRange(array, index))
    {
        return -1;
    }

    for (int i = index; i < array->Length - 1; i++)
    {
        array->Array[i] = array->Array[i + 1];
    }

    array->Length--;
    ResizeDynamicArray(array);
    return 0;
}

int Insert(DynamicArray *array, int element, int index)
{
    if (CheckIndexOutRange(array, index))
    {
        return -1;
    }

    array->Length++;
    ResizeDynamicArray(array);

    for (int i = 0; i < array->Length - index; i++)
    {
        array->Array[array->Length - i] = array->Array[array->Length - i - 1];
    }

    array->Array[index] = element;
    array->IsSorted = false;
    return 0;
}

bool CheckIndexOutRange(DynamicArray *array, int index)
{
    if (index < 0 || index > array->Length - 1)
    {
        return true;
    }
    return false;
}