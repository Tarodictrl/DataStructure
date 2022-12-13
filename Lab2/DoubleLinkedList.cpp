#include "iostream"
#include "DoubleLinkedList.h"

using namespace std;

void InitList(List *list)
{
    list->Head = nullptr;
    list->Tail = nullptr;
    list->Length = 0;
}

void Add(List *list, int value)
{
    ListItem *item = new ListItem();
    item->Value = value;
    item->Next = nullptr;
    item->Prev = list->Tail;

    if (list->Tail != nullptr)
    {
        list->Tail->Next = item;
    }

    if (list->Head == nullptr)
    {
        list->Head = item;
    }

    list->Length++;
    list->Tail = item;
}

void Remove(List *list, int index)
{
    if (index < 0 || index >= list->Length)
    {
        return;
    }

    ListItem *item = list->Head;
    for (int i = 0; i < index; i++)
    {
        item = item->Next;
    }

    if (item == list->Head)
    {
        list->Head = item->Next;
    }
    else
    {
        item->Prev->Next = item->Next;
    }

    if (item == list->Tail)
    {
        list->Tail = item->Prev;
    }
    else
    {
        item->Next->Prev = item->Prev;
    }

    list->Length--;
    delete item;
}

void InsertInBegin(List *list, int value)
{
    ListItem* item = new ListItem();

	item->Value = value;
	item->Prev = nullptr;
	item->Next = list->Head;

	if (list->Head != nullptr)
	{
		list->Head->Prev = item;
	}

	if (list->Tail == nullptr)
	{
		list->Tail = item;
	}

	list->Length++;
	list->Head = item;
}

void InsertInEnd(List *list, int value)
{
    ListItem *item = new ListItem();
    item->Value = value;
    item->Next = nullptr;
    item->Prev = list->Tail;

    if (list->Head == nullptr)
    {
        list->Head = item;
        list->Tail = item;
    }
    else
    {
        item->Prev = list->Tail;
        list->Tail->Next = item;
        list->Tail = item;
    }
    list->Length++;
}

void InsertAfter(List *list, int index, int value)
{
    if (index < 0 || index >= list->Length)
    {
        return;
    }

    ListItem *item = list->Head;
    for (int i = 0; i < index; i++)
    {
        item = item->Next;
    }

    ListItem *newItem = new ListItem();
    newItem->Value = value;
    newItem->Next = item->Next;
    newItem->Prev = item;

    if (item->Next != nullptr)
    {
        item->Next->Prev = newItem;
    }
    else
    {
        list->Tail = newItem;
    }

    item->Next = newItem;
    list->Length++;
}

void InsertBefore(List *list, int index, int value)
{
    if (index < 0 || index >= list->Length)
    {
        return;
    }

    ListItem *item = list->Head;
    for (int i = 0; i < index; i++)
    {
        item = item->Next;
    }

    ListItem *newItem = new ListItem();
    newItem->Value = value;
    newItem->Next = item;
    newItem->Prev = item->Prev;

    if (item->Prev != nullptr)
    {
        item->Prev->Next = newItem;
    }
    else
    {
        list->Head = newItem;
    }

    item->Prev = newItem;
    list->Length++;
}

void InsertionSort(List *list)
{
    if (list->Length < 2)
    {
        return;
    }

    ListItem *item = list->Head->Next;
    while (item != nullptr)
    {
        ListItem *prevItem = item->Prev;
        while (prevItem != nullptr && prevItem->Value > item->Value)
        {
            prevItem = prevItem->Prev;
        }

        if (prevItem == nullptr)
        {
            item->Prev->Next = item->Next;
            if (item->Next != nullptr)
            {
                item->Next->Prev = item->Prev;
            }
            else
            {
                list->Tail = item->Prev;
            }

            item->Next = list->Head;
            list->Head->Prev = item;
            list->Head = item;
            item->Prev = nullptr;
        }
        else if (prevItem->Next != item)
        {
            item->Prev->Next = item->Next;
            if (item->Next != nullptr)
            {
                item->Next->Prev = item->Prev;
            }
            else
            {
                list->Tail = item->Prev;
            }

            item->Next = prevItem->Next;
            item->Next->Prev = item;
            prevItem->Next = item;
            item->Prev = prevItem;
        }

        item = item->Next;
    }
}

int LinearSearch(List *list, int value)
{
    ListItem *item = list->Head;
    for (int i = 0; i < list->Length; i++)
    {
        if (item->Value == value)
        {
            return i;
        }
        item = item->Next;
    }
    return -1;
}

void PrintList(List *list)
{
    ListItem *item = list->Head;
    cout << "[ ";
    while (item != nullptr)
    {
        std::cout << item->Value << " ";
        item = item->Next;
    }
    cout << "]" << endl;
}

void Clear(List *list)
{
    if (list->Head == nullptr)
    {
        return;
    }

    int index = 0;
    ListItem *temp = list->Head->Next;

    while (temp != nullptr)
    {
        delete temp->Prev;
        list->Length--;
        temp = temp->Next;
    }

    delete temp;
    list->Head = nullptr;
    list->Tail = nullptr;
}