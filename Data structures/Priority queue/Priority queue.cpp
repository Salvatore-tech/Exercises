// Priority queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std; 

void scambia(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


class MaxPriorityQueue
{
    int key;
    int heapsize, capacity;
    int* p;
public:
    MaxPriorityQueue(int capacity) { p = new int[capacity]; heapsize = 1; this->capacity = capacity; }
    void insert(int key);
    int parent(int i) { return i / 2; }
    int extractMax();
    void increasePriority(int i, int key);
    void stampa() { for (int i = 1; i < heapsize; i++) cout << *(p + i) << "\t"; }
};

void MaxPriorityQueue::insert(int key)
{
    p[heapsize] = INT_MIN;
    increasePriority(heapsize, key);
    ++heapsize;
}


void MaxPriorityQueue::increasePriority(int i, int key)
{
    if (key < p[i])
    {
        cout << "La nuova chiave è minore di quella presente" << endl;
        return;
    }
    p[i] = key;
    while (p[parent(i)] < p[i] && i>1)
    {
        scambia(&p[i], &p[parent(i)]);
        i = parent(i);
    }
}


int main()
{
    MaxPriorityQueue q(10);
    q.insert(5);
    q.insert(9);
    q.insert(1);
    q.insert(10);
    q.stampa();

    cout << "\nIncreasing priority element 1" << endl;
    q.increasePriority(1, 99);
    q.stampa();
}

