/* Overload operatori.cpp : Questo esempio mostra com'è possibile effettuare l'overload degli operatori (non tutti consentono l'overload)
L'overload è possibile effettuarlo in 2 modi:
1)Dichiarando la funzione all'interno della classe (esempio "operator -")
2)Effettuando l'overload all'esterno della classe della funzione in questione (esempio "operator +")
Nel primo caso il primo operando è un oggetto della stessa classe, pertanto il metodo avrà un argomento in meno rispetto al numero degli operandi
(se l'operatore è unario, la funzione non avrà argomenti).
*/

#include <iostream>
using namespace std;

class Punto {
    float x, y;
public:
    Punto() { x = y = 0.0; }
    Punto(float x, float y) { this->x = x; this->y = y; }
    float getX() { return x; }
    float getY() { return y; }
    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }
    void operator- (Punto p2) { x -= p2.getX(); y -= p2.getY(); }
};

Punto operator+(Punto p1, Punto p2) //Overload dell'operatore somma 
{
    Punto temp;
    temp.setX(p1.getX() + p2.getX());
    temp.setY(p1.getY()+ p2.getY());
    return temp;
}
int main()
{
    Punto a(3.3, 5.7), b(5.2, 9.1), c;
    c = a + b;
    cout << "La somma dei 2 punti e': " <<c.getX()<<"\t"<<c.getY() << endl;
    a - b; 
    //a.operator-(b); //Modo equivalente
    cout << "La sottrazione tra a e b e': " << a.getX() << "\t" << a.getY() << endl;

}

