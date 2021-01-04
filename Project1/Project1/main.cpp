#include <iostream>
#include "Data.h"
#include "Klient.h"
#include "Osoba.h"
#include "Platnosc.h"
#include "Pojazd.h"
#include "Pracownik.h"
#include "Wlasciciel.h"
#include "Wypozyczenie.h"

using namespace std;

int main()
{
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
			Klient k1;
			cout << "Podaj numer rejestracyjny samochodu ktory chcesz wypozyczyc: ";
			cin >> nr_rej;
			k1.wypozycz(nr_rej);
		}


	}


}