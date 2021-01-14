#include "Pracownik.h"
#include <iostream>
#include <fstream>
//#include "Wypozyczenie.h"

using namespace std;

Pracownik::Pracownik(string Im, string Naz, string Pes, string Addr, string Numer):
	Osoba(Im, Naz, Pes, Addr, Numer), Haslo(Pes), Login(Im + Naz)
{
}

void Pracownik::zatwierdz_wypozyczenie(Wypozyczenie w)
{
	ofstream plik;
	plik.open("Wypozyczenia.txt");
	plik << w.get_numer_rejestracyjny() << " ";
	plik << w.get_pesel() << " ";
	plik << w.get_data_do().get_dzien() << " " << w.get_data_do().get_miesiac() << " " << w.get_data_do().get_rok() << " " << w.get_data_do().get_godzina() << "  ";
	plik << w.get_data_od().get_dzien() << " " << w.get_data_od().get_miesiac() << " " << w.get_data_od().get_rok() << " " << w.get_data_od().get_godzina() << "  ";
	plik << w.get_termin_platnosci().get_dzien() << " " << w.get_termin_platnosci().get_miesiac() << " " << w.get_termin_platnosci().get_rok() << " " << w.get_termin_platnosci().get_godzina() << endl;;

	cout << "Wypozyczenie zatwierdzono!" << endl;
	plik.close();
}

void Pracownik::zatwierdz_zwrot(Wypozyczenie w)
{
	// TODO - implement Pracownik::zatwierdz_zwrot
	throw "Not yet implemented";
}

void Pracownik::zatwierdz_zmiany(Wypozyczenie w)
{
	// TODO - implement Pracownik::zarzadzaj_wypozyczeniem
	throw "Not yet implemented";
}

string Pracownik::get_login()
{
	return Pracownik::Login;
}

string Pracownik::get_haslo()
{
	return Pracownik::Haslo;
}
