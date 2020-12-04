#ifndef POJAZD_H
#define POJAZD_H

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
	string Kolor;
	boolean Uszkodzony;
	boolean Wypozyczenie;
	boolean Dostepny;
	int Cena_za_godzine;
	int Liczba_wypozyczen;
	static int liczba_pojazdow;

public:
	void wyswietl_dane();

	void zmien_przebieg(string km);

	void uszkodzenia();

	boolean sprawdz_dostepnosc(string nr);

	void usun_uszkodzenia();

	void zmien_cene(int cena);

	void wypozycz();

	int sprawdz_uszkodzenia();

	void zmien_dostepnosc();

	void napraw();
};

#endif
