#pragma once
template<class T>
struct Node
{
	T data;
	Node* leftChild;
	Node* rightChild;
	char colour;
	int count;
};

