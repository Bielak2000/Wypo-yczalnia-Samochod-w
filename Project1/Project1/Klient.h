#ifndef KLIENT_H
#define KLIENT_H
#include <iostream>
#include "Osoba.h"
#include "Wypozyczenie.h"
#include "Pojazd.h"


using namespace std;

class Klient : public Osoba
{


public:
	Klient(string Im="0", string Naz="0", string Pes="0", string Addr="0", string Numer="0");
	
	bool wypozycz(Pojazd* pojazdy);

	void zarzadzaj_wypozyczeniem();

	void wyswietl_oferte(Pojazd* tablica_pojazdow);

	void zwroc_pojazd(Wypozyczenie w);
};

#endif
