#include <iostream>
#include "Data.h"

using namespace std;

Data::Data(int d, int m, int r, int g)
{
	dzien = d;
	miesiac = m;
	rok = r;
	godzina = g;
}

void Data::zmien_date()
{
	cout << "Podaj nowa date w formacie liczbowym: " << endl;
	cout << "dzien: ";
	cin >> dzien;
	cout << "miesiac: ";
	cin >> miesiac;
	cout << "rok: ";
	cin >> rok;
	cout << "godzina: ";
	cin >> godzina;

	cout << "Data zostala zmieniona!" << endl;
}

bool Data::czy_koliduje(Data zajetyOd, Data zajetyDo, Data terminOd, Data terminDo)	//zajety - istniejace wypozyczenie, termin - potencjalne wypozyczenie
{
	//nazywamy zmienne 3 literami wedlug nastepujacego klucza:
	//z lub t - sprawdzamy zajety lub termin
	//1 lub 2 - od lub do
	//m lub d - dzien lub miesiac
	int z1m = zajetyOd.miesiac;
	int z2m = zajetyDo.miesiac;
	int t1m = terminOd.miesiac;
	int t2m = terminDo.miesiac;

	int z1d = zajetyOd.dzien;
	int z2d = zajetyDo.dzien;
	int t1d = terminOd.dzien;
	int t2d = terminDo.dzien;

	int zm = z2m - z1m;	//dlugosc istniejacego wypozyczenia(zajety) w miesiacach
	int tm = t2m - t1m;	//dlugosc potencjalnego wypozyczenia(termin) w miesiacach

	int zd = z2d - z1d;	//dlugosc istniejacego wypozyczenia(zajety) w dniach
	int td = t2d - t1d;	//dlugosc potencjalnego wypozyczenia(termin) w dniach

	//algorytm sprawdzajacy kolidowanie dat
	if (zm == 0 && tm == 0)	//jesli liczba miesiecy wypozyczenia trwa mniej niz miesiac
	{
		if (z1m == t2m)
		{
			if (z1d <= t1d && t1d <= z2d || z1d <= t2d && t2d <= z2d)	//jesli poczatek lub koniec nalezy do przedzialu gdzie jest rezerwacja (z1d,z2d)
				return true;
			else return false;	//w przeciwnym wypadku nie ma kolizji dat
		}
		else return false;	//jesli to nie ten sam miesiac to brak kolizji
	}
	else if (tm == 0) //jesli potencjalna rezerwacja jest niedluzsza niz miesiac
	{
		if (t1m == z1m)		//jesli potencjalna rezerwacja jest w tym samym miesiacu co koniec istniejacej
		{
			if (t2d < z1d) return false;	//jesli potencjalna rezerwacja konczy sie wczesniej niz zaczyna ta potwierdzona
			return true;	//kolizja w przeciwnym wypadku
		}
		else if (t1m == z2m)
		{
			if (z2d < t1d)	return false;	//jesli potencjalna rezerwacja zaczyna sie po zakonczeniu istniejacej
			return true;	//kolizja w przeciwnym wypadku
		}
		else if (z1m < t1m && t1m < z2m)
			return true; //zawiera sie w przedziale, wiec koliduje
		else return false; //brak kolizji
	}
	else if (zm == 0)	//jesli okres istniejacego wypozyczenia jest krotszy niz miesiac
	{
		if (t1m == z1m)
		{
			if (z2d < t1d) return false;	//brak koolizji
			return true;	//kolizja w przeciwnym wypadku
		}
		else if (t2m == z1m)
		{
			if (t2d < z1d)	return false;
			return true;
		}
		else if (t1m < z1m && z1m < t2m)
			return true; //zawiera sie w przedziale, wiec koliduje
		else return false; //brak kolizji
	}
	else {		//w innym wypadku, czyli kiedy wypozyczenie istniejace i potencjalne maja dluzsze okresy niz miesiac
		if (t1m == z2m)
		{
			if (z2d < t1d)	return false;
			return true;	//kolizja
		}
		else if (t2m == z1m)
		{
			if (t2d < z1d)	return false;
			return true;	//kolizja
		}
		else if (t1m <= z1m && z1m <= t2m || t1m <= z2m && z2m <= t2m)
			return true; //koliduje
		else return false; //nie koliduje
	}
}

int Data::get_dzien()
{
	return Data::dzien;
}

int Data::get_miesiac()
{
	return Data::miesiac;
}

int Data::get_rok()
{
	return Data::rok;
}
int Data::get_godzina()
{
	return Data::godzina;
}

void Data::set_dzien(int d)
{
	Data::dzien = d;
}

void Data::set_miesiac(int m)
{
	Data::miesiac = m;
}

void Data::set_rok(int r)
{
	Data::rok = r;
}

void Data::set_godzina(int g)
{
	Data::godzina = g;
}