#ifndef KLIENT_H
#define KLIENT_H
#include <iostream>
#include <windows.h>
#include <time.h>
#include "Osoba.h"
#include "Wypozyczenie.h"
#include "Pojazd.h"


using namespace std;

class Klient : public Osoba
{
	static int liczba_klientow;

public:
	Klient(string Im = "Niezdefiniowane", string Naz = "Niezdefiniowane", string Pes = "Niezdefiniowane",
		string Addr = "Niezdefiniowane", string Numer = "Niezdefiniowane");
	
	bool wypozycz(Pojazd* pojazdy);

	void wyswietl_oferte(Pojazd* tablica_pojazdow);

	void zwroc_pojazd(Wypozyczenie * tablica_w, Pojazd * tablica_pojazdow);

	static Klient* wczytaj_z_pliku(int& n);	//wczytywanie z pliku klientow do tablicy

	void aktualizuj_plik(Klient* klienci);	//aktualizacja pliku z klientami

	int get_liczba_klientow();

	void zmniejsz_liczba_klientow();

	void dokonaj_platnosci(Wypozyczenie* tablica_w);
};

#endif
