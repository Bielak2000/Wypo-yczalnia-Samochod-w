#ifndef OSOBA_H
#define OSOBA_H

class Osoba
{

private:
	string Imie;
	string Nazwisko;
	string Pesel;
	string Adres;
	string Numer_telefonu;

public:
	void wyswietl_dane();

	void zmien_dane();
};

#endif
