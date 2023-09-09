#pragma once
#include"Node.h"
template<class T>
class Tree
{
public:
	Tree()
	{
		root = nullptr;
	}
	virtual void insert(int)=0;
protected:
	Node<T>* root;

};