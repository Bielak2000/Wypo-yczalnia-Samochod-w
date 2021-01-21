#include "Osoba.h"

//Konstruktor parametryzuj¹cy i domyœlny
Osoba::Osoba(string im, string naz, string pes, string addr, string numer):
	imie(im), nazwisko(naz), pesel(pes), adres(addr), numer_telefonu(numer)
{
}

//Metoda zmieniaj¹ca dane osobowe
void Osoba::zmien_dane()
{
	cout << "Prosze podac nastepujace dane:" << endl;
	cout << "Imie: ";
	cin >> imie;
	cout << "Nazwisko: ";
	cin >> nazwisko;
	cout << "Pesel: ";
	cin >> pesel;
	cout << "Adres: ";
	getline(cin, adres);
	getline(cin, adres);
	cout << "Nr telefonu: ";
	cin >> numer_telefonu;
}

//Gettery
string Osoba::get_imie()
{
	return Osoba::imie;
}
string Osoba::get_nazwisko()
{
	return Osoba::nazwisko;
}
string Osoba::get_pesel()
{
	return Osoba::pesel;
}
string Osoba::get_adres()
{
	return Osoba::adres;
}
string Osoba::get_numer_telefonu()
{
	return Osoba::numer_telefonu;
}