#include "Wlasciciel.h"
#include "Pojazd.h"
#include <fstream>
#include <iostream>
using namespace std;

Wlasciciel::Wlasciciel(): Pracownik("Jan", "Nowak", "92839284782", "Warszawa, ul. Szkolna 5", "983290139")
{
}

void Wlasciciel::dodaj_pojazd()
{
	fstream plik;
	plik.open("Pojazdy.txt");
	if (plik.good())
	{
		plik.seekg(0, ios::end);
		cout << "Podaj dane pojazdu:" << endl;
		string Numer_rejestracyjny, Rodzaj, Marka, Model, Rok, Silnik, Przebieg, Cena_za_godzine;
		cout << "Numer_rejestracyjny: ";
		cin>>Numer_rejestracyjny;
		cout << "Rodzaj: ";
		cin>>Rodzaj;
		cout << "Marka: ";
		cin>>Marka;
		cout << "Model: ";
		cin>>Model;
		cout << "Rok: ";
		cin >> Rok;
		cout << "Silnik: ";
		cin >> Silnik;
		cout << "Przebieg[w km]: ";
		cin >> Przebieg;
		cout << "Cena za godzine[w zl]: ";
		cin >> Cena_za_godzine;
		plik << "\n" << Numer_rejestracyjny << " " << Rodzaj << " " << Marka << " " << Model << " " <<
			Rok << " " << Silnik << " " << Przebieg << " " << Cena_za_godzine << " 1";
	}
	else
	{
		cout << "Nie udalo sie dodac pojazdu!" << endl;
	}
}

void Wlasciciel::zmien_cene(string nr_rej, Pojazd* pojazdy)
{
	//int n;
	//Pojazd* pojazdy = Pojazd::wczytaj_z_pliku(n);
	for (int i = 0; i < pojazdy[0].get_liczba_pojazdow(); i++)
	{
		if (pojazdy[i].get_numer_rejestracyjny() == nr_rej)
		{
			int nowa_cena;
			cout << "Podaj nowa cene za godzine dla tego pojazdu: ";
			cin >> nowa_cena;
			pojazdy[i].zmien_cene_pojazdu(nowa_cena);
			pojazdy[i].aktualizuj_plik(pojazdy);
			break;
		}
	}
}

void Wlasciciel::usun_pojazd(string nr_rej)
{
	// TODO - implement Wlasciciel::usun_pojazd
	throw "Not yet implemented";
}

void Wlasciciel::zarzadzaj_dzialalnoscia()
{
	// TODO - implement Wlasciciel::zarzadzaj_dzialalnoscia
	throw "Not yet implemented";
}
