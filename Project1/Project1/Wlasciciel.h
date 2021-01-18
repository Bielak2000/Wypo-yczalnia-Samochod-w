#ifndef WLASCICIEL_H
#define WLASCICIEL_H
#include "Osoba.h"
#include "Pojazd.h"
#include "Wypozyczenie.h"
#include <iostream>

using namespace std;

class Wlasciciel : public Osoba
{
	string login;
	string haslo;
public:

	Wlasciciel();

	void dodaj_pojazd();

	void zmien_cene(string nr_rej, Pojazd* pojazdy);

	void usun_pojazd(string nr_rej, Pojazd* pojazdy);

	void zatwierdz_wypozyczenie(Wypozyczenie w);

	string get_login();
	
	string get_haslo();
};

#endif
