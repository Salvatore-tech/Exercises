/* Anfore.cpp : Indovinello delle 2 anfore:
Si hanno a disposizione 2 anfore, una può contenere al massimo 5 litri e l'altra 3 litri.
Si vuole misurare con l'ausilio delle 2 anfore, la quantità di 4 litri. 
Passi necessari per la risoluzione dell'indovinello (2 modi possibili):
1) Riempi l'anfora grande
2) Sposta il contenuto nell'anfora piccola (verrranno spostati 3 litri)
3) Svuota l'anfora piccola
4) Sposta il contenuto rimanente dall'anfora grande a quella piccola (2 litri)
5) Riempi l'anfora grande 
6) Sposta il contenuto dall'anfora grande a quella piccola (1 litro)
*/

#include <iostream>
using namespace std;

class Contenitore {
    int qt;
protected:
    void setQt(int qt) { this->qt = qt; }
public:
    Contenitore() { qt = 0; }
    void versa(int lt) { qt += lt; }
    void togli(int lt) { qt-=lt;}
    int getQt() { return qt; };
};

class Anfora :public Contenitore {
    int capacita;
public:
    Anfora(){}
    Anfora(int capacita) { this->capacita = capacita; }
    void riempi() { versa(capacita); }
    void svuota() { setQt(0); }
    int getCapacita() { return capacita; }
    bool isEmpty() { if (getQt() == 0) return true;}
    bool isFull() { if (getQt() == capacita) return true; }
    void travasa(Anfora& A_small); 
};

void Anfora::travasa(Anfora& A_small) //Function che sposta la quantita contenuta nell'anfora passata come parametro
{
    int app = A_small.getCapacita() - A_small.getQt();
    if (app < getQt()) //1) caso: l'anfora big ha più acqua di quanto ne possa contenere l'anfora small
    {
        A_small.versa(app);
        togli(app);
    }
    else //2) caso: l'anfora ha meno acqua di quanto ne possa contenere l'anfora small e verrà spostato il suo contenuto interamente
    {
        A_small.versa(getQt());
        togli(getQt());
    }
}

class Indovinello {
    Anfora A_big; //Attributi di tipo Anfora
    Anfora A_small;
public:
    Indovinello() :A_big(5), A_small(3) {}; //Nel costruttore relativo ad un oggetto composto devi richiamare i costruttori degli oggetti-attributi
    void risolvi();
    void print();
};

void Indovinello::print()
{
    cout << "A.grande\t A.piccola" << endl;
    cout << "Capacita' " << A_big.getCapacita() << "\tCapacita': " << A_small.getCapacita() << endl;
    cout << "Contenuto' " << A_big.getQt() << "\tContenuto: " << A_small.getQt() << endl;
}


void Indovinello::risolvi() //Azioni necessarie per risolvere l'indovinello
{
    A_big.riempi();
    cout << "1) Riempi anfora grande" << endl;
    print();
    A_big.travasa(A_small);
    cout << "\n2) Travasa anfora grande->anfora piccola" << endl;
    print();
    A_small.svuota();
    cout << "\n3) Svuota anfora piccola" << endl;
    print();
    A_big.travasa(A_small);
    cout << "\n4) Travasa anfora grande->anfora piccola" << endl;
    print();
    A_big.riempi();
    cout << "\n5) Riempi anfora grande" << endl;
    print();
    A_big.travasa(A_small);
    cout << "\n6) Travasa anfora grande->anfora piccola" << endl;
    print();
}

int main()
{
    Indovinello I;
    I.risolvi();
}

