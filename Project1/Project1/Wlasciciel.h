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
	
	Wlasciciel();		//Konstruktor domyslny w�a�ciciela

	void dodaj_pojazd();	//Metoda dodaj�ca pojazd	

	void zmien_cene(string nr_rej, Pojazd* pojazdy);	//Metoda zmieniaj�ca cene pojazdu

	void usun_pojazd(string nr_rej, Pojazd* pojazdy);	//Metoda usuwaj�ca pojazd

	//Gettery
	string get_login();
	string get_haslo();
};

#endif
