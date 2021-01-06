#ifndef OSOBA_H
#define OSOBA_H
#include<iostream>

using namespace std;

class Osoba
{

public:
	string Imie;
	string Nazwisko;
	string Pesel;
	string Adres;
	string Numer_telefonu;

public:

	//Osoba(string Im, string Naz, string Pes, string Addr, string Numer);

	void wyswietl_dane();

	void zmien_dane();
};

#endif
