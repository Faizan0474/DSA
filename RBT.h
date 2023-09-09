#pragma once
#include"Node.h"
#include"Tree.h"
#include<iostream>
#include<fstream>
using namespace std;

template<class T>
class RBT:public Tree<T>
{
private:
	void IN_orderTraversal(Node<T>* temp);
	void POST_orderTraversal(Node<T>* temp);
	void PRE_orderTraversal(Node<T>* temp);
	void POST_orderTraversal2(Node<T>* temp);
	void PRE_orderTraversal2(Node<T>* temp);
	void IN_orderTraversal2(Node<T>* temp);
public:
	void in_orderTraversal();
	void pre_orderTraversal();
	void post_orderTraversal();
	void post_orderTraversal2();
	void pre_orderTraversal2();
	void in_orderTraversal2();
	void insertfromfile();
	void insert(int);
	bool is_Empty();
	void wrapper();
	void check(Node<T>*);
	void right_right_rotate(Node<T>*, Node<T>*, Node<T>*, Node<T>*);
	void left_left_rotate(Node<T>*, Node<T>*, Node<T>*, Node<T>*);
	void print(Node<T>*);
	Node<T>* search(int);
	Node<T>* parent(Node<T>*);
	void del(int );
	bool case_with_zero_child(Node<T>*, Node<T>*);
	bool case_with_one_child(Node<T>*, Node<T>*);
	~RBT();
};
template<class T>
bool RBT<T>::case_with_one_child(Node<T>* temp, Node<T>* p)
{

	if (temp->leftChild == nullptr && temp->rightChild != nullptr && p->rightChild == temp)
	{
		temp->rightChild->colour = temp->colour;
		p->rightChild = temp->rightChild;
		delete temp;
		return true;
	}
	if (temp->leftChild == nullptr && temp->rightChild != nullptr && p->leftChild == temp)
	{
		temp->rightChild->colour = temp->colour;
		p->leftChild = temp->rightChild;
		delete temp;
		return true;
	}
	if (temp->leftChild != nullptr && temp->rightChild == nullptr && p->rightChild == temp)
	{
		temp->leftChild->colour = temp->colour;
		p->rightChild = temp->leftChild;
		delete temp;
		return true;
	}
	if (temp->leftChild != nullptr && temp->rightChild == nullptr && p->leftChild == temp)
	{
		temp->leftChild->colour = temp->colour;
		p->leftChild = temp->leftChild;
		delete temp;
		return true;
	}

}
template<class T>
bool RBT<T>::case_with_zero_child(Node<T>* temp, Node<T>* p)
{

	if (temp->rightChild == nullptr && temp->leftChild == nullptr && p->rightChild == temp)
	{
		delete temp;
		p->rightChild = nullptr;
		return true;

	}
	if (temp->rightChild == nullptr && temp->leftChild == nullptr && p->leftChild == temp)
	{
		delete temp;
		p->leftChild = nullptr;
		return true;
	}

	return false;

}
template<class T>
void RBT<T>:: del(int value)
{
	Node<T>* temp = search(value);

	Node<T>* p = parent(search(value));
	if (case_with_zero_child(temp, p) == true)
		return;
	else if (case_with_one_child(temp, p) == true)
		return;

	Node<T>* temp2 = temp;
	if (temp->leftChild != nullptr && temp->rightChild != nullptr)
	{
		temp2 = temp2->leftChild;
		while (temp2->rightChild != nullptr)
		{
			temp2 = temp2->rightChild;

		}
		temp->data = temp2->data;


		if (case_with_zero_child(temp2, p) == true)
			return;
		else if (case_with_one_child(temp2, p) == true)
			return;
	}

}
template<class T>
Node<T>* RBT<T>::parent(Node<T>* child)
{
	if (child == nullptr)
		return nullptr;

	Node<T>* temp = Tree<T>::root;
	if (temp->data == child->data)
		return nullptr;
	while (1)
	{
		if (temp->rightChild != nullptr) {
			if (temp->rightChild->data == child->data)
			{
				return temp;
			}
		}
		if (temp->leftChild != nullptr) {
			if (temp->leftChild->data == child->data && temp->leftChild != nullptr)
			{
				return temp;
			}
		}
		if (temp->data > child->data)
		{
			temp = temp->leftChild;
		}
		else
			temp = temp->rightChild;

	}


}
template<class T>
Node<T>* RBT<T>:: search(int value)
{
	Node<T>* temp = Tree<T>::root;

	if (temp->data == value)
	{
		//cout << "VALUE FOUND\n";
		return temp;
	}
	while (1) {
		if (value > temp->data)
		{
			temp = temp->rightChild;
			if (temp == nullptr)
			{
				//cout << "NOT FOUND\n";
				return nullptr;

			}
			if (temp->data == value)
			{
				//cout << "VALUE FOUND\n";
				return temp;
			}
		}
		if (value < temp->data)
		{
			temp = temp->leftChild;
			if (temp == nullptr)
			{
				//cout << "NOT FOUND\n";
				return nullptr;

			}
			if (temp->data == value)
			{
				//cout << "VALUE FOUND\n";
				return temp;
			}

		}


	}
}
template<class T>
void RBT<T>:: print(Node<T>* n)
{

	if (n != nullptr)
	{
		
		print(n->leftChild);
		cout << n->data << "  " << n->colour << endl;
		print(n->rightChild);
	}

}

template<class T>
void RBT<T>:: insert(int value)
{

	Node<T>* n;
	n = new Node<T>;
	n->data = value;
	n->leftChild = nullptr;
	n->rightChild = nullptr;
	n->colour = 'r';
	//Node<T>* temp = Tree<T>::root;

	//if (temp->data == value)
	//{
	//	//cout << "VALUE FOUND\n";
	//	n->count++;
	//}
	//while (true)
	//{
	//	if (value > temp->data)
	//	{
	//		temp = temp->rightChild;
	//		if (temp == nullptr)
	//		{
	//			//cout << "NOT FOUND\n";
	//			break;

	//		}
	//		if (temp->data == value)
	//		{
	//			//cout << "VALUE FOUND\n";
	//			n->count++;
	//			break;
	//		}
	//	}
	//	if (value < temp->data)
	//	{
	//		temp = temp->leftChild;
	//		if (temp == nullptr)
	//		{
	//			//cout << "NOT FOUND\n";
	//			break;

	//		}
	//		if (temp->data == value)
	//		{
	//			//cout << "VALUE FOUND\n";
	//			n->count++;
	//			break;
	//		}

	//	}
	//}

	if (Tree<T>::root == nullptr)
	{
		Tree<T>::root = n;
		Tree<T>::root->colour = 'b';
		return;
	}
	else
	{
		Node<T>* temp = Tree<T>::root;
		do {

			if (temp->data >=value)
			{
				if (temp->leftChild == nullptr)
				{
					temp->leftChild = n;
					if (parent(n) != nullptr && parent(n)->colour == 'r') {
						check(n);
					}
					return;
				}
				else
					temp = temp->leftChild;

			}
			if (temp->data < value)
			{
				if (temp->rightChild == nullptr)
				{
					temp->rightChild = n;
					if (parent(n) != nullptr && parent(n)->colour == 'r') {
						check(n);
					}

					return;
				}
				else
					temp = temp->rightChild;

			}

		} while (1);

	}

}
template<class T>
void RBT<T>:: wrapper()
{
	print(Tree<T>::root);

}
template<class T>
void RBT<T>::check(Node<T>* n)
{
	Node<T>* p;
	Node<T>* gp;
	Node<T>* ggp;
	bool right_re_color;
	bool left_re_color;
	bool left_right;
	bool right_rotation;
	bool left_rotation;
	do
	{
		p = parent(n);
		gp = parent(p);
		ggp = parent(gp);


		right_re_color = false;
		left_re_color = false;
		right_rotation = false;
		left_right = false;
		//recolor
		if (p->colour == 'r' && n->colour == 'r' && p->rightChild != nullptr && p->rightChild->data == n->data)
		{
			if (gp->leftChild != nullptr)
			{
				if (gp->leftChild->colour == 'r')
				{
					gp->colour = 'r';
					gp->leftChild->colour = 'b';
					p->colour = 'b';

					right_re_color = true;


					if (Tree<T>::root->colour == 'r')
						Tree<T>::root->colour = 'b';


				}
			}




			if (right_re_color == false)
			{
				if (gp != nullptr && gp->rightChild->data == p->data)
				{

					right_right_rotate(n, p, gp, ggp);
					right_rotation = true;
				}


			}


		}

		if (right_re_color == false && right_rotation == false)
		{
			if (p->colour == 'r' && n->colour == 'r' && p->leftChild != nullptr && p->leftChild->data == n->data)
			{
				if (gp->leftChild != nullptr)
				{
					if (gp->rightChild != nullptr && gp->rightChild->colour == 'r')
					{
						gp->colour = 'r';
						gp->rightChild->colour = 'b';
						p->colour = 'b';

						left_re_color = true;


						if (Tree<T>::root->colour == 'r')
							Tree<T>::root->colour = 'b';


					}
				}
				if (left_re_color == false)
				{
					if (gp != nullptr && gp->leftChild->data == p->data)
					{

						left_left_rotate(n, p, gp, ggp);
						left_rotation = true;
					}


				}

			}



		}




		n = parent(n);

	} while (n != Tree<T>::root);


}
template<class T>
void RBT<T>::right_right_rotate(Node<T>* n, Node<T>* p, Node<T>* gp, Node<T>* ggp)
{
	if (gp->leftChild == nullptr || gp->leftChild->colour == 'b') {
		if (gp->rightChild->rightChild != nullptr)
		{
			if (gp->rightChild->rightChild->data == n->data)
			{
				gp->rightChild = p->leftChild;
				p->leftChild = gp;
				p->colour = 'b';
				gp->colour = 'r';
				if (gp == Tree<T>::root)
					Tree<T>::root = p;

				if (ggp != nullptr && ggp->rightChild != nullptr) {
					{
						if (ggp->rightChild = gp)
							ggp->rightChild = p;
						return;
					}
				}
				if (ggp != nullptr && ggp->leftChild != nullptr) {
					{
						if (ggp->leftChild = gp)
							ggp->leftChild = p;
						return;
					}
				}

			}
		}
	}


}
template<class T>
void RBT<T>::left_left_rotate(Node<T>* n, Node<T>* p, Node<T>* gp, Node<T>* ggp)
{
	if (gp->rightChild == nullptr || gp->rightChild->colour == 'b') {
		if (gp->leftChild->leftChild != nullptr)
		{
			if (gp->leftChild->leftChild->data == n->data)
			{
				gp->leftChild = p->rightChild;
				p->rightChild = gp;
				p->colour = 'b';
				gp->colour = 'r';
				if (gp == Tree<T>::root)
					Tree<T>::root = p;
				if (ggp != nullptr && ggp->leftChild != nullptr) {
					{
						if (ggp->leftChild = gp)
							ggp->leftChild = p;
						return;
					}
				}
				if (ggp != nullptr && ggp->rightChild != nullptr) {
					{
						if (ggp->rightChild = gp)
							ggp->rightChild = p;
						return;
					}
				}

			}
		}
	}


}
template<class T>
void RBT<T>::in_orderTraversal()
{
	if (is_Empty())
	{
		cout << "Empty Tree\n";
	}
	else
		IN_orderTraversal(Tree<T>::root);

}
template<class T>
void RBT<T>::IN_orderTraversal(Node<T>* temp)
{
	if (temp != nullptr)
	{
		IN_orderTraversal(temp->leftChild);
		cout << temp->data << " " << temp->colour << endl;
		IN_orderTraversal(temp->rightChild);
	}

}
template<class T>
void RBT<T>::post_orderTraversal()
{
	POST_orderTraversal(Tree<T>::root);
}
template<class T>
void RBT<T>::POST_orderTraversal(Node<T>* temp)
{
	if (temp != nullptr)
	{
		POST_orderTraversal(temp->leftChild);
		POST_orderTraversal(temp->rightChild);
		cout << temp->data << endl;
	}
}
template<class T>
void RBT<T>::pre_orderTraversal()
{
	PRE_orderTraversal(Tree<T>::root);
}
template<class T>
void RBT<T>::PRE_orderTraversal(Node<T>* temp)
{
	if (temp != nullptr)
	{
		cout << temp->data << endl;
		cout << temp->colour << endl;
		PRE_orderTraversal(temp->leftChild);
		PRE_orderTraversal(temp->rightChild);
	}
}
template<class T>
void RBT<T>::post_orderTraversal2()
{
	POST_orderTraversal2(Tree<T>::root);
}
template<class T>
void RBT<T>::POST_orderTraversal2(Node<T>* temp)
{
	POST_orderTraversal2(temp->rightChild);
	POST_orderTraversal2(temp->leftChild);
	cout << temp->data << endl;
	cout << temp->colour << endl;
}
template<class T>

void RBT<T>::pre_orderTraversal2()//nrl
{
	PRE_orderTraversal2(Tree<T>::root);
}
template<class T>
void RBT<T>::PRE_orderTraversal2(Node<T>* temp)
{
	cout << temp->data << endl;
	cout << temp->colour << endl;
	PRE_orderTraversal2(temp->rightChild);
	PRE_orderTraversal2(temp->leftChild);

}
template<class T>

void RBT<T>::in_orderTraversal2()//rnl
{
	IN_orderTraversal2(Tree<T>::root);
}
template<class T>
void RBT<T>::IN_orderTraversal2(Node<T>* temp)
{
	IN_orderTraversal2(temp->rightChild);
	cout << temp->data << endl;
	cout << temp->colour << endl;
	IN_orderTraversal2(temp->leftChild);
}
template<class T>
void RBT<T>::insertfromfile()
{
	ifstream fin;
	fin.open("input.txt");
	if (!fin.is_open())
	{
		cout << "File not open" << endl;
	}
	else
	{
		T x = 0;
		while (!fin.eof())
		{
			fin >> x;
			insert(x);

		}

	}


}
template<class T>
bool RBT<T>::is_Empty()
{
	if (Tree<T>::root != nullptr)
	{
		return false;
	}
	else
		return true;

}
template<class T>
RBT<T>::~RBT()
{
	delete Tree<T>::root;
	Tree<T>::root = nullptr;
}
