// Lettura per parole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>


using namespace std;
int main()
{
    string s;
    fstream miofile;
    miofile.open("prova.txt", ios::out|ios::in);
    if (!miofile)
        cout << "Errore apertura file!" << endl;
    while(miofile >> s)
     cout << s << "\t";
    return 0;
}

