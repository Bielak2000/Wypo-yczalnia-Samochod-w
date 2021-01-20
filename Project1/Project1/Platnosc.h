#ifndef PLATNOSC_H
#define PLATNOSC_H
#include <iostream>

using namespace std;

class Platnosc
{
private:
	string sposob_platnosci;
	int kwota;
	bool potwierdzenie;

public:

	Platnosc(int kw=0);			//Konstruktor

	bool czy_zaplacono();		//Metoda sprawdzaj¹ca czy dokonano p³atnoœci (getter pola potwierdzenie)

	//Settery
	void set_kwota(int cena);
	void set_sposob_platnosci(string sposob);
	void set_potwierdzenie(bool potw);

	//Gettery
	string get_sposob_platnosci();
	int get_kwota();
	bool get_potwierdzenie();


};

#endif
