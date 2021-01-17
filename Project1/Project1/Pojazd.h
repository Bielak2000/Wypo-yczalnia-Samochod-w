#ifndef POJAZD_H
#define POJAZD_H
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Pojazd
{

private:
	string Numer_rejestracyjny;
	string Rodzaj;
	string Marka;
	string Model;
	int Rok;
	string Silnik;
	string Przebieg;
	bool Dostepny;
	int Cena_za_godzine;
	static int liczba_pojazdow;

public:
	Pojazd();

	Pojazd(string n, string rodz, string mar, string mod, int r,
		string sil, string przeb, int cen_godz, bool dost);

	void wyswietl_dane();

	void zmien_przebieg(string km);

	bool sprawdz_dostepnosc(string nr);

	void zmien_cene_pojazdu(int cena);

	void wypozycz();

	void zmien_dostepnosc();

	static Pojazd* wczytaj_z_pliku(int& n);

	void aktualizuj_plik(Pojazd* pojazdy);

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


	void set_cena_za_godzine(int cena);

	void set_dostepny(bool dostep);

	void set_przebieg(string km);

	/*
	void set_numer_rejestracyjny(string numer);

	void set_rodzaj(string rodz);

	void set_marka(string mark);

	void set_model(string mod);

	void set_rok(string ro);

	void set_silnik(string siln);

	void set_przebieg(string przeb);

	void set_cena_za_godzine(int cena);

	void set_dostepny(bool zmienna);*/
};

#endif
