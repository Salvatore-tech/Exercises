#include <iostream>
#include "RB_tree.h"
void RBtree::rotateLeft(Node** x)
{
	Node* y = (*x)->rightChild;
	(*x)->rightChild = y->leftChild;
	if (y->leftChild)
		y->leftChild->parent = (*x);
	y->parent = (*x)->parent;
	if (!(*x)->parent)
		root = y;
	else if (*x == (*x)->parent->leftChild)
		(*x)->parent->leftChild = y;
	else
		(*x)->parent->rightChild = y;
	y->leftChild = *x;
	(*x)->parent = y;
}




