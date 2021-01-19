#include "Wypozyczenie.h"
#include "Platnosc.h"
#include <iostream>

using namespace std;

Wypozyczenie::Wypozyczenie(Data d1, Data d2, string nr_rej, string pes, int cena):Data_od(d1), Data_do(d2), Numer_rejestracyjny(nr_rej), pesel(pes)
{
	Wypozyczenie::Rachunek.set_kwota(cena);
}

bool Wypozyczenie::zmien_okres()
{
	// TODO - implement Wypozyczenie::zmien_okres
	throw "Not yet implemented";
}

void Wypozyczenie::zakoncz_wypozyczenie()
{
	// TODO - implement Wypozyczenie::zakoncz_wypozyczenie
	throw "Not yet implemented";
}

Data Wypozyczenie::zwroc_date_zakonczenia()
{
	// TODO - implement Wypozyczenie::zwroc_date_zakonczenia
	throw "Not yet implemented";
}

void Wypozyczenie::dodaj_auto(string nr)
{
	// TODO - implement Wypozyczenie::dodaj_auto
	throw "Not yet implemented";
}

void Wypozyczenie::pesel_klienta(string nr)
{
	pesel = nr;
}

void Wypozyczenie::podaj_termin()
{
	// TODO - implement Wypozyczenie::podaj_termin
	throw "Not yet implemented";
}

void Wypozyczenie::zaplac()
{
	// TODO - implement Wypozyczenie::zaplac
	throw "Not yet implemented";
}

void Wypozyczenie::skroc_okres(Data rozpoczecie, Data zakonczenie)
{
	// TODO - implement Wypozyczenie::skroc_okres
	throw "Not yet implemented";
}

void Wypozyczenie::wydluz_okres(Data rozpoczecie, Data zakonczenie)
{
	// TODO - implement Wypozyczenie::wydluz_okres
	throw "Not yet implemented";
}

void Wypozyczenie::zmien_termin_platnosci(Data d)
{
	// TODO - implement Wypozyczenie::zmien_termin_platnosci
	throw "Not yet implemented";
}

bool Wypozyczenie::get_zakonczone()
{
	return Wypozyczenie::Zakonczone;
}

Data Wypozyczenie::zwroc_date_rozpoczecia()
{
	// TODO - implement Wypozyczenie::zwroc_date_rozpoczecia
	throw "Not yet implemented";
}

string Wypozyczenie::get_numer_rejestracyjny()
{
	return Wypozyczenie::Numer_rejestracyjny;
}

string Wypozyczenie::get_pesel()
{
	return Wypozyczenie::pesel;
}

Data Wypozyczenie::get_data_od()
{
	return Wypozyczenie::Data_od;
}

Data Wypozyczenie::get_data_do()
{
	return Wypozyczenie::Data_do;
}

Data Wypozyczenie::get_termin_platnosci()
{
	return Wypozyczenie::termin_platnosci;
}

Platnosc Wypozyczenie::get_rachunek()
{
	return Wypozyczenie::Rachunek;
}