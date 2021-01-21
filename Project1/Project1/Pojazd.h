#ifndef POJAZD_H
#define POJAZD_H
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Pojazd
{
private:
	string numer_rejestracyjny;
	string rodzaj;
	string marka;
	string model;
	int rok;
	string silnik;
	string przebieg;
	bool dostepny;
	int cena_za_godzine;
	static int liczba_pojazdow;

public:

	//konstruktor tej klasy ktory tez jest konstruktorem domyslnym tej klasy
	Pojazd(string nr_rej="Niezdefiniowane", string rodzajj = "Niezdefiniowane", string markaa = "Niezdefiniowane", string modell = "Niezdefiniowane", int rokk = 0,
		string silnikk = "Niezdefiniowane", string przebiegg = "Niezdefiniowane", int cena_godz = 0, bool dostepnoscc = false);

	void wyswietl_dane();//metoda sluzaca do wyswietlania danych o pojezdzie

	void zmien_przebieg(string km);//metoda sluzaca do zmiany przebiegu

	void zmien_cene_pojazdu(int cena);	//metoda sluzaca do zmiany ceny pojazdu

	void zmien_dostepnosc();//metoda sluzaca do zmiany dostepnosci na przecwina

	static Pojazd* wczytaj_z_pliku(int& n);		//wczytywanie z pliku pojazdow do tablicy

	void aktualizuj_plik(Pojazd* pojazdy);	//aktualizowanie pliku z pojazdami

	//gettery
	string get_numer_rejestracyjny();
	string get_rodzaj();
	string get_marka();
	string get_model();
	int get_rok();
	string get_silnik();
	string get_przebieg();
	bool get_dostepnosc();
	int get_cena_za_godzine();
	int get_liczba_pojazdow();

	void set_dostepny(bool dostep);//setter do zmien dostepnosc
};

#endif
