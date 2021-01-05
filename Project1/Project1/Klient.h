#ifndef KLIENT_H
#define KLIENT_H
#include <iostream>
#include "Osoba.h"
#include "Wypozyczenie.h"


using namespace std;

class Klient : public Osoba
{


public:
	Klient(string Im, string Naz, string Pes, string Addr, string Numer);

	bool wypozycz(string nr);

	void zarzadzaj_wypozyczeniem();

	void wyswietl_oferte();

	void dokonaj_platnosci(Wypozyczenie w);

	void zwroc_pojazd(Wypozyczenie w);
};

#endif
