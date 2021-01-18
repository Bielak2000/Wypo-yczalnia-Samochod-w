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
	throw "Not yet implemented";
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
