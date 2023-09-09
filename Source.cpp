#include "RBT.h"
void Menu()
{
	cout << "\t\t\n\t\t\t\t\t\tMenu\n\n\t\t\t\t   Select your Choice(1 to 13)\n\n";
	cout << "\t\t\4 1)Insert values\t\t\4 2)Serach values from RBT Tree\n\n";
	cout << "\t\t\4 3)Pre_Order traversal\t\t\4 4)In_Order traversal\n\n";
	cout << "\t\t\4 5)Post_Order traversal\t\4 6)Pre_Order traversal 2\n\n";
	cout << "\t\t\4 7)In_Order traversal 2\t\4 8)post_Order traversal 2\n\n";
	cout << "\t\t\4 9)Displaying parent of a node present in Tree\t\n\n";
	cout << "\t\t\4 10)Read integer values from the file input.txt to create a red - black tree\n\n";
	cout << "\t\t\4 11)Delete all duplicate values from the tree\t\4 12)Destroy the complete tree\n\n";
	cout << "\t\t\t\t\t\4 13)Exit\n\n";
	
}

int main()
{

	RBT<int> myRBT;
	int Choice = 0;
	int user_val = 0;
	do
	{
		Menu();
		cin >> Choice;
		system("cls");
		if (Choice == 1)
		{
			cout << "How many Values you want to Enter: ";
			cin >> user_val;
			int x = 0;
			for (int i = 0; i < user_val; i++)
			{
				cin >> x;
				myRBT.insert(x);
			}

		}

		if (Choice == 2)
		{
			cout << "Enter the value for serach : ";
			cin >> user_val;
			bool r = myRBT.search(user_val);
			if (r == 1)
			{
				cout << "\nFound\n";
			}
			else
				cout << "Sorry Not Found!!\n";

		}

		if (Choice == 3)
		{
			cout << "Pre_Order Traversal (NLR)\n";
			myRBT.pre_orderTraversal();
		}

		if (Choice == 4)
		{
			cout << "In_Order Traversal (LNR)\n";
			myRBT.in_orderTraversal();
		}

		if (Choice == 5)
		{
			cout << "In_Order Traversal (LRN)\n";
			myRBT.post_orderTraversal();
		}

		if (Choice == 6)
		{
			cout << "Pre_Order Traversal (NRL)\n";
			myRBT.pre_orderTraversal2();
		}

		if (Choice == 7)
		{
			cout << "Pre_Order Traversal (RNL)\n";
			myRBT.in_orderTraversal2();
		}

		if (Choice == 8)
		{
			cout << "Pre_Order Traversal (RLN)\n";
			myRBT.post_orderTraversal2();
		}

		if (Choice == 9)
		{
			cout << "Parent's Node in tree is\n";
			//myRBT.FindParent();
		}

		if (Choice == 10)
		{
			myRBT.insertfromfile();
		}

		if (Choice == 11)
		{
			cout << "\nDelete all Duplicates values in the Tree\n";
		}
		if (Choice == 12)
		{
			cout << "Tree Destroyed \n";
			myRBT.~RBT();
		}

		if (Choice == 13)
		{
			cout << "End";
		}
	} while (Choice != 13);

	return 0;
}