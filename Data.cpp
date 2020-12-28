#include "Data.h"

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
