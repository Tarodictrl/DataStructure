/**
 * @file main.cpp
 * @author Tarodictrl
 * @version 0.1
 * @date 2022-11-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "iostream"
#include "DynamicArray.h"
#include "DynamicArray.h"
#include "Actions.h"

using namespace std;

int main()
{
    DynamicArray *array = new DynamicArray();

    InitDynamicArray(array);
    cout << "0. Close program.\n"
            "1. Add a value to the array.\n"
            "2. Delete an array element.\n"
            "3. Insert an element by index into the array.\n"
            "4. Sort the array.\n"
            "5. Linear element search.\n"
            "6. Binary element search.\n"
            "7. Recreate the array.\n"
            "8. Output an array \n"
         << endl;
    cout << endl;

    while (true)
    {
        cout << "Enter the action number: ";
        int number = CheckForDigit();
        switch (number)
        {
        case 0:
            delete[] array->Array;
            delete array;
            return -1;
        case 1:
            AddElement(array);
            break;
        case 2:
            RemoveElement(array);
            break;
        case 3:
            InsertElement(array);
            break;
        case 4:
            SortArray(array);
            break;
        case 5:
            LinearSearchElement(array);
            break;
        case 6:
            BinarySearchElement(array);
            break;
        case 7:
            RecreateDynamicArray(array);
            break;
        case 8:
            PrintDynamicArray(array);
            break;
        default:
            cout << "Incorrect number!" << endl;
            break;
        }
    }
}
