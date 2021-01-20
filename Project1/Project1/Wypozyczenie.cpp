#include "Wypozyczenie.h"
#include "Platnosc.h"
#include <iostream>
using namespace std;

int Wypozyczenie::liczba_wypozyczen = 0;

Wypozyczenie::Wypozyczenie(Data d1, Data d2, string nr_rej, string pes, int cena):Data_od(d1), Data_do(d2), Numer_rejestracyjny(nr_rej), pesel(pes)
{
	Wypozyczenie::Rachunek.set_kwota(cena);
	liczba_wypozyczen++;
}

void Wypozyczenie::pesel_klienta(string nr)
{
	pesel = nr;
}

void Wypozyczenie::zaplac(Wypozyczenie * tab_w)
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
		} while (wybor != 1 && wybor != 2 && wybor != 3);
		if (wybor == 1)
		{
			this->get_rachunek1()->set_sposob_platnosci("gotowka");
			cout << "Kwota do zaplaty " << this->get_rachunek().get_kwota() << "zl." << endl;
			cout << "Prosze o wplate!" << endl;
			Sleep(1000);
			cout << "Dziekujemy za zaplate!" << endl;
			Sleep(2000);
			system("cls");
			this->get_rachunek1()->set_potwierdzenie(true);
			return;
		}
		else if (wybor == 2)
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
		else if (wybor == 3)
		{
			int ilosc = 0;
			for (int i = 0; i < tab_w[0].get_liczba_wypozyczen(); i++)
			{
				if (tab_w[i].get_pesel() == this->pesel)
					ilosc++;
			}

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
				(&termin_platnosci)->set_dzien(d);
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

bool Wypozyczenie::skroc_okres(Data nowe_zakonczenie)
{
	bool x = false;
	if (this->Data_od.get_rok() < nowe_zakonczenie.get_rok())
	{
		x=true;
	}
	else if (this->Data_od.get_rok() > nowe_zakonczenie.get_rok())
	{
		x = false;
	}
	else
	{
		if (this->Data_od.get_miesiac() < nowe_zakonczenie.get_miesiac())
		{
			x = true;
		}
		else if (this->Data_od.get_miesiac() > nowe_zakonczenie.get_miesiac())
		{
			x = false;
		}
		else
		{
			if (this->Data_od.get_dzien() < nowe_zakonczenie.get_dzien())
			{
				x = true;
			}
			else if (this->Data_od.get_dzien() > nowe_zakonczenie.get_dzien())
			{
				x = false;
			}
			else
			{
				if (this->Data_od.get_godzina() < nowe_zakonczenie.get_godzina())
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

	if (this->Data_do.get_rok() > nowe_zakonczenie.get_rok())
	{
		this->Data_do.set_dzien(nowe_zakonczenie.get_dzien());
		this->Data_do.set_miesiac(nowe_zakonczenie.get_miesiac());
		this->Data_do.set_rok(nowe_zakonczenie.get_rok());
		this->Data_do.set_godzina(nowe_zakonczenie.get_godzina());
		return true;
	}
	else if (this->Data_do.get_rok() < nowe_zakonczenie.get_rok())
	{
		return false;
	}
	else
	{
		if (this->Data_do.get_miesiac() > nowe_zakonczenie.get_miesiac())
		{
			this->Data_do.set_dzien(nowe_zakonczenie.get_dzien());
			this->Data_do.set_miesiac(nowe_zakonczenie.get_miesiac());
			this->Data_do.set_rok(nowe_zakonczenie.get_rok());
			this->Data_do.set_godzina(nowe_zakonczenie.get_godzina());
			return true;
		}
		else if (this->Data_do.get_miesiac() < nowe_zakonczenie.get_miesiac())
		{
			return false;
		}
		else
		{
			if (this->Data_do.get_dzien() > nowe_zakonczenie.get_dzien())
			{
				this->Data_do.set_dzien(nowe_zakonczenie.get_dzien());
				this->Data_do.set_miesiac(nowe_zakonczenie.get_miesiac());
				this->Data_do.set_rok(nowe_zakonczenie.get_rok());
				this->Data_do.set_godzina(nowe_zakonczenie.get_godzina());
				return true;
			}
			else if (this->Data_do.get_dzien() < nowe_zakonczenie.get_dzien())
			{
				return false;
			}
			else
			{
				if (this->Data_do.get_godzina() > nowe_zakonczenie.get_godzina())
				{
					this->Data_do.set_dzien(nowe_zakonczenie.get_dzien());
					this->Data_do.set_miesiac(nowe_zakonczenie.get_miesiac());
					this->Data_do.set_rok(nowe_zakonczenie.get_rok());
					this->Data_do.set_godzina(nowe_zakonczenie.get_godzina());
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

bool Wypozyczenie::wydluz_okres(Data nowe_zakonczenie)
{
	if (this->Data_do.get_rok() < nowe_zakonczenie.get_rok())
	{
		this->Data_do.set_dzien(nowe_zakonczenie.get_dzien());
		this->Data_do.set_miesiac(nowe_zakonczenie.get_miesiac());
		this->Data_do.set_rok(nowe_zakonczenie.get_rok());
		this->Data_do.set_godzina(nowe_zakonczenie.get_godzina());
		return true;
	}
	else if (this->Data_do.get_rok() > nowe_zakonczenie.get_rok())
	{
		return false;
	}
	else
	{
		if (this->Data_do.get_miesiac() < nowe_zakonczenie.get_miesiac())
		{
			this->Data_do.set_dzien(nowe_zakonczenie.get_dzien());
			this->Data_do.set_miesiac(nowe_zakonczenie.get_miesiac());
			this->Data_do.set_rok(nowe_zakonczenie.get_rok());
			this->Data_do.set_godzina(nowe_zakonczenie.get_godzina());
			return true;
		}
		else if (this->Data_do.get_miesiac() > nowe_zakonczenie.get_miesiac())
		{
			return false;
		}
		else
		{
			if (this->Data_do.get_dzien() < nowe_zakonczenie.get_dzien())
			{
				this->Data_do.set_dzien(nowe_zakonczenie.get_dzien());
				this->Data_do.set_miesiac(nowe_zakonczenie.get_miesiac());
				this->Data_do.set_rok(nowe_zakonczenie.get_rok());
				this->Data_do.set_godzina(nowe_zakonczenie.get_godzina());
				return true;
			}
			else if (this->Data_do.get_dzien() > nowe_zakonczenie.get_dzien())
			{
				return false;
			}
			else
			{
				if (this->Data_do.get_godzina() < nowe_zakonczenie.get_godzina())
				{
					this->Data_do.set_dzien(nowe_zakonczenie.get_dzien());
					this->Data_do.set_miesiac(nowe_zakonczenie.get_miesiac());
					this->Data_do.set_rok(nowe_zakonczenie.get_rok());
					this->Data_do.set_godzina(nowe_zakonczenie.get_godzina());
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

bool Wypozyczenie::get_zakonczone()
{
	return Wypozyczenie::Zakonczone;
}

void Wypozyczenie::set_termin_platnosci(Data d)
{
	Wypozyczenie::termin_platnosci = d;
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

Platnosc * Wypozyczenie::get_rachunek1()
{
	return (&Rachunek);
}
Platnosc Wypozyczenie::get_rachunek()
{
	return Wypozyczenie::Rachunek;
}


void Wypozyczenie::set_nr_rej(string nr)
{
	Wypozyczenie::Numer_rejestracyjny = nr;
}

int Wypozyczenie::get_liczba_wypozyczen()
{
	return liczba_wypozyczen;
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
			iss >> znaki;
			if (znaki == "Zaplacone")
				Wypozyczenia[i].Rachunek.set_potwierdzenie(true);
			else
				Wypozyczenia[i].Rachunek.set_potwierdzenie(false);
			iss >> calkowita;
			Wypozyczenia[i].termin_platnosci.set_dzien(calkowita);
			iss >> calkowita;
			Wypozyczenia[i].termin_platnosci.set_miesiac(calkowita);
			iss >> calkowita;
			Wypozyczenia[i].termin_platnosci.set_rok(calkowita);
			iss >> calkowita;
			Wypozyczenia[i].termin_platnosci.set_godzina(calkowita);
		}
	}
	else
	{
		return nullptr;
	}
	plik.close();
	return Wypozyczenia;
}

void Wypozyczenie::aktualizuj_plik(Wypozyczenie* wypozyczenia)
{
	int jest = -1;	//indeks dla wypozyczenia dla ktorego wywolana jest metoda

	for (int i = 0; i < Wypozyczenie::get_liczba_wypozyczen(); i++)
		if (wypozyczenia[i].get_pesel() == this->pesel && wypozyczenia[i].get_numer_rejestracyjny() == this->Numer_rejestracyjny
			&& wypozyczenia[i].get_data_od().get_dzien() == this->Data_od.get_dzien() && wypozyczenia[i].get_data_od().get_miesiac() == this->Data_od.get_miesiac() &&
			wypozyczenia[i].get_data_od().get_rok() == this->Data_od.get_rok() && wypozyczenia[i].get_data_od().get_godzina() == this->Data_od.get_godzina())
		{
			jest = i;	//jesli wypozyczenie jest juz w pliku to zapisujemy jego indeks w "jest"
			break;
		}

	//jesli zmienna "jest" pozostala bez zmian -1 tzn ze nie ma wypozyczenia w pliku
	if (jest == -1) //wypozyczenia nie ma w pliku
	{
		ofstream plik;	//edytowanie pliku z dopisywaniem
		plik.open("Wypozyczenia.txt", ios::out | ios::app);
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
	else
	{
		ofstream plik;	//edytowanie pliku z nadpisaniem
		plik.open("Wypozyczenia.txt");
		for (int i = 0; i < Wypozyczenie::get_liczba_wypozyczen(); i++)
		{
			if (i == jest) continue;	//pomijane okrazenie w petli zeby wypozyczenia nie zapisac 2x
			if (!(i == 1 && jest == 0))
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
		//edytowanie pliku z dopisywaniem
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