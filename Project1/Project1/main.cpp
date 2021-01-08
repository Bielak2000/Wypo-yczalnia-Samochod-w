#include <iostream>
#include "Data.h"
#include "Klient.h"
#include "Osoba.h"
#include "Platnosc.h"
#include "Pojazd.h"
#include "Pracownik.h"
#include "Wlasciciel.h"
#include "Wypozyczenie.h"
#include <fstream>
#include <sstream>

using namespace std;

Pojazd* wczytaj_z_pliku(int& n)
{
	//pobranie danych z pliku 
	string linia;//zmienna przehcowuja linie z pliku
	ifstream plik;//zmienna obslugujaca plik 
	plik.open("Pojazdy.txt");//otwieramy nasz plik z przelewami
	//sprawdzamy czy udalo sie otowrzyc plik, jesli nie to wychodzimy z programu
	Pojazd* pojazdy = NULL;
	if (plik.good())
	{
		cout << "Udalo sie otworzyc plik!" << endl;
		int liczba_pojazdow = 0;
		while (getline(plik, linia))
		{
			liczba_pojazdow++;
		}
		plik.clear();
		plik.seekg(0);
		n = liczba_pojazdow;

		pojazdy = new Pojazd[liczba_pojazdow];//utowrzenie tablicy elementow ktorymi sa obiekty strukutry dane o rozmiarze 10000
		//do naszej tablicy przepisuje dane wartosci z pliku
		for (int i = 0; i < liczba_pojazdow; i++)
		{
			getline(plik, linia);
			istringstream iss(linia);
			iss >> pojazdy[i].Numer_rejestracyjny;
			iss >> pojazdy[i].Rodzaj;
			iss >> pojazdy[i].Marka;
			iss >> pojazdy[i].Model;
			iss >> pojazdy[i].Rok;
			iss >> pojazdy[i].Silnik;
			iss >> pojazdy[i].Przebieg;
			iss >> pojazdy[i].Cena_za_godzine;
			iss >> pojazdy[i].Dostepny;
		}
	}
	plik.close();
	return pojazdy;
}

int main()
{
	int n;
	Pojazd* pojazdy = wczytaj_z_pliku(n);


	int wybor;
	cout << "Witaj w naszej wypozyczalni samochdow!" << endl;
	cout << "Kim jestes?";

	cout << "Kim jestes?" << endl;
	cout << "1.Klientem." << endl;
	cin >> wybor;

	if (wybor == 1)
	{
		int wybor1;
		cout << "Wybierz opcje." << endl;
		cout << "1.Wypozyczenie pojazdu." << endl;
		cout << "2.Zarzadzaj wypozyczeniem." << endl;
		cout << "3.Zwroc pojazd." << endl;
		cout << "4.Wyswietl oferte." << endl;
		cout << "5.Dokonaj platnosci." << endl;
		cin >> wybor1;

		if (wybor1 == 1)
		{
			string nr_rej;
			Klient k1("Julek","Starski","123","Liliowa 15","123123");
			cout << "Podaj numer rejestracyjny samochodu ktory chcesz wypozyczyc: ";
			cin >> nr_rej;
			k1.wypozycz(nr_rej);
		}


	}
}