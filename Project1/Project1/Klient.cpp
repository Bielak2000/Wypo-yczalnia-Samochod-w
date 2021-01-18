#include "Klient.h"
#include "Wypozyczenie.h"
#include "Pojazd.h"
#include "Data.h"
#include <iostream>

using namespace std;

Klient::Klient(string Im, string Naz, string Pes, string Addr, string Numer):
	Osoba(Im, Naz, Pes, Addr, Numer) {}

bool Klient::wypozycz(Pojazd* pojazdy)
{
	bool dostepny = false;
	string nr_rej;
	bool istnieje = false;
	int godzina1, dzien1, miesiac1, rok1, godzina2, dzien2, miesiac2, rok2, wybor, wybor1;
	int i = 0;
	cout << "Podaj imie: ";
	cin >> Imie;
	cout << "Podaj nazwisko: ";
	cin >> Nazwisko;
	cout << "Podaj pesel: ";
	cin >> Pesel;
	cout << "Podaj adres: ";
	cin >> Adres;
	cout << "Podaj telefon kontaktowy: ";
	cin >> Numer_telefonu;
	do {
		cout << "Podaj numer rejestracyjny: ";
		cin >> nr_rej;
		cout << "Podaj godzine rozpoczecia wypozyczenia: ";
		cin >> godzina1;
		cout << "Podaj dzien rozpoczecia wypozyczenia: ";
		cin >> dzien1;
		cout << "Podaj miesiac rozpoczecia wypozyczenia: ";
		cin >> miesiac1;
		cout << "Podaj rok rozpoczecia wypozyczenia: ";
		cin >> rok1;
		Data d1(dzien1, miesiac1, rok1, godzina1);
		cout << "Podaj godzine zakonczenia wypozyczenia: ";
		cin >> godzina2;
		cout << "Podaj dzien zakonczenia wypozyczenia: ";
		cin >> dzien2;
		cout << "Podaj miesiac zakonczenia wypozyczenia: ";
		cin >> miesiac2;
		cout << "Podaj rok zakonczenia wypozyczenia: ";
		cin >> rok2;
		for (i = 0; i < pojazdy[0].get_liczba_pojazdow(); i++)
		{
			if (pojazdy[i].get_numer_rejestracyjny() == nr_rej)
			{
				if (pojazdy[i].get_dostepnosc() == 1)
				{
					cout << "Pojazd jest dostepny!" << endl;
					dostepny = true;
				}
				istnieje = true;
				break;
			}
		}
		if (istnieje == false)
		{
			cout << "Nie znaleziono pojazdu o tym numerze rejestracyjnym!" << endl;
			cout << "Czy chcesz kontynuowac?" << endl;
			cout << "1.TAK" << endl;
			cout << "2.NIE" << endl;
			cin >> wybor1;
			if (wybor1 == 2)
				return 0;
		}
		else if(dostepny == false)
		{
			cout << "Czy chcesz zmienic pojazd czy zrezygnowac?" << endl;
			cout << "1.Zmienic pojazd" << endl;
			cout << "2.Reyzgnuje" << endl;
			cin >> wybor;
			if (wybor == 2)
				return 0;
		}
	} while (dostepny == false);

	int cena;
	pojazdy[i].zmien_dostepnosc();
	if (rok1 == rok2)
	{
		/*
		if (miesiac1 == miesiac2)
		{
			if (dzien1 == dzien2)
			{
				cena = pojazdy[i].get_cena_za_godzine() * (godzina2 - godzina1);
			}
			else
			{
				cena = pojazdy[i].get_cena_za_godzine() * ((24 - godzina1) + godzina2);
			}
		}*/
		if (miesiac1 == 1 || miesiac1 == 3 || miesiac1 == 5 || miesiac1 == 7 || miesiac1 == 8 || miesiac1 == 10 || miesiac1 == 12)
		{
			if (miesiac2 == 1 || miesiac2 == 3 || miesiac2 == 5 || miesiac2 == 7 || miesiac2 == 8 || miesiac2 == 10 || miesiac2 == 12)
				cena = pojazdy[i].get_cena_za_godzine()*((miesiac2 - 1) * 31 + dzien2) * 24 - ((miesiac1 - 1) * 31 + dzien1) * 24;
			else if(miesiac2 == 2)
				cena = pojazdy[i].get_cena_za_godzine() * ((miesiac2 - 1) * 28 + dzien2) * 24 - ((miesiac1 - 1) * 31 + dzien1) * 24;
			else
				cena = pojazdy[i].get_cena_za_godzine() * ((miesiac2 - 1) * 30 + dzien2) * 24 - ((miesiac1 - 1) * 31 + dzien1) * 24;
		}
		else if (miesiac1 == 2)
		{
			
		}
		///((miesiac2 - 1) * 30 + dzien2) * 24 - ((miesiac1 - 1) * 30 + dzien1) * 24;
	}
	Data d1(dzien1, miesiac1, rok1, godzina1);
	Data d2(dzien2, miesiac2, rok2, godzina2);
	Wypozyczenie w(d1, d2, nr_rej, Pesel, cena);

	cout << "Wypozyczono pojazd!" << endl;

	ofstream plik;	//edytowanie pliku z dopisywaniem
	plik.open("Wypozyczenia.txt", ios::out | ios::app);
	plik << "\n" << w.get_data_do().get_dzien() << " ";
	plik << w.get_data_do().get_miesiac() << " ";
	plik << w.get_data_do().get_rok() << " ";
	plik << w.get_data_do().get_godzina() << " ";

	plik << w.get_data_od().get_dzien() << " ";
	plik << w.get_data_od().get_miesiac() << " ";
	plik << w.get_data_od().get_rok() << " ";
	plik << w.get_data_od().get_godzina() << " ";

	plik << w.get_numer_rejestracyjny() << " ";
	plik << w.get_pesel() << " ";
	if(w.get_zakonczone()==1)
		plik << "Zakonczone" << " ";
	else
		plik << "Niezakonczone" << " ";

	plik << w.get_rachunek().get_sposob_platnosci() << " ";
	plik << w.get_rachunek().get_kwota() << " ";
	if (w.get_rachunek().get_potwierdzenie() == 1)
		plik << "Zaplacone" << " ";
	else
		plik << "Niezaplacone" << " ";
	plik.close();

	return 1;
}

void Klient::zarzadzaj_wypozyczeniem()
{
	// TODO - implement Klient::zarzadzaj_wypozyczeniem
	throw "Not yet implemented";
}

void Klient::wyswietl_oferte(Pojazd* tablica_pojazdow)
{
	for (int i = 0; i < tablica_pojazdow[0].get_liczba_pojazdow(); i++)
	{
		tablica_pojazdow[i].wyswietl_dane();
		cout << endl;
	}
}

void Klient::zwroc_pojazd(Wypozyczenie w)
{
	// TODO - implement Klient::zwroc_pojazd
	throw "Not yet implemented";
}