/* Red-black tree.cpp : This file contains the 'main' function. Program execution begins and ends there.


N.B. utilizza il costruttore della classe Node per inizializzare i membri del nuovo nodo invece che farlo nel
	metodo RBtree::insert!
*/

#include "RB_tree.h";






void RBtree::inorder(Node* p)
{
	if (p!=nullptr)
	{
		inorder(p->leftChild);
		cout <<"\nChiave: "<<p->chiave << "\tColore: "<<p->colore<<endl;
		inorder(p->rightChild);
	}
}

Node* RBtree::inserter(int key)
{
	Node* nuovoNodo = new Node(key);
	nuovoNodo->leftChild = nuovoNodo->rightChild = nuovoNodo->parent = nullptr;
	Node* x = root;
	Node* y = nullptr;
	while (x != nullptr)
	{
		y = x;
		if (key < x->chiave)
			x = x->leftChild;
		else
			x = x->rightChild;
	}
	nuovoNodo->parent = y;
	if (y == nullptr)
		root = nuovoNodo;
	else if (nuovoNodo->chiave < nuovoNodo->parent->chiave)
		nuovoNodo->parent->leftChild = nuovoNodo;
	else
		nuovoNodo->parent->rightChild = nuovoNodo;
	return nuovoNodo;
}

void RBtree::insert(int key)
{
	//Node* v = new Node(key);
	Node* v = inserter(key);
	if (v==root)
		setBlack(&v);
	else
	{
		setRed(&v);
		remedyDoubleRed(&v);
	}
}

Node* RBtree::sibling(const Node* v)
{
	if (v == v->parent->leftChild)
		return v->parent->rightChild;
	else
		return v->parent->leftChild;
}

void RBtree::remedyDoubleRed(Node** v)
{
	Node* p = (*v)->parent;
	if (p == root || isBlack(p))
		return;

	if (isRed(sibling(*v)))
	{
		setBlack(v);
		Node* app = sibling(*v);
		setBlack(&app);
		Node* u = (*v)->parent;
		if (u == root) return;
		setRed(&u);
		remedyDoubleRed(&u);
	}
}


int main()
{
	RBtree rb;
	rb.insert(5);
	rb.insert(7);
	rb.insert(3);
	rb.insert(12);

	rb.inorder(rb.getRoot());

}

