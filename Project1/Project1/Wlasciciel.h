#ifndef WLASCICIEL_H
#define WLASCICIEL_H
#include "Pracownik.h"
#include <iostream>

using namespace std;

class Wlasciciel : Pracownik
{


public:
	void dodaj_pojazd();

	void zmien_cene(string nr_rej);

	void usun_pojazd(string nr_rej);

	void zarzadzaj_dzialalnoscia();
};

#endif
