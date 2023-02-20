#include "../Model/BinaryTree/BinaryTree.h"
#include "../Services/Validator.h"
#include <iostream>

using namespace std;

void PrintTree(BinaryTreeNode* currentNode, int level)
{
	if (currentNode)
	{
		PrintTree(currentNode->Right, level + 1);

		for (int i = 0; i < level; i++)
		{
			cout << "   ";
		}
		cout << currentNode->Data << endl;
		PrintTree(currentNode->Left, level + 1);
	}
}

void MenuBinaryTree()
{
	cout << "Binary Tree" << endl;

	BinaryTree* tree = new BinaryTree();

	while (true)
	{
		cout << "1. Add." << endl;
		cout << "2. Delete." << endl;
		cout << "3. Find." << endl;
		cout << "4. Find min." << endl;
		cout << "5. Find max." << endl;
		cout << "6. Back." << endl;

		int number = AssertIsDigit("Select action: ");

		switch (number)
		{
			case 1:
			{
                system("cls");
				int data = AssertIsDigit("Enter value: ");

				AddElement(tree, data);
				PrintTree(tree->Root, 0);
				break;
			}
			case 2:
			{
                system("cls");
				if (!tree->Root)
				{
                    cout << "Tree is empty!" << endl;
					break;
				}

				int data = AssertIsDigit("Enter value: ");
				
				if (RemoveElement(tree->Root, data))
				{
					cout << "Element was deleted." << endl;
				}
				else
				{
					cout << "Error!" << endl;
				}

				PrintTree(tree->Root, 0);


				break;
			}
			case 3:
			{
                system("cls");
				if (!tree->Root)
				{
                    cout << "Tree is empty!" << endl;
					break;
				}

				int data = AssertIsDigit("Enter value: ");
				BinaryTreeNode* parent = nullptr;

				if (FindElement(tree->Root, data, parent))
				{
					cout << "Element was found." << endl;
				}
				else
				{
					cout << "Element wasn't found." << endl;
				}

				break;
			}
			case 4:
			{
                system("cls");
				if (!tree->Root)
				{
                    cout << "Tree is empty!" << endl;
					break;
				}
				BinaryTreeNode* parentMinNode = nullptr;
				cout << "Min value: " << FindMin(tree->Root, parentMinNode)->Data << endl;
				break;
			}
			case 5:
			{
                system("cls");
				if (!tree->Root)
				{
					cout << "Tree is empty!" << endl;
					break;
				}

				BinaryTreeNode* parentMaxNode = nullptr;
				cout << "Max value: " << FindMax(tree->Root, parentMaxNode)->Data << endl;
				break;
			}
			case 6:
			{
                system("cls");
				if (tree != nullptr)
				{
					DeleteBinaryTree(tree->Root);
					delete tree;			
				}
				return;
			}
			default:
			{
                system("cls");
				cout << "Incorrect action!" << endl;
				break;
			}
		}
	}
}