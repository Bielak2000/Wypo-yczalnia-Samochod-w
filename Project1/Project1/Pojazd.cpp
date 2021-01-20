#include "Pojazd.h"


int Pojazd::liczba_pojazdow = 0;

/*Pojazd::Pojazd()
{
	Pojazd::liczba_pojazdow++;
}*/

Pojazd::Pojazd(string n, string rodz, string mar, string mod,
	int r, string sil, string przeb, int cen_godz, bool dost)
{
	this->Numer_rejestracyjny = n;
	this->Rodzaj = rodz;
	this->Marka = mar;
	this->Model = mod;
	this->Rok = r;
	this->Silnik = sil;
	this->Przebieg = przeb;
	this->Cena_za_godzine = cen_godz;
	this->Dostepny = dost;

	this->liczba_pojazdow++;
}

void Pojazd::wyswietl_dane()
{
	cout << "Rodzaj: " << Rodzaj;
	cout << ", marka: " << Marka;
	cout << ", model: " << Model;
	cout << ", rok: " << Rok;
	cout << ", numer rejestracyjny: " << Numer_rejestracyjny << endl;
	cout << "\tSilnik: " << Silnik;
	cout << ", przebieg: " << Przebieg;
	if (Dostepny == 1)
		cout << ", dostepny: TAK";
	else
		cout << ", dostepny: NIE";
	cout << ", cena za godzine: " << Cena_za_godzine << ".";
}

void Pojazd::zmien_przebieg(string km)
{
	Przebieg = km;
}

bool Pojazd::sprawdz_dostepnosc(string nr)
{
	if (Dostepny == 1)
	{
		cout << "Pojazd jest dostepny." << endl;
		return true;
	}
	else
	{
		cout << "Pojazd jest niedostepny." << endl;
		return false;
	}
}

void Pojazd::zmien_cene_pojazdu(int cena)
{
	Cena_za_godzine = cena;
}

void Pojazd::wypozycz()
{
	zmien_dostepnosc();
}

void Pojazd::zmien_dostepnosc()
{
	if (Dostepny)
	{
		Dostepny = false;
	}
	else
	{
		Dostepny = true;
	}
}

Pojazd* Pojazd::wczytaj_z_pliku(int& n)
{
	//pobranie danych z pliku 
	string linia;//zmienna przehcowuja linie z pliku
	ifstream plik;//zmienna obslugujaca plik 
	plik.open("Pojazdy.txt");//otwieramy nasz plik z przelewami
	//sprawdzamy czy udalo sie otowrzyc plik, jesli nie to wychodzimy z programu
	Pojazd* pojazdy = NULL;
	if (plik.good())
	{
		int liczba_pojazdow = 0;
		while (getline(plik, linia))
		{
			liczba_pojazdow++;
		}
		plik.clear();
		plik.seekg(0);
		n = liczba_pojazdow;

		pojazdy = new Pojazd[liczba_pojazdow];//utowrzenie tablicy elementow ktorymi sa obiekty strukutry dane o rozmiarze 10000
		//do naszej tablicy przepisuje dane wartosci z pliku
		for (int i = 0; i < liczba_pojazdow; i++)
		{
			getline(plik, linia);
			istringstream iss(linia);
			iss >> pojazdy[i].Numer_rejestracyjny;
			iss >> pojazdy[i].Rodzaj;
			iss >> pojazdy[i].Marka;
			iss >> pojazdy[i].Model;
			iss >> pojazdy[i].Rok;
			iss >> pojazdy[i].Silnik;
			iss >> pojazdy[i].Przebieg;
			iss >> pojazdy[i].Cena_za_godzine;
			iss >> pojazdy[i].Dostepny;
		}
	}
	else
	{
		return nullptr;
	}
	plik.close();
	return pojazdy;
}

void Pojazd::aktualizuj_plik(Pojazd* pojazdy)
{
	//int n, jest = -1;	//ilosc pojazdow, indeks dla pojazdu dla ktorego wywolana jest metoda
	//Pojazd* pojazdy = Pojazd::wczytaj_z_pliku(n);	//wczytujemy pojazdy
	int jest = -1;

	for (int i = 0; i < pojazdy[i].get_liczba_pojazdow(); i++)
		if (pojazdy[i].get_numer_rejestracyjny() == this->Numer_rejestracyjny) 
		{
			jest = i;	//jesli pojazd jest juz w pliku to zapisujemy jego indeks w "jest"
			break;
		}

	//jesli zmienna "jest" pozostala bez zmian -1 tzn ze nie ma pojazdu w pliku
	if (jest == -1) //pojazdu nie ma w pliku
	{
		ofstream plik;	//edytowanie pliku z dopisywaniem
		plik.open("Pojazdy.txt", ios::out|ios::app);
		if (pojazdy[0].get_liczba_pojazdow() != 0)
			plik << "\n";
		plik << this->Numer_rejestracyjny << " ";
		plik << this->Rodzaj << " ";
		plik << this->Marka << " ";
		plik << this->Model << " ";
		plik << this->Rok << " ";
		plik << this->Silnik << " ";
		plik << this->Przebieg << " ";
		plik << this->Cena_za_godzine << " ";
		plik << this->Dostepny;
		plik.close();
	}
	else
	{
		ofstream plik;	//edytowanie pliku z nadpisaniem
		plik.open("Pojazdy.txt");
		for (int i = 0; i < pojazdy[i].get_liczba_pojazdow(); i++)
		{
			if (i == jest) continue;	//pomijane okrazenie w petli zeby pojazdu nie zapisac 2x
			if (!(i == 1 && jest == 0))
				if (i != 0)	 plik << "\n";
			plik << pojazdy[i].Numer_rejestracyjny << " ";
			plik << pojazdy[i].Rodzaj << " ";
			plik << pojazdy[i].Marka << " ";
			plik << pojazdy[i].Model << " ";
			plik << pojazdy[i].Rok << " ";
			plik << pojazdy[i].Silnik << " ";
			plik << pojazdy[i].Przebieg << " ";
			plik << pojazdy[i].Cena_za_godzine << " ";
			plik << pojazdy[i].Dostepny;
		}

		//na koncu dopisujemy nowy pojazd z aktualnymi danymi
		if (pojazdy[0].get_liczba_pojazdow() != 1)
			plik << "\n";
		plik << this->Numer_rejestracyjny << " ";
		plik << this->Rodzaj << " ";
		plik << this->Marka << " ";
		plik << this->Model << " ";
		plik << this->Rok << " ";
		plik << this->Silnik << " ";
		plik << this->Przebieg << " ";
		plik << this->Cena_za_godzine << " ";
		plik << this->Dostepny;

		plik.close();
	}
}

string Pojazd::get_numer_rejestracyjny()
{
	return Pojazd::Numer_rejestracyjny;
}

string Pojazd::get_rodzaj()
{
	return Pojazd::Rodzaj;
}

string Pojazd::get_marka()
{
	return Pojazd::Marka;
}

string Pojazd::get_model()
{
	return Pojazd::Model;
}

int Pojazd::get_rok() 
{
	return Pojazd::Rok;
}

string Pojazd::get_silnik()
{
	return Pojazd::Silnik;
}

string Pojazd::get_przebieg()
{
	return Pojazd::Przebieg;
}

bool Pojazd::get_dostepnosc()
{
	return Pojazd::Dostepny;
}

int Pojazd::get_liczba_pojazdow()
{
	return Pojazd::liczba_pojazdow;
}

int Pojazd::get_cena_za_godzine()
{
	return Pojazd::Cena_za_godzine;
}

void Pojazd::set_cena_za_godzine(int cena)
{
	Cena_za_godzine = cena;
}

void Pojazd::set_przebieg(string km)
{
	Przebieg = km;
}

void Pojazd::set_dostepny( bool dostep )
{
	Pojazd::Dostepny = dostep;
}

/*
void Pojazd::set_numer_rejestracyjny()
{

}

void Pojazd::set_rodzaj();

void Pojazd::set_marka();

void Pojazd::set_model();

void Pojazd::set_rok();

void Pojazd::set_silnik();

void Pojazd::set_przebieg();

void Pojazd::set_cena_za_godzine();

bool Pojazd::get_dostepny()
{
	if (Pojazd::Dostepny == 1)
		return true;
	else
		return false;
}*/

