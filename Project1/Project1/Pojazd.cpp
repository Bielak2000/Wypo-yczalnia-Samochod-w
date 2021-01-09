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

int Pojazd::get_liczba_pojazdow()
{
	return Pojazd::liczba_pojazdow;
}

int Pojazd::get_cena_za_godzine()
{
	return Pojazd::Cena_za_godzine;
}

void Pojazd::set_cena_za_godzine(int cena)
{
	Cena_za_godzine = cena;
}

string Pojazd::get_przebieg()
{
	return Pojazd::Przebieg;
}

void Pojazd::set_przebieg(string km)
{
	Przebieg = km;
}

/*
void Pojazd::set_numer_rejestracyjny()
{

}

void Pojazd::set_rodzaj();

void Pojazd::set_marka();

void Pojazd::set_model();

void Pojazd::set_rok();

void Pojazd::set_silnik();

void Pojazd::set_przebieg();

void Pojazd::set_cena_za_godzine();

void Pojazd::set_dostepny();


string Pojazd::get_numer_rejestracyjny()
{
	return Pojazd::Numer_rejestracyjny;
}

string Pojazd::get_rodzaj()
{
	return Pojazd::Rodzaj;
}

string Pojazd::get_marka()
{
	return Pojazd::Marka;
}

string Pojazd::get_model()
{
	return Pojazd::Model;
}

int Pojazd::get_rok()
{
	return Pojazd::Rok;
}

string Pojazd::get_silnik()
{
	return Pojazd::Silnik;
}

string Pojazd::get_przebieg()
{
	return Pojazd::Przebieg;
}

int Pojazd::get_cena_za_godzine()
{
	return Pojazd::Cena_za_godzine;
}

bool Pojazd::get_dostepny()
{
	if (Pojazd::Dostepny == 1)
		return true;
	else
		return false;
}*/

