#include "Klient.h"
#include "Wypozyczenie.h"
#include "Pojazd.h"
#include "Data.h"
#include <iostream>

using namespace std;

int Klient::liczba_klientow = 0;

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
	getline(cin, Adres);
	getline(cin, Adres);
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

	int cena = 0;
	pojazdy[i].zmien_dostepnosc();

	int rok, miesiac, dzien;
	miesiac = miesiac2 - miesiac1;
	miesiac += 12*(rok2 - rok1);
	dzien = dzien2 - dzien1;
	for (int m = 0; m < miesiac; m++)
	{
		int ktory = (miesiac1 + m) % 12;
		if (ktory == 1 || ktory == 3 || ktory == 5 || ktory == 7 || ktory == 8 || ktory == 10 || ktory == 12)
		{
			dzien += 31;
		}
		else if (ktory == 2)
		{
			dzien += 28;
		}
		else
		{
			dzien += 30;
		}
	}
	cena = dzien * 24 * pojazdy[i].get_cena_za_godzine();


	
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

Klient* Klient::wczytaj_z_pliku(int& n)
{
	//pobranie danych z pliku 
	string linia;//zmienna przehcowuja linie z pliku
	ifstream plik;//zmienna obslugujaca plik 
	plik.open("Klienci.txt");//otwieramy nasz plik z klientami
	//sprawdzamy czy udalo sie otowrzyc plik, jesli nie to wychodzimy z programu
	Klient* klienci = NULL;
	if (plik.good())
	{
		cout << "Udalo sie otworzyc plik!" << endl;
		int liczba_klientow = 0;
		while (getline(plik, linia))
		{
			liczba_klientow++;
		}
		plik.clear();
		plik.seekg(0);
		liczba_klientow /= 2;
		n = liczba_klientow;

		klienci = new Klient[liczba_klientow];//utowrzenie tablicy elementow ktorymi sa obiekty strukutry dane o rozmiarze 10000
		//do naszej tablicy przepisuje dane wartosci z pliku
		for (int i = 0; i < liczba_klientow; i++)
		{
			getline(plik, linia);
			istringstream iss(linia);
			iss >> klienci[i].Imie;
			iss >> klienci[i].Nazwisko;
			iss >> klienci[i].Pesel;
			iss >> klienci[i].Numer_telefonu;
			getline(plik, linia);
			klienci[i].Adres = linia;
		}
	}
	plik.close();
	return klienci;
}


void Klient::aktualizuj_plik(Klient* klienci)
{
	int jest = -1;	//indeks dla klienta dla ktorego wywolana jest metoda

	for (int i = 0; i < klienci[i].get_liczba_klientow(); i++)
		if (klienci[i].get_pesel() == this->Pesel)
		{
			jest = i;	//jesli klient jest juz w pliku to zapisujemy jego indeks w "jest"
			break;
		}

	//jesli zmienna "jest" pozostala bez zmian -1 tzn ze nie ma klienta w pliku
	if (jest == -1) //klienta nie ma w pliku
	{
		//dane klienta zajmuja 2 linijki - w 1 jest imie, nazwisko, pesel, numer telefonu, a w 2 adres
		ofstream plik;	//edytowanie pliku z dopisywaniem
		plik.open("Klienci.txt", ios::out | ios::app);
		plik << "\n" << this->Imie << " ";
		plik << this->Nazwisko << " ";
		plik << this->Pesel << " ";
		plik << this->Numer_telefonu << "\n";
		plik << this->Adres;
		plik.close();
	}
	else
	{
		ofstream plik;	//edytowanie pliku z nadpisaniem
		plik.open("Klienci.txt");
		for (int i = 0; i < klienci[i].get_liczba_klientow(); i++)
		{
			if (i == jest) continue;	//pomijane okrazenie w petli zeby klienta nie zapisac 2x
			if (i != 0) plik << "\n";
			plik << klienci[i].Imie << " ";
			plik << klienci[i].Nazwisko << " ";
			plik << klienci[i].Pesel << " ";
			plik << klienci[i].Numer_telefonu << "\n";
			plik << klienci[i].Adres << " ";
		}

		//na koncu dopisujemy nowego klienta z aktualnymi danymi
		plik << "\n" << this->Imie << " ";
		plik << this->Nazwisko << " ";
		plik << this->Pesel << " ";
		plik << this->Numer_telefonu << "\n";
		plik << this->Adres << " ";

		plik.close();
	}
}

int Klient::get_liczba_klientow()
{
	return Klient::liczba_klientow;
}