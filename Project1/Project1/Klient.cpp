#include "Klient.h"
#include "Wypozyczenie.h"
#include "Pojazd.h"
#include "Data.h"
#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

int Klient::liczba_klientow = 0;//poczatkowa inicjalizacja statycznego pola wskazujacego na liczbe klientow

//konstruktor, zwieksza statyczne pole liczba_klientow o jeden
Klient::Klient(string imiee, string nazwiskoo, string pesell, string address, string numerr):
	Osoba(imiee, nazwiskoo, pesell, address, numerr) {
	liczba_klientow++;
}

//funkcja sluzaca do wypozyczenia pojazdu, klient podaje swoje dane i zapisuje je do pol, wyswietlana jest oferta wyzpoyczalnii, podawany jest numer rejestracyjny
//i na jego bazie sprawdzamy czy jest on dostepny i czy on istnieje:
//1.W przypadku gdzy jest niedostepny lub nieistnieje uzytkownik moze zrezygnowac lub zakonczyc.
//2.W drugim przypadku zapisywana jest aktualna data z wyprzedzeniem o godzine do daty rozpoczecia wypozyczenia oraz klient podaje date zakonczenia, ktora jest sprawdzana
//czy zostala podana poprawna(jest pozniejsza niz data rozpoczecia), jesli nie to trzeba podac ja od nowa, gdy dobra to zmieniania jest dostepnosc pojazdu i aktualizuje
//sie plik z pojazdami; nastepnie obliczana jest kwota za wypozyczenie i tworzy sie obiekt klasy wypozyczenie po czym zapisuje sie to wypozyczenie do pliku.
bool Klient::wypozycz(Pojazd* pojazdy)
{
	bool dostepny = false;
	string nr_rej;
	bool istnieje = false;
	int godzina1, dzien1, miesiac1, rok1, godzina2, dzien2, miesiac2, rok2, wybor, wybor1;
	int i = 0;//zmienna sterujaca petla
	cout << "Podaj imie: ";
	cin >> imie;
	cout << "Podaj nazwisko: ";
	cin >> nazwisko;
	cout << "Podaj pesel: ";
	cin >> pesel;
	cout << "Podaj adres: ";
	getline(cin, adres);
	getline(cin, adres);
	cout << "Podaj telefon kontaktowy: ";
	cin >> numer_telefonu;
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

	Data data1(dzien1, miesiac1, rok1, godzina1);
	Data data2(dzien2, miesiac2, rok2, godzina2);
	Wypozyczenie wypozyczenie(data1, data2, nr_rej, pesel, cena);

	cout << "Wypozyczono pojazd!" << endl;
	Sleep(2000);
	system("cls");

	//edytowanie pliku z dopisywaniem
	ofstream plik;
	plik.open("Wypozyczenia.txt", ios::out | ios::app);
	if (Wypozyczenie::get_liczba_wypozyczen() != 1)
		plik << "\n";
	plik << wypozyczenie.get_data_od().get_dzien() << " ";
	plik << wypozyczenie.get_data_od().get_miesiac() << " ";
	plik << wypozyczenie.get_data_od().get_rok() << " ";
	plik << wypozyczenie.get_data_od().get_godzina() << " ";

	plik << wypozyczenie.get_data_do().get_dzien() << " ";
	plik << wypozyczenie.get_data_do().get_miesiac() << " ";
	plik << wypozyczenie.get_data_do().get_rok() << " ";
	plik << wypozyczenie.get_data_do().get_godzina() << " ";

	plik << wypozyczenie.get_numer_rejestracyjny() << " ";
	plik << wypozyczenie.get_pesel() << " ";
	if(wypozyczenie.get_zakonczone()==1)
		plik << "Zakonczone" << " ";
	else
		plik << "Niezakonczone" << " ";

	plik << wypozyczenie.get_rachunek().get_sposob_platnosci() << " ";
	plik << wypozyczenie.get_rachunek().get_kwota() << " ";
	if (wypozyczenie.get_rachunek().get_potwierdzenie() == 1)
		plik << "Zaplacone" << " ";
	else
		plik << "Niezaplacone" << " ";
	plik << wypozyczenie.get_termin_platnosci().get_dzien() << " ";
	plik << wypozyczenie.get_termin_platnosci().get_miesiac() << " ";
	plik << wypozyczenie.get_termin_platnosci().get_rok() << " ";
	plik << wypozyczenie.get_termin_platnosci().get_godzina() << " ";
	plik.close();

	return true;
}

//metoda do wyswietlania oferty czyli wszytskich danych o pojazdach, korzysta z metody wyswietl_dane w klasie Pojazd
void Klient::wyswietl_oferte(Pojazd* tablica_pojazdow)
{
	for (int i = 0; i < tablica_pojazdow[0].get_liczba_pojazdow(); i++)
	{
		tablica_pojazdow[i].wyswietl_dane();
		cout << endl;
	}
}

//metoda sluzaca do zwrotu wypozyczonego pojazdu przez klienta, podaje on numer rejestracyjny i swoj pesel metoda sprawdza czy ten klient ma takie wypozyczenie(jesli nie to 
//wychodzi z funkcji, jesli tak spawdza sie uszkodzenia i w razie czego podaje wartosc uszkodzen i dopsiuje do kwoty za wypozyczenie, podaje sie tez aktualny przebieg i dopisuje 
//do pojazdu, zmienia sie jego dostpenosc na dostepny i aktualizuje plik z pojazdami, po tym zmienia sie pole zakonczone na 1 w wypozyczeniu i aktualizuje
//plik z wypozyczeniami.
void Klient::zwroc_pojazd(Wypozyczenie * tablica_wypozyczen, Pojazd * tablica_pojazdow)
{
	string pesell, nr_rejj;
	int sprawdzacz = 0;
	cout << "Podaj swoj pesel: ";
	cin >> pesell;
	cout << "Podaj numer rejestracyjny: ";
	cin >> nr_rejj;
	for (int i = 0; i < tablica_wypozyczen[0].get_liczba_wypozyczen(); i++)
	{
		if (tablica_wypozyczen[i].get_pesel() == pesell && tablica_wypozyczen[i].get_numer_rejestracyjny() == nr_rejj && tablica_wypozyczen[i].get_rachunek().get_potwierdzenie() == 0)
		{
			sprawdzacz = 1;
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
					uszkodzenia += tablica_wypozyczen[i].get_rachunek().get_kwota();
					tablica_wypozyczen[i].get_rachunek1()->set_kwota( uszkodzenia );
				}
			} while (wybor != 1 && wybor != 2);

			cout << "Podaj aktualny przebieg: ";
			string przebieg;
			cin >> przebieg;
			
			for (int j = 0; j < tablica_pojazdow[0].get_liczba_pojazdow(); j++)
			{
				if (nr_rejj == tablica_pojazdow[j].get_numer_rejestracyjny())
				{
					tablica_pojazdow[j].zmien_przebieg(przebieg);
					tablica_pojazdow[j].zmien_dostepnosc();
					tablica_pojazdow[j].aktualizuj_plik(tablica_pojazdow);
					break;
				}
			}

			tablica_wypozyczen[i].set_zakonczone(true);

			cout << "Pojazd zostal zwrocony!" << endl;
			Sleep(2000);
			system("cls");

			tablica_wypozyczen[i].aktualizuj_plik(tablica_wypozyczen);
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
//korzysta z funkcji zaplac w wypozyczeniu i na koniec aktualizuje plik, a jesli nie znaleziono takiego wypozyczenia to wyswietla komunikat i wychodzi z funkcji;
void Klient::dokonaj_platnosci(Wypozyczenie* tablica_wypozyczen)
{
	string pessel, nr_reej;
	cout << "Podaj pesel: ";
	cin >> pessel;
	cout << "Podaj numer rejestracyjny pojazdu za wypozyczenie ktorego chcesz zaplacic: ";
	cin >> nr_reej;
	bool sprawdzacz = 0;

	for (int i = 0; i < tablica_wypozyczen[0].get_liczba_wypozyczen(); i++)
	{
		if (tablica_wypozyczen[i].get_numer_rejestracyjny() == nr_reej && tablica_wypozyczen[i].get_pesel() == pessel)
		{
			tablica_wypozyczen[i].zaplac(tablica_wypozyczen);
			tablica_wypozyczen[i].aktualizuj_plik(tablica_wypozyczen);
			sprawdzacz = 1;
			break;
		}
	}
	if (!sprawdzacz)
		cout << "Nie znaleziono takiego wypozyczenia!" << endl;
}

//zwracany argument metody to wskaznik do tablicy z klientami, a przekazywany argument to rozmiar tej tablicy
Klient* Klient::wczytaj_z_pliku(int& rozmiar)
{
	//pobranie danych z pliku 
	string linia;//zmienna przechowujaca linie z pliku
	ifstream plik;//zmienna obslugujaca plik 
	plik.open("Klienci.txt");//otwieramy nasz plik z klientami
	Klient* klienci = NULL;
	//sprawdzamy czy udalo sie otworzyc plik, jesli nie to wychodzimy z programu
	if (plik.good())
	{
		int liczba_klientow = 0;
		while (getline(plik, linia))	// w tej petli sprawdzamy ile jest linijek zeby wiedziec jaki bedzie rozmiar tablicy 
		{
			liczba_klientow++;
		}
		plik.clear();
		plik.seekg(0);
		liczba_klientow /= 2;
		rozmiar = liczba_klientow;

		klienci = new Klient[liczba_klientow];//utworzenie tablicy elementow na podstawie obliczonej liczby klientow
		//do naszej tablicy przepisujemy dane wartosci z pliku
		for (int i = 0; i < liczba_klientow; i++)
		{
			getline(plik, linia);		//w pierwszej z linii sa podstawowe dane
			istringstream iss(linia);
			iss >> klienci[i].imie;
			iss >> klienci[i].nazwisko;
			iss >> klienci[i].pesel;
			iss >> klienci[i].numer_telefonu;
			getline(plik, linia);
			klienci[i].adres = linia;
		}
	}
	else
	{
		return nullptr; //w przypadku gdy nie udaje sie otworzyc pliku zwracamy wskaznik pusty
	}
	plik.close();
	return klienci;
}


void Klient::aktualizuj_plik(Klient* klienci) //przyjmowany argument to tablica pojazdow
{
	int jest = -1;	//indeks dla klienta dla ktorego wywolana jest metoda

	for (int i = 0; i < klienci[i].get_liczba_klientow(); i++)
		if (klienci[i].get_pesel() == this->pesel)
		{
			jest = i;	//jesli klient jest juz w pliku to zapisujemy jego indeks w "jest"
			break;
		}

	//jesli zmienna "jest" pozostala bez zmian (-1) tzn ze nie ma klienta w pliku
	if (jest == -1) //klienta nie ma w pliku
	{
		//dane klienta zajmuja 2 linijki - w 1 jest imie, nazwisko, pesel, numer telefonu, a w 2 adres
		ofstream plik;	//edytowanie pliku z dopisywaniem
		plik.open("Klienci.txt", ios::out | ios::app);
		if (klienci[0].get_liczba_klientow() != 0)
			plik << "\n";
		plik << this->imie << " ";
		plik << this->nazwisko << " ";
		plik << this->pesel << " ";
		plik << this->numer_telefonu << "\n";
		plik << this->adres;
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
			plik << klienci[i].imie << " ";
			plik << klienci[i].nazwisko << " ";
			plik << klienci[i].pesel << " ";
			plik << klienci[i].numer_telefonu << "\n";
			plik << klienci[i].adres << " ";
		}

		//na koncu dopisujemy nowego klienta z aktualnymi danymi
		if (klienci[0].get_liczba_klientow() != 1)
			plik << "\n";
		plik << this->imie << " ";
		plik << this->nazwisko << " ";
		plik << this->pesel << " ";
		plik << this->numer_telefonu << "\n";
		plik << this->adres << " ";

		plik.close();
	}
}

//getter do liczby klientow
int Klient::get_liczba_klientow()
{
	return Klient::liczba_klientow;
}

//metoda do zmieniejszenia liczby klientow o jeden
void Klient::zmniejsz_liczba_klientow()
{
	liczba_klientow--;
}