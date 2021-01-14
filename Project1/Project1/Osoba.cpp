#include "Osoba.h"


Osoba::Osoba(string Im, string Naz, string Pes, string Addr, string Numer):
	Imie(Im), Nazwisko(Naz), Pesel(Pes), Adres(Addr), Numer_telefonu(Numer)
{
}

void Osoba::wyswietl_dane()
{
	cout << "Imie i nazwisko:\t" << this->Imie << " " << this->Nazwisko << endl;
	cout << "Pesel:\t\t" << this->Pesel << endl;
	cout << "Numer telefonu:\t" << this->Numer_telefonu << endl;
	cout << "Adres:\t\t" << this->Adres << endl;
}

void Osoba::zmien_dane()
{
	// TODO - implement Osoba::zmien_dane
	throw "Not yet implemented";
}

string Osoba::get_imie()
{
	return Osoba::Imie;
}

string Osoba::get_nazwisko()
{
	return Osoba::Nazwisko;
}

string Osoba::get_pesel()
{
	return Osoba::Pesel;
}

string Osoba::get_adres()
{
	return Osoba::Adres;
}

string Osoba::get_numer_telefonu()
{
	return Osoba::Numer_telefonu;
}
