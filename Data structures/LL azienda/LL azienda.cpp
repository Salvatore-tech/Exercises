/* LL azienda.cpp : This file contains the 'main' function. Program execution begins and ends there.
Progettare ed implementare una lista (linked list) di impiegati di un'azienda.
Un impiegato ha un nome ed un salario. Un manager è un impiegato cui viene corrisposto un bonus oltre al salario.
1) Creare una lista di impiegati e stamparla a video sfruttando il principio del polimorfismo
2) Implementare l'overload dell'operatore + in modo da sommare i salari di tutti gli impiegati.

N.B. se l'overload dell'operatore avviene come metodo della funzione allora avrà un argomento in meno rispetto al numero
di operando (1 invece di 2). Ciò è utilizzabile solo se il primo operando è un oggetto della stessa classe
*/

#include <iostream>
#include <string>
using namespace std;

typedef struct node {
	int salario;
	string nome;
	struct node* next;
}Node;


class Impiegato {

protected:
	Node* head;
	Node* tail;
	Node* createNode(string& nome, int salario);
public:
	Impiegato() : head{ nullptr }, tail{ nullptr } {};
	void insertTail(string& nome, int salario);
	virtual void visita();
	virtual int operator+()
	{
		int tot = 0;
		Node* temp;
		for (temp=head; temp!=nullptr; temp=temp->next)
			tot += temp->salario;
		return tot;
	}
};


Node* Impiegato::createNode(string& nome, int salario)
{
	Node* temp = new Node;
	temp->nome = nome;
	temp->salario = salario;
	temp->next = nullptr;
	return temp;
}

void Impiegato::insertTail(string& nome, int salario)
{
	Node* nuovo = createNode(nome, salario);
	if (head == NULL)
	{
		head = nuovo;
		tail = nuovo;
		nuovo = nullptr;
	}
	else
	{
		tail->next = nuovo;
		tail = nuovo;
	}
}

void Impiegato::visita() 
{
	int totale = 0;
	for (Node* app=this->head; app != nullptr; app = app->next)
		cout << "Nome: " << app->nome << "\tSalario: " << app->salario << endl;
}


class Manager :public Impiegato {
	int bonus;
public:
	Manager() { bonus = 100; };
	void visita ();
	int operator+()
	{
		int tot = 0;
		Node* temp;
		for (temp = this->head; temp != nullptr; temp=temp->next)
		{
			tot += temp->salario;
			tot += this->bonus;
		}
		return tot;
	}
};
void Manager::visita()
{
	int totale = 0;
	Node* app;
	for(app=this->head; app!=nullptr; app=app->next)
		cout << "Nome: " << app->nome << "\tSalario: " << app->salario <<"\tBonus: "<<bonus<<endl;
}



int main()
{
	Impiegato i1, i2;
	string s;
	int salario, totale;
	cout << "--- Inserisci nome e salario per creare lista di impiegati ---" << endl;
	for(int i=0; i<5; i++)
	{
		cin >> s;
		cin >> salario;
		i1.insertTail(s, salario);
	}
	i1.visita();

	/* Modi equivalenti di chiamare la funzione operator+:
	1) totale= i1.operator+();
	2) totale = +i1;
	*/
	cout << "Il totale dei salari e': " <<+i1<< endl; //Chiamata all'overload dell'operatore operator +

	/*Polimorfismo, creazione di puntatori di oggetti, quest'ultimi sono associati in late binding,
	*/
	Impiegato* arr[10];
	for (int i = 0; i < 3; i++) //Le prime 3 componenti dell'array sono oggetti impiegati
	{
		arr[i] = new Impiegato();
		cin >> s;
		cin >> salario;
		arr[i]->insertTail(s, salario);
	}
	for (int i = 3; i < 5; i++) //Le successive 2 componenti sono oggetti manager
	{
		arr[i] = new Manager();
		cin >> s;
		cin >> salario;
		arr[i]->insertTail(s, salario);
	}
	totale = 0;
	for (int i = 0; i < 5; i++) //Stampa l'array in modo polimorfo di impiegati e manager
	{
		arr[i]->visita();
		totale += arr[i]->operator+();
	};
	//cout << "Il totale dell'insieme di manager e impiegati e' " << arr[0]->operator+() << endl;
	cout << "Il totale dell'insieme di manager e impiegati e' " << totale << endl;

	

}
