#include "rb_tree.h"

Node** Rb_tree::sibling(const Node* v)
{
	if (v == v->parent->leftChild)
		return &v->parent->rightChild;
	else if (v == v->parent->rightChild)
		return &v->parent->leftChild;
	else
		return nullptr;
}

void Rb_tree::inorder(const Node* v)const
{
	if (v)
	{
		inorder(v->leftChild);
		cout << "\nKey: " << v->key << "\tColore: " << v->colore << endl;
		inorder(v->rightChild);
	}
}

void Rb_tree::changeColor(Node** v)
{
	if (isRed(*v))
		setBlack(v);
	else
		setRed(v);
}

void Rb_tree::insert(int key)
{
	Node* nuovoNodo = new Node(key);
	Node* x = root;
	Node* y = nullptr;
	while (x) // Standard BST insert of a new node
	{
		y = x;
		if (key < x->key)
			x = x->leftChild;
		else
			x = x->rightChild;
	}
	nuovoNodo->parent = y;
	if (!y)
	{
		root = nuovoNodo;
		return;
	}
	else if (key < y->key)
		y->leftChild = nuovoNodo;
	else
		y->rightChild = nuovoNodo;

	// Check for violation
	Node* uncle = *sibling(nuovoNodo->parent);
	if (uncle!=nullptr)
	{

	if (isRed(uncle))
	{
		Node* x = nuovoNodo;
		Node* p = nuovoNodo->parent;
		while (x->colore == x->parent->colore == RED)
		{
			changeColor(&nuovoNodo->parent);
			changeColor(sibling(nuovoNodo->parent));
			changeColor(&nuovoNodo->parent->parent);
			x = x->parent;
		}

	}
	else if (isBlack(uncle))
	{
		if (grandParent(nuovoNodo)->leftChild == nuovoNodo->parent)
		{
			if (nuovoNodo == nuovoNodo->parent->leftChild) // Left left case
			{
				rotateRight(&nuovoNodo->parent->parent);
				changeColor(&nuovoNodo->parent->parent);
				changeColor(&nuovoNodo->parent);
			}
			else // Left right case
			{
				rotateLeft(&nuovoNodo->parent);
				rotateRight(&nuovoNodo->parent->parent);
				changeColor(&nuovoNodo->parent->parent);
				changeColor(&nuovoNodo->parent);
			}
		}
		else if (grandParent(nuovoNodo)->rightChild == nuovoNodo->parent)
		{
			if (nuovoNodo == nuovoNodo->parent->rightChild) // Right right case 
			{
				rotateLeft(&nuovoNodo->parent->parent);
				changeColor(&nuovoNodo->parent->parent);
				changeColor(&nuovoNodo->parent);
			}
			else // Right left case 
			{
				rotateRight(&nuovoNodo->parent);
				rotateLeft(&nuovoNodo->parent->parent);
				changeColor(&nuovoNodo->parent->parent);
				changeColor(&nuovoNodo->parent);
			}
		}
	}
	root->colore = BLACK;
	}
}