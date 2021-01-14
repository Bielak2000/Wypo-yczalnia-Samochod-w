#ifndef PLATNOSC_H
#define PLATNOSC_H
#include <iostream>

using namespace std;

class Platnosc
{

public:
	string Sposob_platnosci;
	int Kwota;
	bool Potwierdzenie;
	bool Odroczenie;


	bool czy_zaplacono();

	bool mozliwosc_odroczenia();

	void dokonaj_platnosci();

	void zaplac_karta();

	void zaplac_gotowka();
};

#endif
