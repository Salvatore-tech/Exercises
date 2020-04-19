#pragma once
#include <iostream>

using namespace std;

typedef enum { RED, BLACK } Color;

class Node
{

	Node* parent;
	Node* leftChild;
	Node* rightChild;
	int chiave;
	bool colore;
	friend class RBtree;
	Node(int chiave) { this->chiave = chiave; this->colore = RED; parent = leftChild = rightChild = nullptr; }
};

class RBtree
{
public:
	RBtree() { root = nullptr; }
	void inorder(Node* r);
	Node* getRoot() { return root; }
	bool isBlack(const Node* v) { return v->colore == BLACK; }
	bool isRed(const Node* v) { return v->colore == RED; }
	Node* sibling(const Node* v);

	void setBlack(Node** v) { (*v)->colore = BLACK; }
	void setRed(Node** v) { (*v)->colore = RED; }
	void insert(int key);
	Node* inserter(int key);
	void remedyDoubleRed(Node** v);
protected:
	void rotateLeft(Node**);
	void rotateRight(Node**);
	void fixViolation(Node**);

private:
	Node* root;
};