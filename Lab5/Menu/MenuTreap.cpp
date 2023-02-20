#include "../Model/Treap/Treap.h"
#include "../Services/Validator.h"
#include <iostream>

void PrintTreap(TreapNode* node, int level)
{
	if (node)
	{
		PrintTreap(node->Right, level + 1);
		for (int i = 0; i < level; i++)
		{
			cout << "	";
		}
		cout << '(' << node->Data << "; " << node->Priority << ')' << endl;
		PrintTreap(node->Left, level + 1);
	}
}

void MenuTreap()
{
	cout << "Treap" << endl;
	Treap* treap = new Treap;

	while (true)
	{
		cout << "1. Add an element with an optimized algorithm." << endl;
		cout << "2. Add an element using a non-optimized algorithm." << endl;
		cout << "3. Remove an element from the tree by an optimized algorithm." << endl;
		cout << "4. Remove an element from the tree using an un-optimized algorithm." << endl;
		cout << "5. Delete." << endl;
		cout << "6. Back." << endl;

		int number = AssertIsDigit("Enter action: ");

		switch (number)
		{
			case 1:
			{
                system("cls");
				int data = AssertIsDigit("Enter value: ");

				AddOptimized(treap->Root, data, rand() % treap->MaxPriority);
				PrintTreap(treap->Root, 0);
				break;
			}
			case 2:
			{
                system("cls");
				int data = AssertIsDigit("Enter value: ");
				AddNotOptimized(treap->Root, data, rand() % treap->MaxPriority);
				PrintTreap(treap->Root, 0);
				break;
			}
			case 3:
			{
                system("cls");
				int data = AssertIsDigit("Enter value: ");
				
				bool result = RemoveOptimized(treap->Root, data);
                if (result)
                {
                    cout << "Successfully deleted" << endl;
                }
                else
                {
                    cout << "Error deleting" << endl;
                }

				PrintTreap(treap->Root, 0);
				break;
			}
			case 4:
			{
                system("cls");
				int data = AssertIsDigit("Enter the value to delete: ");

				bool result = RemoveNotOptimized(treap->Root, data);
                if (result)
                {
                    cout << "Successfully deleted" << endl;
                }
                else
                {
                    cout << "Error deleting" << endl;
                }
			
				PrintTreap(treap->Root, 0);
				break;
			}
			case 5:
			{
                system("cls");
				int data = AssertIsDigit("Enter the desired value: ");
				
				bool result = FindElement(treap->Root, data);
                if (result)
                {
                    cout << "Element was found." << endl;
                }
                else
                {
                    cout << "Element wasn't found." << endl;
                }

				break;
			}
			case 6:
			{
                system("cls");
				DeleteTreap(treap->Root);
				delete treap;
				return;
			}
			default:
			{
                system("cls");
				cout << "Invalid action!" << endl;
				break;
			}
		}
	}
}