#include <iostream>
#include <windows.h>
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



int main()
{
	int n;
	Pojazd* pojazdy = Pojazd::wczytaj_z_pliku(n);
  system("cls");
	int wybor;
	cout << "Witaj w naszej wypozyczalni pojazdow!" << endl;
	Sleep(3000);
	system("cls");

	cout << "Kim jestes?" << endl;
	cout << "1.Klientem." << endl;
	cout << "2.Pracownikiem." << endl;
	cout << "3.Wlascicielem." << endl;
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
	else if (wybor == 3)
	{
		int wybor1;
		cout << "Wybierz opcje." << endl;
		cout << "1.Dodaj pojazd." << endl;
		cout << "2.Usun pojazd." << endl;
		cout << "3.Zmien cennik." << endl;
		cin >> wybor1;
		system("cls");
		if (wybor1 == 1)
		{

		}
		else if (wybor1 == 2)
		{

		}
		else
		{

		}
	}
}