// RB tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "rb_tree.h"

int main()
{
	Rb_tree R;
	R.insert(5);
	R.insert(3);
	R.insert(7);
	R.insert(12);
	R.inorder(R.getRoot());
}

