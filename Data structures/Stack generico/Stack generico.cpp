/*Stack generico.cpp : This file contains the 'main' function. Program execution begins and ends there.
Implementazione di uno stack generico attraverso l'utilizzo dei template
Overload del costruttore, il "secondo costruttore" consente di allocare memoria per una dimensione passata in input,
evitando in tal modo inutili riallocazioni e spostamenti di blocchi di memoria quando dobbiamo inserire molti dati.
La gestione dello stack avviene attraverso un array, un intero che rappresenta la dimensione e un indice
che memorizza l'ultimo elemento inserito.
Le operazioni di push e pop avvengono sempre in testa 
*/

#include <iostream>
using namespace std;

template<typename T>
class Stack
{
	T* vett;
	int dim, top;
public:
	Stack() { vett = nullptr; dim = 0; top = -1; };
	Stack(int dim) { vett = new int[dim]; this->dim = dim; top = -1; };
	void push(T elem);
	bool pop();
	void visit();
};

template<typename T>void Stack<T>::push(T elem)
{
	if (top == dim - 1)
	{
		T* app = new T[dim + 10];
		for (int i = 0; i < dim; i++)
			*(app + i) = *(vett + i);
		dim += 10;
		delete []vett;
		vett = app;
	}
	vett[top++] = elem;
}

template<typename T>bool Stack<T>::pop()
{
	if (top > 0) {
		vett[top--];
		return true;
	}
	return false;
}



template<typename T>void Stack<T>::visit()
{
	cout << "--- First ---" << endl;
	for (int i = 0; i < dim; i++)
	{
		if (i == top)  cout << "H\t";
		cout << "Valore: " << *(vett + i) << endl;
	}
	cout << "--- Last ---" << endl;

}


int main()
{
	Stack<int> s(20);
	for (int i=0; i<5; i++)
		s.push(i);
	s.visit();
	s.pop();
	s.visit();
}

