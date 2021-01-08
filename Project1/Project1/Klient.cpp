#include "Klient.h"
#include "Wypozyczenie.h"
#include <iostream>

using namespace std;

Klient::Klient(string Im, string Naz, string Pes, string Addr, string Numer)
{
	this->Imie = Im;
	this->Nazwisko = Naz;
	this->Pesel = Pes;
	this->Adres = Addr;
	this->Numer_telefonu = Numer;
}
/*
bool Klient::wypozycz()
{
	cout << "Podaj imie: ";
	cin >> Imie;
	cout << "Podaj nazwisko: ";
	cin >> Nazwisko;
	cout << "Podaj pesel: ";
	cin >> Pesel;
	cout << "Podaj adres: ";
	cin >> Adres;
	cout << "Podaj telefon kontaktowy: ";
	cin >> Numer_telefonu;
	cout << "Podaj : ";
	cin >> Imie;


}*/

void Klient::zarzadzaj_wypozyczeniem()
{
	// TODO - implement Klient::zarzadzaj_wypozyczeniem
	throw "Not yet implemented";
}

void Klient::wyswietl_oferte(Pojazd* tablica_pojazdow)
{
	for (int i = 0; i < tablica_pojazdow[0].liczba_pojazdow; i++)
	{
		tablica_pojazdow[i].wyswietl_dane();
		cout << endl;
	}
}

void Klient::dokonaj_platnosci(Wypozyczenie w)
{
	// TODO - implement Klient::dokonaj_platnosci
	throw "Not yet implemented";
}

void Klient::zwroc_pojazd(Wypozyczenie w)
{
	// TODO - implement Klient::zwroc_pojazd
	throw "Not yet implemented";
}
