#pragma once
#include <iostream>
using namespace std;
typedef enum { RED, BLACK } color;

class Node
{
	Node* parent, * leftChild, * rightChild;
	int key;
	bool colore;
	Node(int key) { this->key = key; this->colore = RED; parent = leftChild = rightChild = nullptr; }
	friend class Rb_tree;
};

class Rb_tree
{
	Node* root;
protected:
	void rotateLeft(Node** v);
	void rotateRight(Node** v);
	void fixViolation(Node** v);

public:
	Rb_tree() { root = nullptr; }
	bool isBlack(const Node* v) const { return v->colore == BLACK; }
	bool isRed(const Node* v) const { return v->colore == RED; }
	void changeColor(Node** v);
	void inorder(const Node* v) const;
	Node* getRoot() const { return root; }
	Node** sibling(const Node* v);
	Node* grandParent(const Node* v) const { return v->parent->parent; }
	void setBlack(Node** v) { (*v)->colore = BLACK; }
	void setRed(Node** v) { (*v)->colore = RED; }
	void insert(int key);

};

