#include "Pracownik.h"
#include <iostream>
#include <fstream>
//#include "Wypozyczenie.h"

using namespace std;

Pracownik::Pracownik(string Im, string Naz, string Pes, string Addr, string Numer) {
	this->Imie = Im;
	this->Nazwisko = Naz;
	this->Pesel = Pes;
	this->Adres = Addr;
	this->Numer_telefonu = Numer;
	this->Haslo = Pes;
	this->Login = Im+Naz;
}

void Pracownik::zatwierdz_wypozyczenie(Wypozyczenie w)
{
	ofstream plik;
	plik.open("Wypozyczenia.txt");
	plik << w.Numer_rejestracyjny << " ";
	plik << w.pesel << " ";
	plik << w.Data_do.dzien << " " << w.Data_do.miesiac << " " << w.Data_do.rok << " " << w.Data_do.godzina << "  ";
	plik << w.Data_od.dzien << " " << w.Data_od.miesiac << " " << w.Data_od.rok << " " << w.Data_od.godzina << "  ";
	plik << w.termin_platnosci.dzien << " " << w.termin_platnosci.miesiac << " " << w.termin_platnosci.rok << " " << w.termin_platnosci.godzina << endl;;

	cout << "Wypozyczenie zatwierdzono!" << endl;
	plik.close();
}

void Pracownik::zatwierdz_zwrot(Wypozyczenie w)
{
	w.Zakonczone = true;
}

void Pracownik::zatwierdz_zmiany(Wypozyczenie w)
{
	// TODO - implement Pracownik::zarzadzaj_wypozyczeniem
	throw "Not yet implemented";
}
