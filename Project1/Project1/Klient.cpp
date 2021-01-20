#include "Klient.h"
#include "Wypozyczenie.h"
#include "Pojazd.h"
#include "Data.h"
#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

int Klient::liczba_klientow = 0;

Klient::Klient(string Im, string Naz, string Pes, string Addr, string Numer):
	Osoba(Im, Naz, Pes, Addr, Numer) {
	liczba_klientow++;
}

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
		cout << endl << "-----------------------------------------------------" << endl;
		this->wyswietl_oferte(pojazdy);
		cout << "-----------------------------------------------------" << endl;
		cout << "Podaj numer rejestracyjny: ";
		cin >> nr_rej;

		//sprawdzenie dostepnosci pojazdu
		for (i = 0; i < pojazdy[0].get_liczba_pojazdow(); i++)
		{
			if (pojazdy[i].get_numer_rejestracyjny() == nr_rej)
			{
				if (pojazdy[i].get_dostepnosc() == 1)
				{
					
					cout << "Pojazd jest dostepny!" << endl;
					Sleep(2000);
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
			system("cls");
			if (wybor1 == 1)
				continue;
			else
				return false;
		}
		else if (dostepny == false)
		{
			cout << "Pojazd jest niedostepny!" << endl;
			cout << "Czy chcesz zmienic pojazd czy zrezygnowac?" << endl;
			cout << "1.Zmienic pojazd" << endl;
			cout << "2.Reyzgnuje" << endl;
			cin >> wybor;
			system("cls");
			if (wybor == 1)
				continue;
			else
				return false;
		}

		//pobieramy aktualny czas do zmiennej time_t
		time_t czas;
		time(&czas);
		//konwetujemy zmienna time_t na wskaznik do zmiennej tm* za pomoca funkcji localtime(&czas), a elementy z kotrych nie bedziemy korzystac ustawiamy na null
		struct tm aktualny_czas;
		localtime_s(&aktualny_czas, &czas);
		dzien1 = aktualny_czas.tm_mday;
		miesiac1 = aktualny_czas.tm_mon + 1;
		rok1 = aktualny_czas.tm_year + 1900;
		godzina1 = aktualny_czas.tm_hour + 1;

		Data d1(dzien1, miesiac1, rok1, godzina1);

		//sprawdzenie poprawnosci wprowadzonej daty
		int data;
		do {
			system("cls");
			data = 0;
			cout << "Podaj godzine zakonczenia wypozyczenia: ";
			cin >> godzina2;
			if (godzina2 > 24 || godzina2 < 1)
			{
				cout << "Podana zostala zla data! Sprobuj ponownie" << endl;
				Sleep(3000);
				data = 1;
				continue;
			}
			cout << "Podaj miesiac zakonczenia wypozyczenia: ";
			cin >> miesiac2;
			if (miesiac2 > 12 || miesiac2 < 1)
			{
				cout << "Podana zostala zla data! Sprobuj ponownie" << endl;
				Sleep(3000);
				data = 1;
				continue;
			}
			cout << "Podaj dzien zakonczenia wypozyczenia: ";
			cin >> dzien2;
			if(miesiac2==1 || miesiac2 == 3 || miesiac2 == 5 || miesiac2 == 7 || miesiac2 == 8 || miesiac2 == 10 || miesiac2 == 12)
				if (dzien2 > 31 || dzien2 < 1)
				{
					cout << "Podana zostala zla data! Sprobuj ponownie" << endl;
					Sleep(3000);
					data = 1;
					continue;
				}
			if (miesiac2 == 2)
			{
				if (dzien2 > 28 || dzien2 < 1)
				{
					cout << "Podana zostala zla data! Sprobuj ponownie" << endl;
					Sleep(3000);
					data = 1;
					continue;
				}
			}
			else
				if (dzien2 > 30 || dzien2 < 1)
				{
					cout << "Podana zostala zla data! Sprobuj ponownie" << endl;
					Sleep(3000);
					data = 1;
					continue;
				};
			
			cout << "Podaj rok zakonczenia wypozyczenia: ";
			cin >> rok2;
			if (rok2 == rok1)
			{
				if (miesiac2 == miesiac1)
				{
					if (dzien2 == dzien1)
					{
						if (godzina2 <= godzina1)
						{
							cout << "Podana zla date! Sprobuj jeszcze raz!" << endl;
							Sleep(3000);
							data = 1;
						}
					}
					else if(dzien2 < dzien1)
					{
						cout << "Podana zla date! Sprobuj jeszcze raz!" << endl;
						Sleep(3000);
						data = 1;
					}
				}
				else if (miesiac2 < miesiac1)
				{
					cout << "Podana zla date! Sprobuj jeszcze raz!" << endl;
					Sleep(3000);
					data = 1;
				}
			}
			else if (rok2 < rok1)
			{
				cout << "Podana zla date! Sprobuj jeszcze raz!" << endl;
				Sleep(3000);
				data = 1;
			}
		} while (data == 1);

	} while (dostepny == false);

	int cena = 0;
	pojazdy[i].zmien_dostepnosc();
	pojazdy[i].aktualizuj_plik(pojazdy);

	int miesiac, dzien;
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
	int godzina = godzina2 - godzina1;
	godzina += dzien * 24;
	cena = godzina * pojazdy[i].get_cena_za_godzine();


	Data d1(dzien1, miesiac1, rok1, godzina1);
	Data d2(dzien2, miesiac2, rok2, godzina2);
	Wypozyczenie w(d1, d2, nr_rej, Pesel, cena);

	cout << "Wypozyczono pojazd!" << endl;
	Sleep(2000);
	system("cls");

	ofstream plik;	//edytowanie pliku z dopisywaniem
	plik.open("Wypozyczenia.txt", ios::out | ios::app);
	if (Wypozyczenie::get_liczba_wypozyczen() != 1)
		plik << "\n";
	plik << w.get_data_od().get_dzien() << " ";
	plik << w.get_data_od().get_miesiac() << " ";
	plik << w.get_data_od().get_rok() << " ";
	plik << w.get_data_od().get_godzina() << " ";

	plik << w.get_data_do().get_dzien() << " ";
	plik << w.get_data_do().get_miesiac() << " ";
	plik << w.get_data_do().get_rok() << " ";
	plik << w.get_data_do().get_godzina() << " ";

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
	plik << w.get_termin_platnosci().get_dzien() << " ";
	plik << w.get_termin_platnosci().get_miesiac() << " ";
	plik << w.get_termin_platnosci().get_rok() << " ";
	plik << w.get_termin_platnosci().get_godzina() << " ";
	plik.close();

	return true;
}


void Klient::wyswietl_oferte(Pojazd* tablica_pojazdow)
{
	for (int i = 0; i < tablica_pojazdow[0].get_liczba_pojazdow(); i++)
	{
		tablica_pojazdow[i].wyswietl_dane();
		cout << endl;
	}
}

void Klient::zwroc_pojazd(Wypozyczenie * tablica_w, Pojazd * tablica_pojazdow)
{
	string p, nr;
	int sprawdzacz = 0;
	cout << "Podaj swoj pesel: ";
	cin >> p;
	cout << "Podaj numer rejestracyjny: ";
	cin >> nr;
	for (int i = 0; i < tablica_w[0].get_liczba_wypozyczen(); i++)
	{
		if (tablica_w[i].get_pesel() == p && tablica_w[i].get_numer_rejestracyjny() == nr && tablica_w[i].get_rachunek().get_potwierdzenie() == 0)
		{
			sprawdzacz = 1;
			tablica_w[i].set_zakonczone(true);
			int wybor;
			do
			{
				cout << "Czy pojazd jest uszkodzony?" << endl;
				cout << "[1] TAK" << endl;
				cout << "[2] NIE" << endl;
				
				cin >> wybor;

				if (wybor == 1)
				{
					cout << "Podaj wartosc uszkodzen pojazdu: ";
					int uszkodzenia;
					cin >> uszkodzenia;
					uszkodzenia += tablica_w[i].get_rachunek().get_kwota();
					tablica_w[i].get_rachunek1()->set_kwota( uszkodzenia );
				}
			} while (wybor != 1 && wybor != 2);

			cout << "Podaj aktualny przebieg: ";
			string przebieg;
			cin >> przebieg;
			
			for (int j = 0; j < tablica_pojazdow[0].get_liczba_pojazdow(); j++)
			{
				if (nr == tablica_pojazdow[j].get_numer_rejestracyjny())
				{
					tablica_pojazdow[j].set_przebieg(przebieg);
					tablica_pojazdow[j].zmien_dostepnosc();
					tablica_pojazdow[j].aktualizuj_plik(tablica_pojazdow);
					break;
				}
			}

			tablica_w[i].set_zakonczone(true);

			cout << "Pojazd zostal zwrocony!" << endl;
			Sleep(2000);
			system("cls");

			tablica_w[i].aktualizuj_plik(tablica_w);
			break;
		}

	}
	if (0==sprawdzacz)
	{
		cout << "Bledne dane!" << endl;
		Sleep(2000);
	}
}

//funkcja wyszukuje dane wypozyczenie za ktore chce zaplacic uzytkownik po przez wyszukanie jego po peselu i nr rejestracyjnym pojazdu;
//korzysta z funkcji zaplac w wypozyczeniu i na koniec aktualizuje plik
void Klient::dokonaj_platnosci(Wypozyczenie* tablica_w)
{
	string pes, nr;
	cout << "Podaj pesel: ";
	cin >> pes;
	cout << "Podaj numer rejestracyjny pojazdu za wypozyczenie ktorego chcesz zaplacic: ";
	cin >> nr;
	bool sprawdzacz = 0;

	for (int i = 0; i < tablica_w[0].get_liczba_wypozyczen(); i++)
	{
		if (tablica_w[i].get_numer_rejestracyjny() == nr && tablica_w[i].get_pesel() == pes)
		{
			tablica_w[i].zaplac(tablica_w);
			tablica_w[i].aktualizuj_plik(tablica_w);
			sprawdzacz = 1;
			break;
		}
	}
	if (!sprawdzacz)
		cout << "Nie znaleziono takiego wypozyczenia!" << endl;
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
	else
	{
		return nullptr;
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
		if (klienci[0].get_liczba_klientow() != 0)
			plik << "\n";
		plik << this->Imie << " ";
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
			if (!(i == 1 && jest == 0))
			if (i != 0) plik << "\n";
			plik << klienci[i].Imie << " ";
			plik << klienci[i].Nazwisko << " ";
			plik << klienci[i].Pesel << " ";
			plik << klienci[i].Numer_telefonu << "\n";
			plik << klienci[i].Adres << " ";
		}

		//na koncu dopisujemy nowego klienta z aktualnymi danymi
		if (klienci[0].get_liczba_klientow() != 1)
			plik << "\n";
		plik << this->Imie << " ";
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

void Klient::zmniejsz_liczba_klientow()
{
	liczba_klientow--;
}