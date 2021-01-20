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
	static int liczba_klientow;//statyczne pole ktore przechowuje liczbe klientow wypozyczalni

public:
	//konstuktor pelniacy rowniez role konstuktora domyslnego tej klasy
	Klient(string Im = "Niezdefiniowane", string Naz = "Niezdefiniowane", string Pes = "Niezdefiniowane",
		string Addr = "Niezdefiniowane", string Numer = "Niezdefiniowane");
	
	bool wypozycz(Pojazd* pojazdy);//metoda sluzaca wypozyczenia pojazdu

	void wyswietl_oferte(Pojazd* tablica_pojazdow);//metoda sluzaca do wyswietlania oferty, czyli pojazdow wraz z ich wszytskimi informacjami

	void zwroc_pojazd(Wypozyczenie * tablica_w, Pojazd * tablica_pojazdow);//metoda sluzaca zwortu wypozyczonego pojazdu

	static Klient* wczytaj_z_pliku(int& n);	//wczytywanie z pliku klientow do tablicy

	void aktualizuj_plik(Klient* klienci);	//aktualizacja pliku z klientami

	int get_liczba_klientow();//getter 

	void zmniejsz_liczba_klientow();//metoda sluzaca do zmniejszenia liczby klientow

	void dokonaj_platnosci(Wypozyczenie* tablica_w);//metoda dokonujaca platnosci za wypozyczenie
};

#endif
