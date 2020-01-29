/* Heap.cpp :
Heap data structure array based, because of it's array based the first element could not be 0!
Otherwise we can not compute the children of the root, so we have to create an array of one size greater and use the
index 1 as first element
*/

#include <iostream>
using namespace std;

void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


class MaxHeap
{
	int capacity, heapsize;
	int* root;
public:
	MaxHeap(int capacity) { this->capacity = capacity; heapsize = 1; root = new int[capacity]; }
	int parent(int i) { return (i-1) / 2; }
	int left(int i) { return 2 * i; }
	int right(int i) { return 2 * i + 1; }
	void insert(int data);
	void print();
	void heapify(int i);
	void buildHeap();
	int extractMax();
	void heapSort();
};



void MaxHeap::insert(int key) // Insert data until heapsize < capacity
{
	if (heapsize == capacity)
	{
		cout << "\nHeap overflow\n";
		return;
	}
    root[heapsize++] = key;

    /* Heapify // Uncomment this if you want to insert numbers and immediatly rearrange them in Heap
    while (i != 0 && root[parent(i)] < root[i])
    {
        Swap(&root[i], &root[parent(i)]);
        i = parent(i);
    }
	*/
}



void MaxHeap::print()
{
	cout << "\n";
	for (int i=1; i<heapsize; i++)
		cout << *(root+i) << "\t";
}

void MaxHeap::heapify(int i) // Restore heap property between the node at i position and its children
{
	int l = left(i);
	int r = right(i);
	int max;
	if (root[i]<root[l] && l <= heapsize)
		max = l;
	else
		max = i;
	if (root[max] < root[r] && r <= heapsize)
		max = r;
	if (max != i)
	{
		Swap(&root[i], &root[max]);
		heapify(max);
	}
}

void MaxHeap::buildHeap()
{
	for (int i = heapsize / 2; i > 0; i--)
		heapify(i);
}

int MaxHeap::extractMax()
{
	if (heapsize <= 1)
	{
		cout << "Heap empty!" << endl;
		return NULL;
	}
	int max = root[1];
	root[1] = root[--heapsize];
	heapify(1);
	return max;
}

void MaxHeap::heapSort()
{
	//buildHeap();
	//print();
	int len = heapsize;

	for (int i = len-1; i >= 1; i--)
	{
		Swap(&root[i], &root[1]);
		--len;
		heapify(1);
		cout << "\nHeap dopo il primo ciclo" << endl;
		print();
	}
}


int main()
{
	MaxHeap h(10);
	int max, elem;
	cout << "Inserisci 6 elementi" << endl;
	for (int i = 0; i < 6; i++)
	{
		cin >> elem;
		h.insert(elem);
	}

	h.heapSort();
	h.print();

	/*
	max=h.extractMax(); // Check if it is null
	if (max)
		cout << "\nIl massimo appena estratto dall'heap e' " << max << endl;
	h.print();
	*/

	//h.heapSort();

}
