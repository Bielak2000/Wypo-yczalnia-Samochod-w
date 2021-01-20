#include "Wlasciciel.h"
#include "Pojazd.h"
#include "Osoba.h"
#include <fstream>
#include <iostream>
using namespace std;

//Konstruktor domyœlny
Wlasciciel::Wlasciciel(): Osoba("Jan", "Nowak", "92839284782", "Warszawa, ul. Szkolna 5", "983290139"), login("JanNowak"), haslo("Jan123")
{}

//Metoda dodaj¹ca pojazd
void Wlasciciel::dodaj_pojazd()
{
	fstream plik;

	//Otwarcie pliku
	plik.open("Pojazdy.txt");
	if (plik.good())
	{
		//Podanie danych pojazdu do koñca pliku
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
		cout << "Dodano pojazd!" << endl;
		Sleep(2000);
	}
	else
	{
		cout << "Nie udalo sie dodac pojazdu!" << endl;
	}
}

//Metoda zmieniaj¹ca cene pojazdu
void Wlasciciel::zmien_cene(string nr_rej, Pojazd* pojazdy)
{
	for (int i = 0; i < pojazdy[0].get_liczba_pojazdow(); i++)
	{
		if (pojazdy[i].get_numer_rejestracyjny() == nr_rej)
		{
			int nowa_cena;
			cout << "Podaj nowa cene za godzine dla tego pojazdu: ";
			cin >> nowa_cena;
			pojazdy[i].zmien_cene_pojazdu(nowa_cena);
			pojazdy[i].aktualizuj_plik(pojazdy);
			cout << "Cena zostala zmieniona!" << endl;
			Sleep(2000);
			break;
		}
	}
}

//Metoda usuwaj¹ca pojazd
void Wlasciciel::usun_pojazd(string nr_rej, Pojazd* pojazdy)
{
	int jest = -1;	//zmienna na indeks pojazdu w pliku

	//przeszukujemy tablice w poszukiwaniu pojazdu do usuniecia
	for (int i = 0; i < pojazdy[i].get_liczba_pojazdow(); i++)
		if (pojazdy[i].get_numer_rejestracyjny() == nr_rej)	
		{
			jest = i;
			break;
		}

	if (jest == -1)
		cout << "Pojazd nie zostal usuniety, gdyz nie ma go w pliku.";
	else
	{
		if (pojazdy[jest].get_dostepnosc() == 1)
		{
			ofstream plik;
			plik.open("Pojazdy.txt");	//nadpisujemy plik
			for (int i = 0; i < pojazdy[i].get_liczba_pojazdow(); i++)
			{
				if (i == jest) continue;	//pomijanie dopisania pojazdu usuwanego
				if (!(i == 1 && jest == 0)) //warunek pomijaj¹cy koniec lini w przypadku gdy pierwsza linia pliku jest edytowana
				if (i != 0) plik << "\n";	//warunek, aby nie zrobic pustej linii na poczatku pliku
				plik << pojazdy[i].get_numer_rejestracyjny() << " ";
				plik << pojazdy[i].get_rodzaj() << " ";
				plik << pojazdy[i].get_marka() << " ";
				plik << pojazdy[i].get_model() << " ";
				plik << pojazdy[i].get_rok() << " ";
				plik << pojazdy[i].get_silnik() << " ";
				plik << pojazdy[i].get_przebieg() << " ";
				plik << pojazdy[i].get_cena_za_godzine() << " ";
				plik << pojazdy[i].get_dostepnosc();
			}
			cout << "Usunieto pojazd!" << endl;
			Sleep(2000);
		}
		else
		{
			cout << "Pojazd jest niedostpeny! Nie mozna go usunac!" << endl;
			Sleep(2000);
			system("cls");
		}
	}
}

//Gettery
string Wlasciciel::get_login()
{
	return Wlasciciel::login;
}

string Wlasciciel::get_haslo()
{
	return Wlasciciel::haslo;
}
