/* Polimorfismo.cpp : This file contains the 'main' function. Program execution begins and ends there.
Esempio utile per capire il funzionamento del polimorfismo, viene creata una classe astratta Abitazione e 2 classi derivate.
Il metodo print() della superclasse è dichiarato virtual e ridefinito da entrambe le sottoclassi.
Nel main viene creato un array di puntatori ad oggetti, dove i primi 5 sono oggetti Abitazione e i rimanenti sono oggetti di tipo Villa
Da notare la creazione dell'array di puntatori che inizialmente e' di tipo Abitazione e solo successivamente in fase di compilazione 
i relativi elementi vengono istanziati nei 2 cicli for.
N.B. Il polimorfismo garantisce, in sostanza, la possibilità di creare un oggetto di classe derivata anche tramite un riferimento 
(o puntatore) ad oggetto di classe base.
*/

#include <iostream>
using namespace std;

//Abitazione e' una classe generica astratta, pertanto non posso istanziare oggetti di tipo abitazione, e' utile solo come superclasse
class Abitazione { 
public:
    virtual void print() { cout << "Questa e' un abitazione generica!" << endl; } //Metodo oggetto di late binding
};

class Appartamento :public Abitazione {
public:
    void print() { cout << "Questa e' un appartamento!" << endl; } //Override del metodo virtual
};

class Villa :public Abitazione {
public:
    void print() { cout << "Questa e' una villa!" << endl; } // Override del metodo virtual
};

int main()
{
    Abitazione* app[10];
    for (int i = 0; i < 5; i++)
        app[i] =  new Appartamento();
    for (int i = 5; i < 10; i++)
        app[i] = new Villa();

    for (int i = 0; i < 10; i++)
        app[i]->print();    
}
