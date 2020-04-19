#pragma once
#include <stdlib.h>
#include <stdio.h>
using namespace std;
void* operator new(size_t size);
void operator delete(void* p);
