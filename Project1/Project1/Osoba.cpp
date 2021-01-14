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
