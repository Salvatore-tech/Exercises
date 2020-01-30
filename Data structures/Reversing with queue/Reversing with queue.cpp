/* Reversing with queue.cpp :
Suppose you are given an array A, containing n numbers in order.
Reverse the order of the numbers in A using a single for-loop to insert each elements in a queue and another for-loop
that removes the elements from the queue and put them back in reverse order.
Can't use container from STL!
*/

#include <iostream>
using namespace std;

class Node
{
    int data;
    Node* next;
    friend class Queue;
};

/* Queue implementation based on linked list, i added a pointer to the tail to enqueue the elements without traversing
   the entire list.
   1) The constructor initializes both head and tail to nullptr
   2) When we insert an element for the 1st time we also allocate memory for the head-tail node
   N.B. the first element is at head->next->data!! */
class Queue 
{
    int capacity, i;
    Node* head;
    Node* tail;
public:
    Queue(int capacity) { i = 0; this->capacity = capacity; head = tail = nullptr;}
    void enqueue(int key);
    int dequeue();
    void visita() { cout << "\n"; for (Node* app = head->next; app != nullptr; app = app->next) cout << app->data << "\t"; }

};

void Queue::enqueue(int key)
{
    Node* nuovoNodo = new Node;
    nuovoNodo->data = key;
    nuovoNodo->next = nullptr;
    if (!tail)
        head = tail = new Node;
    tail->next = nuovoNodo;
    tail = nuovoNodo;
}

int Queue::dequeue()
{
    if (head)
    {
        int head_value = head->next->data;
        head = head->next;
        return head_value;
    }
    else
        cout << "Coda vuota!" << endl;
}


int main()
{
    int A[10];
    Queue q(10);

    for (int i = 0; i < 10; i++) // Filling the array with numbers between 0-9 and enqueue
    {
        A[i] = i;
        q.enqueue(A[i]);
    }

    cout << "--- Normal order ---" << endl;
    q.visita();

    cout << "\n--- Printing in reverse order ---" << endl;
    for (int i = 9; i >= 0; i--)
        A[i] = q.dequeue();

    // For each loop to print array elements
    for (const int& i : A)
        cout << i << "\t";





}

