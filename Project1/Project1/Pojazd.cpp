#include "Pojazd.h"


int Pojazd::liczba_pojazdow = 0;

Pojazd::Pojazd()
{
	Pojazd::liczba_pojazdow++;
}

void Pojazd::wyswietl_dane()
{
	cout << "Numer rejestracyjny: " << Numer_rejestracyjny;
	cout << ", rodzaj: " << Rodzaj;
	cout << ", marka: " << Marka;
	cout << ", model: " << Model;
	cout << ", rok: " << Rok;
	cout << ", silnik: " << Silnik;
	cout << ", przebieg: " << Przebieg;
	if (Dostepny == 1)
		cout << "Dostepny: TAK";
	else
		cout << "Dostepny: NIE";
	cout << ", cena za godzine: " << Cena_za_godzine << ".";
}

void Pojazd::zmien_przebieg(string km)
{
	Przebieg = km;
}

bool Pojazd::sprawdz_dostepnosc(string nr)
{
	if (Dostepny == 1)
	{
		cout << "Pojazd jest dostepny." << endl;
		return true;
	}
	else
	{
		cout << "Pojazd jest niedostepny." << endl;
		return false;
	}
}

void Pojazd::zmien_cene(int cena)
{
	Cena_za_godzine = cena;
}

void Pojazd::wypozycz()
{
	// TODO - implement Pojazd::wypozycz
	throw "Not yet implemented";
}

void Pojazd::zmien_dostepnosc()
{
	// TODO - implement Pojazd::zmien_dostepnosc
	throw "Not yet implemented";
}

