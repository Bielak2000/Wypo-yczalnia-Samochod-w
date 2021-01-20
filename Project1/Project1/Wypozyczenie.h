#ifndef WYPOZYCZENIE_H
#define WYPOZYCZENIE_H
#include "Data.h"
#include "Osoba.h"
#include "Platnosc.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>

using namespace std;

class Wypozyczenie
{

private:
	Data Data_od;
	Data Data_do;
	string Numer_rejestracyjny;
	string pesel;
	bool Zakonczone = 0;
	Data termin_platnosci = Data_do;
	Platnosc Rachunek;
	static int liczba_wypozyczen;

public:
	Wypozyczenie(Data d1=0, Data d2=0, string nr_rej="0", string pes="0", int cena=0);

	bool zmien_okres();

	void zakoncz_wypozyczenie();

	Data zwroc_date_zakonczenia();

	void dodaj_auto(string nr);

	void pesel_klienta(string nr_pesel);

	void podaj_termin();

	void zaplac(Wypozyczenie* tab_w);

	void skroc_okres(Data rozpoczecie, Data zakonczenie);

	void wydluz_okres(Data rozpoczecie, Data zakonczenie);

	void zmien_termin_platnosci(Data d);

	Data zwroc_date_rozpoczecia();

	string get_numer_rejestracyjny();

	string get_pesel();

	bool get_zakonczone();

	Data get_data_od();

	Data get_data_do();

	Data get_termin_platnosci();

	Platnosc * get_rachunek1();
	Platnosc get_rachunek();

	static Wypozyczenie* wczytaj_z_pliku(int& w);

	void set_nr_rej(string nr);

	void set_pesel(string pes);

	void set_zakonczone(bool zakon);

	static int get_liczba_wypozyczen();

	void aktualizuj_plik(Wypozyczenie * wypozyczenia);
};

#endif
