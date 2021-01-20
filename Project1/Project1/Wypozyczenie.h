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
	Data data_od;
	Data data_do;
	string numer_rejestracyjny;
	string pesel;
	bool zakonczone = 0;
	Data termin_platnosci = data_do;
	Platnosc rachunek;
	static int liczba_wypozyczen;

public:
	Wypozyczenie(Data d1=0, Data d2=0, string nr_rej="0", string pes="0", int cena=0); //konstruktor domyslny

	void zaplac(Wypozyczenie* tab_w);	//ustalanie sposobu platnosci i zaplacenie lub ewentualne odroczenie

	bool skroc_okres(Data nowe_zakonczenie);	//metoda do skracania okresu wypozyczenia przyjmujaca nowe zakonczenie

	bool wydluz_okres(Data nowe_zakonczenie);	//metoda do wydluzania okresu wypozyczenia przyjmujaca nowe zakonczenie

	static Wypozyczenie* wczytaj_z_pliku(int& w);	//wczytywanie wypozyczen z pliku do tablicy

	void aktualizuj_plik(Wypozyczenie* wypozyczenia);	//aktualizacja pliku z wypozyczeniami, takze z tymi, ktore juz minely
	
	//gettery do pol klasy
	string get_numer_rejestracyjny();
	string get_pesel();
	bool get_zakonczone();
	Data get_data_od();
	Data get_data_do();
	Data get_termin_platnosci();
	Platnosc * get_rachunek1();	//zwraca wskaznik, zeby pracowac na oryginale
	Platnosc get_rachunek();

	//settery do pol klasy
	void set_nr_rej(string nr);
	void set_pesel(string pes);
	void set_zakonczone(bool zakon);
	void set_termin_platnosci(Data d);
	static int get_liczba_wypozyczen();
};

#endif
