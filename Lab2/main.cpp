#include <iostream>
#include "Actions.h"
#include "DoubleLinkedList.h"

using namespace std;

int main()
{
    
    List* list = new List();
    while (true)
    {
        system("cls");
        cout << "0. Close program.\n"
            "1. Add a value to the list.\n"
            "2. Delete an list element.\n"
            "3. Insert an element in the begin of the list.\n"
            "4. Insert an element in the end of the list.\n"
            "5. Insert an element by after into the list.\n"
            "6. Insert an element by before into the list.\n"
            "7. Sort the list.\n"
            "8. Linear element search.\n"
            "9. Recreate the list.\n"
            "10. Conduct research.\n"
         << endl;
        
        OutputList(list);
        cout << endl;
        cout << "Enter the action number: ";
        int number = CheckForDigit();
        switch (number)
        {
            case 0:
                delete list;
                return -1;
            case 1:
                AddElement(list);
                break;
            case 2:
                RemoveElement(list);
                break;
            case 3:
                InsertElementInBegin(list);
                break;
            case 4:
                InsertElementInEnd(list);
                break;
            case 5:
                InsertElementAfter(list);
                break;
            case 6:
                InsertElementBefore(list);
                break;
            case 7:
                SortList(list);
                break;
            case 8:
                LinearSearchElement(list);
                break;
            case 9:
                Clear(list);
                break;
            case 10:
                ConductResearch();
                break;
            default:
                cout << "Error! Enter the number from 0 to 10!" << endl;
                break;
        }
    }
    
}