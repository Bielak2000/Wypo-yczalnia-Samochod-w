#include "Wypozyczenie.h"
#include "Platnosc.h"
#include <iostream>
using namespace std;

Wypozyczenie::Wypozyczenie(Data d1, Data d2, string nr_rej, string pes, int cena):Data_od(d1), Data_do(d2), Numer_rejestracyjny(nr_rej), pesel(pes)
{
	Wypozyczenie::Rachunek.set_kwota(cena);
}

bool Wypozyczenie::zmien_okres()
{
	// TODO - implement Wypozyczenie::zmien_okres
	throw "Not yet implemented";
}

void Wypozyczenie::zakoncz_wypozyczenie()
{
	// TODO - implement Wypozyczenie::zakoncz_wypozyczenie
	throw "Not yet implemented";
}

Data Wypozyczenie::zwroc_date_zakonczenia()
{
	// TODO - implement Wypozyczenie::zwroc_date_zakonczenia
	throw "Not yet implemented";
}

void Wypozyczenie::dodaj_auto(string nr)
{
	// TODO - implement Wypozyczenie::dodaj_auto
	throw "Not yet implemented";
}

void Wypozyczenie::pesel_klienta(string nr)
{
	pesel = nr;
}

void Wypozyczenie::podaj_termin()
{
	// TODO - implement Wypozyczenie::podaj_termin
	throw "Not yet implemented";
}

void Wypozyczenie::zaplac()
{
	// TODO - implement Wypozyczenie::zaplac
	throw "Not yet implemented";
}

void Wypozyczenie::skroc_okres(Data rozpoczecie, Data zakonczenie)
{
	// TODO - implement Wypozyczenie::skroc_okres
	throw "Not yet implemented";
}

void Wypozyczenie::wydluz_okres(Data rozpoczecie, Data zakonczenie)
{
	// TODO - implement Wypozyczenie::wydluz_okres
	throw "Not yet implemented";
}

void Wypozyczenie::zmien_termin_platnosci(Data d)
{
	// TODO - implement Wypozyczenie::zmien_termin_platnosci
	throw "Not yet implemented";
}

bool Wypozyczenie::get_zakonczone()
{
	return Wypozyczenie::Zakonczone;
}

Data Wypozyczenie::zwroc_date_rozpoczecia()
{
	// TODO - implement Wypozyczenie::zwroc_date_rozpoczecia
	throw "Not yet implemented";
}

string Wypozyczenie::get_numer_rejestracyjny()
{
	return Wypozyczenie::Numer_rejestracyjny;
}

string Wypozyczenie::get_pesel()
{
	return Wypozyczenie::pesel;
}

Data Wypozyczenie::get_data_od()
{
	return Wypozyczenie::Data_od;
}

Data Wypozyczenie::get_data_do()
{
	return Wypozyczenie::Data_do;
}

Data Wypozyczenie::get_termin_platnosci()
{
	return Wypozyczenie::termin_platnosci;
}

Platnosc Wypozyczenie::get_rachunek()
{
	return Wypozyczenie::Rachunek;
}


void Wypozyczenie::set_nr_rej(string nr)
{
	Wypozyczenie::Numer_rejestracyjny = nr;
}

void Wypozyczenie::set_pesel(string pes)
{
	Wypozyczenie::pesel = pes;
}

void Wypozyczenie::set_zakonczone(bool zakon)
{
	Wypozyczenie::Zakonczone = zakon;
}

Wypozyczenie* Wypozyczenie::wczytaj_z_pliku(int& w)
{
	//pobranie danych z pliku 
	string linia;//zmienna przehcowuja linie z pliku
	ifstream plik;//zmienna obslugujaca plik 
	plik.open("Wypozyczenia.txt");//otwieramy nasz plik z klientami
	//sprawdzamy czy udalo sie otowrzyc plik, jesli nie to wychodzimy z programu
	Wypozyczenie* Wypozyczenia = NULL;
	if (plik.good())
	{
		int liczba_wypozyczen = 0;
		while (getline(plik, linia))
		{
			liczba_wypozyczen++;
		}
		plik.clear();
		plik.seekg(0);
		w = liczba_wypozyczen;

		int calkowita;
		string znaki;

		Wypozyczenia = new Wypozyczenie[liczba_wypozyczen];//utowrzenie tablicy elementow ktorymi sa obiekty strukutry dane o rozmiarze 10000
		//do naszej tablicy przepisuje dane wartosci z pliku
		for (int i = 0; i < liczba_wypozyczen; i++)
		{
			getline(plik, linia);
			istringstream iss(linia);
			iss >> calkowita;
			Wypozyczenia[i].Data_od.set_dzien(calkowita);
			iss >> calkowita;
			Wypozyczenia[i].Data_od.set_miesiac(calkowita);
			iss >> calkowita;
			Wypozyczenia[i].Data_od.set_rok(calkowita);
			iss >> calkowita;
			Wypozyczenia[i].Data_od.set_godzina(calkowita);

			iss >> calkowita;
			Wypozyczenia[i].Data_do.set_dzien(calkowita);
			iss >> calkowita;
			Wypozyczenia[i].Data_do.set_miesiac(calkowita);
			iss >> calkowita;
			Wypozyczenia[i].Data_do.set_rok(calkowita);
			iss >> calkowita;
			Wypozyczenia[i].Data_do.set_godzina(calkowita);

			iss >> Wypozyczenia[i].Numer_rejestracyjny;
			iss >> Wypozyczenia[i].pesel;
			iss >> znaki;
			if (znaki == "Zakonczone")
				Wypozyczenia[i].Zakonczone = 1;
			else
				Wypozyczenia[i].Zakonczone = 0;
			iss >> znaki;
			Wypozyczenia[i].Rachunek.set_sposob_platnosci(znaki);
			iss >> calkowita;
			Wypozyczenia[i].Rachunek.set_kwota(calkowita);
			if (znaki == "Zaplacone")
				Wypozyczenia[i].Rachunek.set_potwierdzenie(true);
			else
				Wypozyczenia[i].Rachunek.set_potwierdzenie(false);
		}
	}
	else
	{
		return nullptr;
	}
	plik.close();
	return Wypozyczenia;
}