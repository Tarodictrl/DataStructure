#include "Model/BinaryTree/BinaryTree.h"
#include "Model/Treap/Treap.h"
#include "Services/Validator.h"
#include "iostream"
#include "Menu/MenuBinaryTree.h"
#include "Menu/MenuTreap.h"

using namespace std;

int main()
{
	while (true)
	{
		system("cls");
		cout << "Select:" << endl;
		cout << "1. Binary Tree." << endl;
		cout << "2. Treap." << endl;
		cout << endl;

		int key = AssertIsDigit("Select action: ");

		switch (key)
		{
			case 1:
				system("cls");
				MenuBinaryTree();
				break;
			case 2:
				system("cls");
				MenuTreap();
				break;
			default:
				cout << "Invalid action!" << endl;
				break;
			}
	}
	
}