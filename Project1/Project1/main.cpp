#include <iostream>
#include <windows.h>
#include "Data.h"
#include "Klient.h"
#include "Osoba.h"
#include "Platnosc.h"
#include "Pojazd.h"
#include "Wlasciciel.h"
#include "Wypozyczenie.h"
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	int n;
	Pojazd* pojazdy = Pojazd::wczytaj_z_pliku(n);
	int k;
	Klient* klienci = Klient::wczytaj_z_pliku(k);

	system("cls");
	int wybor;
	cout << "Witaj w naszej wypozyczalni pojazdow!" << endl;
	Sleep(3000);
	system("cls");

	cout << "Kim jestes?" << endl;
	cout << "1.Klientem." << endl;
	cout << "2.Wlascicielem." << endl;
	cin >> wybor;
	system("cls");

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
		system("cls");

		if (wybor1 == 1)
		{
			Klient k;
			k.wypozycz(pojazdy);
		}
		else if (wybor1 == 2)
		{

		}
		else if (wybor1 == 3)
		{

		}
		else if (wybor1 == 4)
		{
			Klient k1;
			k1.wyswietl_oferte(pojazdy);
		}
		else
		{

		}
	}
	else if (wybor == 2)
	{
		Wlasciciel w;
		int wybor1;
		cout << "Wybierz opcje." << endl;
		cout << "1.Dodaj pojazd." << endl;
		cout << "2.Usun pojazd." << endl;
		cout << "3.Zmien cennik." << endl;
		cin >> wybor1;
		system("cls");
		if (wybor1 == 1)
		{
			w.dodaj_pojazd();
		}
		else if (wybor1 == 2)
		{
			string nr_rej_usun;
			cout << "Podaj numer rejestracyjny pojazdu, ktory chcesz usunac: ";
			cin >> nr_rej_usun;
			w.usun_pojazd(nr_rej_usun, pojazdy);
		}
		else if (wybor1 == 3)
		{
			string numer_rejestracyjny;
			cout << "Podaj numer rejestracyjny pojazdu, ktorego cene za godzine chcesz zmienic: ";
			cin >> numer_rejestracyjny;
			w.zmien_cene(numer_rejestracyjny, pojazdy);
		}
		else 
		{
			cout << "Podano nieprawidlowy numer wyboru!";
			Sleep(2000);
		}
	}
}