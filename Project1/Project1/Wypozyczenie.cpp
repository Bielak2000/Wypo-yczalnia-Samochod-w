#include "Wypozyczenie.h"
#include "Platnosc.h"
#include <iostream>
using namespace std;

int Wypozyczenie::liczba_wypozyczen = 0;

Wypozyczenie::Wypozyczenie(Data d1, Data d2, string nr_rej, string pes, int cena):data_od(d1), data_do(d2), numer_rejestracyjny(nr_rej), pesel(pes)
{
	Wypozyczenie::rachunek.set_kwota(cena);
	liczba_wypozyczen++;
}

//ustalanie sposobu platnosci i zaplacenie lub ewentualne odroczenie
void Wypozyczenie::zaplac(Wypozyczenie * tab_wyp)
{
	int wybor;
	do
	{
		do
		{
			cout << "Podaj sposob platnosci" << endl;
			cout << "[1] Gotowka" << endl;
			cout << "[2] Karta" << endl;
			cout << "[3] Odroczenie" << endl;
			cin >> wybor;
		} while (wybor != 1 && wybor != 2 && wybor != 3);	//obsluga bledow
		if (wybor == 1)	//wybor gotowki
		{
			this->get_rachunek1()->set_sposob_platnosci("gotowka");	//ustawiamy sposob platnosci i poszemy komunikaty
			cout << "Kwota do zaplaty " << this->get_rachunek().get_kwota() << "zl." << endl;
			cout << "Prosze o wplate!" << endl;
			Sleep(1000);
			cout << "Dziekujemy za zaplate!" << endl;
			Sleep(2000);
			system("cls");
			this->get_rachunek1()->set_potwierdzenie(true);
			return;
		}
		else if (wybor == 2)	//wybor karty
		{
			this->get_rachunek1()->set_sposob_platnosci("karta");
			cout << "Kwota do zaplaty " << this->get_rachunek().get_kwota() << "zl." << endl;
			cout << "Prosze o wplate!" << endl;
			Sleep(1000);
			cout << "Dziekujemy za zaplate!" << endl;
			Sleep(2000);
			system("cls");
			this->get_rachunek1()->set_potwierdzenie(true);
			return;

		}
		else if (wybor == 3)	//wybor odroczenia
		{
			int ilosc = 0;
			//sprawdzenie ile osoba chcaca odroczyc ma wypozyczen
			for (int i = 0; i < tab_wyp[0].get_liczba_wypozyczen(); i++)
			{
				if (tab_wyp[i].get_pesel() == this->pesel)
					ilosc++;
			}

			//jesli ma wiecej niz 5 to stosujemy algorytm odraczania
			if (ilosc >= 5)	
			{
				int d = this->termin_platnosci.get_dzien();
				int m = this->termin_platnosci.get_miesiac();
				int r = this->termin_platnosci.get_rok();
				d += 10;
				if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
				{
					if (d > 31)
					{
						m++;
						d -= 31;
						if (m > 12)
						{
							r++;
							m = 1;
						}
					}
				}
				else if (m == 2)
				{
					if (d > 28)
					{
						m++;
						d -= 28;
					}
				}
				else
				{
					if (d > 30)
					{
						m++;
						d -= 30;
					}
				}
				(&termin_platnosci)->set_dzien(d);	//uzywamy adresow aby pracowac na oryginalach
				(&termin_platnosci)->set_miesiac(m);
				(&termin_platnosci)->set_rok(r);
				cout << "Termin platnosci zostal odroczony!" << endl;
				Sleep(2000);
				return;
			}
			else
			{
				cout << "Nie mozna odroczyc!" << endl;
			}
		}
	} while (true);
}

//skracanie okresu wypozyczenia
bool Wypozyczenie::skroc_okres(Data nowe_zakonczenie)
{
	bool x = false;
	if (this->data_od.get_rok() < nowe_zakonczenie.get_rok())
	{
		x=true;
	}
	else if (this->data_od.get_rok() > nowe_zakonczenie.get_rok())
	{
		x = false;
	}
	else
	{
		if (this->data_od.get_miesiac() < nowe_zakonczenie.get_miesiac())
		{
			x = true;
		}
		else if (this->data_od.get_miesiac() > nowe_zakonczenie.get_miesiac())
		{
			x = false;
		}
		else
		{
			if (this->data_od.get_dzien() < nowe_zakonczenie.get_dzien())
			{
				x = true;
			}
			else if (this->data_od.get_dzien() > nowe_zakonczenie.get_dzien())
			{
				x = false;
			}
			else
			{
				if (this->data_od.get_godzina() < nowe_zakonczenie.get_godzina())
				{
					x = true;
				}
				else
				{
					x = false;
				}
			}
		}
	}
	if (x == false)
		return false;

	if (this->data_do.get_rok() > nowe_zakonczenie.get_rok())
	{
		this->data_do.set_dzien(nowe_zakonczenie.get_dzien());
		this->data_do.set_miesiac(nowe_zakonczenie.get_miesiac());
		this->data_do.set_rok(nowe_zakonczenie.get_rok());
		this->data_do.set_godzina(nowe_zakonczenie.get_godzina());
		return true;
	}
	else if (this->data_do.get_rok() < nowe_zakonczenie.get_rok())
	{
		return false;
	}
	else
	{
		if (this->data_do.get_miesiac() > nowe_zakonczenie.get_miesiac())
		{
			this->data_do.set_dzien(nowe_zakonczenie.get_dzien());
			this->data_do.set_miesiac(nowe_zakonczenie.get_miesiac());
			this->data_do.set_rok(nowe_zakonczenie.get_rok());
			this->data_do.set_godzina(nowe_zakonczenie.get_godzina());
			return true;
		}
		else if (this->data_do.get_miesiac() < nowe_zakonczenie.get_miesiac())
		{
			return false;
		}
		else
		{
			if (this->data_do.get_dzien() > nowe_zakonczenie.get_dzien())
			{
				this->data_do.set_dzien(nowe_zakonczenie.get_dzien());
				this->data_do.set_miesiac(nowe_zakonczenie.get_miesiac());
				this->data_do.set_rok(nowe_zakonczenie.get_rok());
				this->data_do.set_godzina(nowe_zakonczenie.get_godzina());
				return true;
			}
			else if (this->data_do.get_dzien() < nowe_zakonczenie.get_dzien())
			{
				return false;
			}
			else
			{
				if (this->data_do.get_godzina() > nowe_zakonczenie.get_godzina())
				{
					this->data_do.set_dzien(nowe_zakonczenie.get_dzien());
					this->data_do.set_miesiac(nowe_zakonczenie.get_miesiac());
					this->data_do.set_rok(nowe_zakonczenie.get_rok());
					this->data_do.set_godzina(nowe_zakonczenie.get_godzina());
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}

}

//wydluzanie okresu wypozyczenia
bool Wypozyczenie::wydluz_okres(Data nowe_zakonczenie)
{
	if (this->data_do.get_rok() < nowe_zakonczenie.get_rok())
	{
		this->data_do.set_dzien(nowe_zakonczenie.get_dzien());
		this->data_do.set_miesiac(nowe_zakonczenie.get_miesiac());
		this->data_do.set_rok(nowe_zakonczenie.get_rok());
		this->data_do.set_godzina(nowe_zakonczenie.get_godzina());
		return true;
	}
	else if (this->data_do.get_rok() > nowe_zakonczenie.get_rok())
	{
		return false;
	}
	else
	{
		if (this->data_do.get_miesiac() < nowe_zakonczenie.get_miesiac())
		{
			this->data_do.set_dzien(nowe_zakonczenie.get_dzien());
			this->data_do.set_miesiac(nowe_zakonczenie.get_miesiac());
			this->data_do.set_rok(nowe_zakonczenie.get_rok());
			this->data_do.set_godzina(nowe_zakonczenie.get_godzina());
			return true;
		}
		else if (this->data_do.get_miesiac() > nowe_zakonczenie.get_miesiac())
		{
			return false;
		}
		else
		{
			if (this->data_do.get_dzien() < nowe_zakonczenie.get_dzien())
			{
				this->data_do.set_dzien(nowe_zakonczenie.get_dzien());
				this->data_do.set_miesiac(nowe_zakonczenie.get_miesiac());
				this->data_do.set_rok(nowe_zakonczenie.get_rok());
				this->data_do.set_godzina(nowe_zakonczenie.get_godzina());
				return true;
			}
			else if (this->data_do.get_dzien() > nowe_zakonczenie.get_dzien())
			{
				return false;
			}
			else
			{
				if (this->data_do.get_godzina() < nowe_zakonczenie.get_godzina())
				{
					this->data_do.set_dzien(nowe_zakonczenie.get_dzien());
					this->data_do.set_miesiac(nowe_zakonczenie.get_miesiac());
					this->data_do.set_rok(nowe_zakonczenie.get_rok());
					this->data_do.set_godzina(nowe_zakonczenie.get_godzina());
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}
}

//zwracany argument metody to wskaznik do tablicy z wypozyczeniami, a przekazywany argument to rozmiar tej tablicy
Wypozyczenie* Wypozyczenie::wczytaj_z_pliku(int& rozmiar)
{
	//pobranie danych z pliku 
	string linia;	//zmienna przechowujaca linie z pliku
	ifstream plik;	//zmienna obslugujaca plik 
	plik.open("Wypozyczenia.txt");	//otwieramy nasz plik z klientami
	Wypozyczenie* wypozyczenia = NULL;	//tablica na wypozyczenia, pozniej zwracana
	//sprawdzamy czy udalo sie otworzyc plik, jesli nie to wychodzimy z programu
	if (plik.good())
	{
		int liczba_wypozyczen = 0;
		while (getline(plik, linia))	// w tej petli sprawdzamy ile jest linijek zeby wiedziec jaki bedzie rozmiar tablicy 
		{
			liczba_wypozyczen++;
		}
		plik.clear();
		plik.seekg(0);
		rozmiar = liczba_wypozyczen;

		int calkowita;
		string znaki;

		wypozyczenia = new Wypozyczenie[liczba_wypozyczen];//utworzenie tablicy elementow wedlug obliczonej liczby wypozyczen
		//do naszej tablicy przepisujemy dane wartosci z pliku
		for (int i = 0; i < liczba_wypozyczen; i++)
		{
			getline(plik, linia);	//czytamy linie i po kolei ustawiamy dane w obiektach
			istringstream iss(linia);
			iss >> calkowita;
			wypozyczenia[i].data_od.set_dzien(calkowita);
			iss >> calkowita;
			wypozyczenia[i].data_od.set_miesiac(calkowita);
			iss >> calkowita;
			wypozyczenia[i].data_od.set_rok(calkowita);
			iss >> calkowita;
			wypozyczenia[i].data_od.set_godzina(calkowita);

			iss >> calkowita;
			wypozyczenia[i].data_do.set_dzien(calkowita);
			iss >> calkowita;
			wypozyczenia[i].data_do.set_miesiac(calkowita);
			iss >> calkowita;
			wypozyczenia[i].data_do.set_rok(calkowita);
			iss >> calkowita;
			wypozyczenia[i].data_do.set_godzina(calkowita);

			iss >> wypozyczenia[i].numer_rejestracyjny;
			iss >> wypozyczenia[i].pesel;
			iss >> znaki;
			if (znaki == "Zakonczone")
				wypozyczenia[i].zakonczone = 1;
			else
				wypozyczenia[i].zakonczone = 0;
			iss >> znaki;
			wypozyczenia[i].rachunek.set_sposob_platnosci(znaki);
			iss >> calkowita;
			wypozyczenia[i].rachunek.set_kwota(calkowita);
			iss >> znaki;
			if (znaki == "Zaplacone")
				wypozyczenia[i].rachunek.set_potwierdzenie(true);
			else
				wypozyczenia[i].rachunek.set_potwierdzenie(false);
			iss >> calkowita;
			wypozyczenia[i].termin_platnosci.set_dzien(calkowita);
			iss >> calkowita;
			wypozyczenia[i].termin_platnosci.set_miesiac(calkowita);
			iss >> calkowita;
			wypozyczenia[i].termin_platnosci.set_rok(calkowita);
			iss >> calkowita;
			wypozyczenia[i].termin_platnosci.set_godzina(calkowita);
		}
	}
	else
	{
		return nullptr;	//w przypadku gdy nie udaje sie otworzyc pliku zwracamy wskaznik pusty
	}
	plik.close();
	return wypozyczenia;
}

void Wypozyczenie::aktualizuj_plik(Wypozyczenie* wypozyczenia)
{
	int jest = -1;	//indeks dla wypozyczenia dla ktorego wywolana jest metoda

	//w przypadku wypozyczenia musimy sprawdzic wiecej pol, poniewaz przechowujemy takze stare wypozyczenia
	for (int i = 0; i < Wypozyczenie::get_liczba_wypozyczen(); i++)
		if (wypozyczenia[i].get_pesel() == this->pesel && wypozyczenia[i].get_numer_rejestracyjny() == this->numer_rejestracyjny
			&& wypozyczenia[i].get_data_od().get_dzien() == this->data_od.get_dzien() && wypozyczenia[i].get_data_od().get_miesiac() == this->data_od.get_miesiac() &&
			wypozyczenia[i].get_data_od().get_rok() == this->data_od.get_rok() && wypozyczenia[i].get_data_od().get_godzina() == this->data_od.get_godzina())
		{
			jest = i;	//jesli wypozyczenie jest juz w pliku to zapisujemy jego indeks w "jest"
			break;
		}

	//jesli zmienna "jest" pozostala bez zmian (-1) tzn ze nie ma wypozyczenia w pliku
	if (jest == -1) //wypozyczenia nie ma w pliku
	{
		ofstream plik;	//edytowanie pliku z dopisywaniem
		plik.open("Wypozyczenia.txt", ios::out | ios::app);
		if (Wypozyczenie::get_liczba_wypozyczen() != 1)	//warunek zeby nie zapisac pustej linii w przypadku pustego pliku
			plik << "\n";
		plik << this->get_data_od().get_dzien() << " ";
		plik << this->get_data_od().get_miesiac() << " ";
		plik << this->get_data_od().get_rok() << " ";
		plik << this->get_data_od().get_godzina() << " ";

		plik << this->get_data_do().get_dzien() << " ";
		plik << this->get_data_do().get_miesiac() << " ";
		plik << this->get_data_do().get_rok() << " ";
		plik << this->get_data_do().get_godzina() << " ";

		plik << this->get_numer_rejestracyjny() << " ";
		plik << this->get_pesel() << " ";
		if (this->get_zakonczone() == 1)
			plik << "Zakonczone" << " ";
		else
			plik << "Niezakonczone" << " ";

		plik << this->get_rachunek().get_sposob_platnosci() << " ";
		plik << this->get_rachunek().get_kwota() << " ";
		if (this->get_rachunek().get_potwierdzenie() == 1)
			plik << "Zaplacone" << " ";
		else
			plik << "Niezaplacone" << " ";
		plik << this->termin_platnosci.get_dzien() << " ";
		plik << this->termin_platnosci.get_miesiac() << " ";
		plik << this->termin_platnosci.get_rok() << " ";
		plik << this->termin_platnosci.get_godzina() << " ";
		plik.close();
	}
	else
	{
		ofstream plik;	//edytowanie pliku z nadpisaniem
		plik.open("Wypozyczenia.txt");
		for (int i = 0; i < Wypozyczenie::get_liczba_wypozyczen(); i++)
		{
			if (i == jest) continue;	//pomijane okrazenie w petli zeby wypozyczenia nie zapisac 2x
			if (!(i == 1 && jest == 0))	//warunek zeby nie zapisac pustej linii w przypadku pustego pliku
				if (i != 0) plik << "\n";
			plik << wypozyczenia[i].get_data_od().get_dzien() << " ";
			plik << wypozyczenia[i].get_data_od().get_miesiac() << " ";
			plik << wypozyczenia[i].get_data_od().get_rok() << " ";
			plik << wypozyczenia[i].get_data_od().get_godzina() << " ";

			plik << wypozyczenia[i].get_data_do().get_dzien() << " ";
			plik << wypozyczenia[i].get_data_do().get_miesiac() << " ";
			plik << wypozyczenia[i].get_data_do().get_rok() << " ";
			plik << wypozyczenia[i].get_data_do().get_godzina() << " ";

			plik << wypozyczenia[i].get_numer_rejestracyjny() << " ";
			plik << wypozyczenia[i].get_pesel() << " ";
			if (wypozyczenia[i].get_zakonczone() == 1)
				plik << "Zakonczone" << " ";
			else
				plik << "Niezakonczone" << " ";

			plik << wypozyczenia[i].get_rachunek().get_sposob_platnosci() << " ";
			plik << wypozyczenia[i].get_rachunek().get_kwota() << " ";
			if (wypozyczenia[i].get_rachunek().get_potwierdzenie() == 1)
				plik << "Zaplacone" << " ";
			else
				plik << "Niezaplacone" << " ";
			plik << wypozyczenia[i].termin_platnosci.get_dzien() << " ";
			plik << wypozyczenia[i].termin_platnosci.get_miesiac() << " ";
			plik << wypozyczenia[i].termin_platnosci.get_rok() << " ";
			plik << wypozyczenia[i].termin_platnosci.get_godzina() << " ";
		}

		//na koncu dopisujemy nowe wypozyczenie z aktualnymi danym
		if (Wypozyczenie::get_liczba_wypozyczen() != 1)
			plik << "\n";
		plik << this->get_data_od().get_dzien() << " ";
		plik << this->get_data_od().get_miesiac() << " ";
		plik << this->get_data_od().get_rok() << " ";
		plik << this->get_data_od().get_godzina() << " ";

		plik << this->get_data_do().get_dzien() << " ";
		plik << this->get_data_do().get_miesiac() << " ";
		plik << this->get_data_do().get_rok() << " ";
		plik << this->get_data_do().get_godzina() << " ";

		plik << this->get_numer_rejestracyjny() << " ";
		plik << this->get_pesel() << " ";
		if (this->get_zakonczone() == 1)
			plik << "Zakonczone" << " ";
		else
			plik << "Niezakonczone" << " ";

		plik << this->get_rachunek().get_sposob_platnosci() << " ";
		plik << this->get_rachunek().get_kwota() << " ";
		if (this->get_rachunek().get_potwierdzenie() == 1)
			plik << "Zaplacone" << " ";
		else
			plik << "Niezaplacone" << " ";
		plik << this->termin_platnosci.get_dzien() << " ";
		plik << this->termin_platnosci.get_miesiac() << " ";
		plik << this->termin_platnosci.get_rok() << " ";
		plik << this->termin_platnosci.get_godzina() << " ";
		plik.close();
	}
}

bool Wypozyczenie::get_zakonczone()
{
	return Wypozyczenie::zakonczone;
}

string Wypozyczenie::get_numer_rejestracyjny()
{
	return Wypozyczenie::numer_rejestracyjny;
}
string Wypozyczenie::get_pesel()
{
	return Wypozyczenie::pesel;
}
Data Wypozyczenie::get_data_od()
{
	return Wypozyczenie::data_od;
}
Data Wypozyczenie::get_data_do()
{
	return Wypozyczenie::data_do;
}
Data Wypozyczenie::get_termin_platnosci()
{
	return Wypozyczenie::termin_platnosci;
}
Platnosc * Wypozyczenie::get_rachunek1()
{
	return (&rachunek);
}
Platnosc Wypozyczenie::get_rachunek()
{
	return Wypozyczenie::rachunek;
}
int Wypozyczenie::get_liczba_wypozyczen()
{
	return liczba_wypozyczen;
}


void Wypozyczenie::set_termin_platnosci(Data d)
{
	Wypozyczenie::termin_platnosci = d;
}
void Wypozyczenie::set_nr_rej(string nr)
{
	Wypozyczenie::numer_rejestracyjny = nr;
}
void Wypozyczenie::set_pesel(string pes)
{
	Wypozyczenie::pesel = pes;
}
void Wypozyczenie::set_zakonczone(bool zakon)
{
	Wypozyczenie::zakonczone = zakon;
}