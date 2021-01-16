#ifndef OSOBA_H
#define OSOBA_H
#include<iostream>

using namespace std;

class Osoba
{

protected:
	string Imie;
	string Nazwisko;
	string Pesel;
	string Adres;
	string Numer_telefonu;

public:

	Osoba(string Im, string Naz, string Pes, string Addr, string Numer);

	void wyswietl_dane();

	void zmien_dane();

	string get_imie();

	string get_nazwisko();

	string get_pesel();

	string get_adres();

	string get_numer_telefonu();

};

#endif
