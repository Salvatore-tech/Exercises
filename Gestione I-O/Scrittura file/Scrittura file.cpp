// Operazioni base per lettura/scrittura su file 
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{   
    char ch;
    ofstream filewrite("file.txt");
    ifstream fileread("file.txt");
    filewrite << "Hello world!" << endl;
    while (fileread.get(ch))
        cout << ch;
    filewrite.close();
    fileread.close();
}

