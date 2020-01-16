// Template.cpp :Esempio uso dei template, sommatoria degli elementi di un array
//

#include <iostream>
using namespace std;

template<class T>
T sumArray(T a[], int n)
{
    T tot = 0;
    for (int i = 0; i < n; i++)
        tot += a[i];
    return tot;
}


int main()
{
    int a[] = { 1,2,3,4,5,10 };
    float b[] = { 2.2, 3.3 };
    double c[] = { 2.333, 5.764 };
    cout <<"La somma dell'array d'interi e' "<<sumArray<int>(a, 6) << endl;
    cout << "La somma dell'array di float e' " << sumArray<float>(b, 2) << endl;
    cout << "La somma dell'array di double e' " << sumArray<double>(c, 2) << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
