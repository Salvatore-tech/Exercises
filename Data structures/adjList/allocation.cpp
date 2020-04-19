#include "allocation.h"
void* operator new(size_t size)
{
	cout << "\nAllocating %d bytes"<< size << endl;
	void *p= malloc(size);
	return p;
}

void operator delete(void* p)
{
	cout << "\nFreeing %d bytes" << sizeof(p) << endl;
	free(p);
}