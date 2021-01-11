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
	bool czy_zaplacono();

	bool mozliwosc_odroczenia();

	void dokonaj_platnosci();
};

#endif
