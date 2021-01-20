#ifndef OSOBA_H
#define OSOBA_H
#include<iostream>
#include<string>

using namespace std;

class Osoba
{

protected:
	string imie;
	string nazwisko;
	string pesel;
	string adres;
	string numer_telefonu;

public:

	//Konstruktor parametryzuj¹cy i domyœlny
	Osoba(string Im = "Niezdefiniowane", string Naz = "Niezdefiniowane", string Pes = "Niezdefiniowane",
		string Addr = "Niezdefiniowane", string Numer = "Niezdefiniowane");

	void zmien_dane();	//Metoda zmieniaj¹ca dane osobowe

	//Gettery
	string get_imie();
	string get_nazwisko();
	string get_pesel();
	string get_adres();
	string get_numer_telefonu();

};

#endif
