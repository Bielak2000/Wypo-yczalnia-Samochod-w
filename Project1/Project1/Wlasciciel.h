#ifndef WLASCICIEL_H
#define WLASCICIEL_H
#include "Pracownik.h"
#include "Pojazd.h"
#include <iostream>

using namespace std;

class Wlasciciel : public Pracownik
{
public:

	Wlasciciel();

	void dodaj_pojazd();

	void zmien_cene(string nr_rej, Pojazd* pojazdy);

	void usun_pojazd(string nr_rej);

	void zarzadzaj_dzialalnoscia();

	string get_login_wlasciciela();

	string get_haslo_wlasciciela();
};

#endif
