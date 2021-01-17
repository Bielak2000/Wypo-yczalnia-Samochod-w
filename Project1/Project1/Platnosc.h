#ifndef PLATNOSC_H
#define PLATNOSC_H
#include <iostream>

using namespace std;

class Platnosc
{

private:
	string Sposob_platnosci;
	int Kwota;
	bool Potwierdzenie;
	bool Odroczenie;

public:
	//Platnosc(string sp = "Gotowka", int kw, bool potw = 0, bool odr = 0);
	Platnosc(int kw=0);

	bool czy_zaplacono();

	bool mozliwosc_odroczenia();

	void dokonaj_platnosci();

	void set_potwierdzenie(bool potw);
};

#endif
