#ifndef PRACOWNIK_H
#define PRACOWNIK_H
#include "Osoba.h"
#include <iostream>

using namespace std;

class Pracownik : Osoba
{


public:
	bool zatwierdz_wypozyczenie(string nr, string pesel);

	bool zatwierdz_zwrot(string nr, string pesel);

	void zarzadzaj_wypozyczeniem(string pesel, string nr);
};

#endif
