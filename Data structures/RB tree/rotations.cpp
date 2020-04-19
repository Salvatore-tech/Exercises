#include "rb_tree.h"

void Rb_tree::rotateLeft(Node** v)
{
	Node* right = (*v)->rightChild;
	(*v)->rightChild = right->leftChild; // Sostituisce p con p->left
	if ((*v)->rightChild)
		(*v)->rightChild->parent = *v; // Imposta il nuovo padre del sottoalbero 
	right->parent = (*v)->parent;

	if (!(*v)->parent)
		root = right;
	else if ((*v) == (*v)->parent->leftChild)
		(*v)->parent->leftChild = right;
	else
		(*v)->parent->rightChild = right;
	right->leftChild = *v;
	(*v)->parent = right;
}





void Rb_tree::rotateRight(Node** v)
{
	Node* left = (*v)->leftChild;
	(*v)->leftChild = left->rightChild;
	if ((*v)->leftChild)
		(*v)->leftChild->parent = *v;
	left->parent = (*v)->parent;
	if (!(*v)->parent)
		root = left;
	else if ((*v) == (*v)->parent->leftChild)
		(*v)->parent->leftChild = left;
	else
		(*v)->parent->rightChild = left;
	left->rightChild = *v;
	(*v)->parent = left;
}