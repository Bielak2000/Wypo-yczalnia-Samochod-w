#ifndef PRACOWNIK_H
#define PRACOWNIK_H
#include "Osoba.h"
#include "Wypozyczenie.h"
#include <iostream>

using namespace std;

class Pracownik : Osoba
{
	const string login;
	const string haslo;

public:
	void zatwierdz_wypozyczenie(Wypozyczenie w);

	void zatwierdz_zwrot(Wypozyczenie w);

	void zatwierdz_zmiany(Wypozyczenie w);
};

#endif
