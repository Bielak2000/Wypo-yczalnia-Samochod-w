#ifndef POJAZD_H
#define POJAZD_H
#include <iostream>

using namespace std;

class Pojazd
{

private:
	friend Pojazd* wczytaj_z_pliku(int& n);
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

	void wyswietl_dane();

	void zmien_przebieg(string km);

	void uszkodzenia();

	bool sprawdz_dostepnosc(string nr);

	void zmien_cene(int cena);

	void wypozycz();

	void zmien_dostepnosc();

	int get_liczba_pojazdow();

	int get_cena_za_godzine();

	void set_cena_za_godzine(int cena);

	string get_przebieg();

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
