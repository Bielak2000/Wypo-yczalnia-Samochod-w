#ifndef WYPOZYCZENIE_H
#define WYPOZYCZENIE_H
#include "Data.h"
#include "Osoba.h"
#include <iostream>

using namespace std;

class Wypozyczenie
{

public:
	Data Data_od;
	Data Data_do;
	string Numer_rejestracyjny;
	bool Zakonczone = 0;
	string pesel;
	Data termin_platnosci = Data_do;

public:
	//Wypozyczenie();

	bool zmien_okres();

	void zakoncz_wypozyczenie();

	Data zwroc_date_zakonczenia();

	void dodaj_auto(string nr);

	void pesel_klienta(string nr_pesel);

	void podaj_termin();

	void zaplac();

	void skroc_okres(Data rozpoczecie, Data zakonczenie);

	void wydluz_okres(Data rozpoczecie, Data zakonczenie);

	void zmien_termin_platnosci(Data d);

	Data zwroc_date_rozpoczecia();
};

#endif
