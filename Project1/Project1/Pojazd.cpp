#include "Pojazd.h"

int Pojazd::liczba_pojazdow = 0;//poczatkowa inicjalizacja zmiennej statycznej

//konstuktor tej klasy wraz z inkrementacja statycznego pola wskauzjacego na liczbe pojazdow
Pojazd::Pojazd(string nr_rejj, string rodz, string markaa, string mod,
	int rokk, string silnikk, string przebiegg, int cen_godz, bool dost)
{
	this->numer_rejestracyjny = nr_rejj;
	this->rodzaj = rodz;
	this->marka = markaa;
	this->model = mod;
	this->rok = rokk;
	this->silnik = silnikk;
	this->przebieg = przebiegg;
	this->cena_za_godzine = cen_godz;
	this->dostepny = dost;
	this->liczba_pojazdow++;
}

//metoda sluzaca do wyswietlenia wszytskich danych o pojezdzie
void Pojazd::wyswietl_dane()
{
	cout << "Rodzaj: " << rodzaj;
	cout << ", marka: " << marka;
	cout << ", model: " << model;
	cout << ", rok: " << rok;
	cout << ", numer rejestracyjny: " << numer_rejestracyjny << endl;
	cout << "\tSilnik: " << silnik;
	cout << ", przebieg: " << przebieg;
	if (dostepny == 1)
		cout << ", dostepny: TAK";
	else
		cout << ", dostepny: NIE";
	cout << ", cena za godzine: " << cena_za_godzine << ".";
}

//metoda sluzaca do zmiany przebiegu pojazdu
void Pojazd::zmien_przebieg(string km)
{
	przebieg = km;
}

//metoda sluzaca do zmiany ceny pojazdu
void Pojazd::zmien_cene_pojazdu(int cena)
{
	cena_za_godzine = cena;
}

//metoda zmieniajaca dostepnosc pojazdu na przeciwna
void Pojazd::zmien_dostepnosc()
{
	if (dostepny)
	{
		dostepny = false;
	}
	else
	{
		dostepny = true;
	}
}

//zwracany argument metody to wskaznik do tablicy z pojazdami, a przekazywany argument to rozmiar tej tablicy
Pojazd* Pojazd::wczytaj_z_pliku(int& rozmiar)
{
	//pobranie danych z pliku 
	string linia;	//zmienna przechowujaca linie z pliku
	ifstream plik;	//zmienna obslugujaca plik 
	plik.open("Pojazdy.txt");	//otwieramy nasz plik z przelewami
	Pojazd* pojazdy = NULL;
	//sprawdzamy czy udalo sie otworzyc plik, jesli nie to wychodzimy z programu
	if (plik.good())
	{
		int liczba_pojazdow = 0;
		while (getline(plik, linia))	// w tej petli sprawdzamy ile jest linijek zeby wiedziec jaki bedzie rozmiar tablicy 
		{
			liczba_pojazdow++;
		}
		plik.clear();
		plik.seekg(0);
		rozmiar = liczba_pojazdow;

		pojazdy = new Pojazd[liczba_pojazdow];	//utworzenie tablicy elementow na podstawie obliczonej ilosci pojazdow
		//do naszej tablicy przepisujemy dane wartosci z pliku
		for (int i = 0; i < liczba_pojazdow; i++)
		{
			getline(plik, linia);
			istringstream iss(linia);
			iss >> pojazdy[i].numer_rejestracyjny;
			iss >> pojazdy[i].rodzaj;
			iss >> pojazdy[i].marka;
			iss >> pojazdy[i].model;
			iss >> pojazdy[i].rok;
			iss >> pojazdy[i].silnik;
			iss >> pojazdy[i].przebieg;
			iss >> pojazdy[i].cena_za_godzine;
			iss >> pojazdy[i].dostepny;
		}
	}
	else
	{
		return nullptr;	//aktualizacja pliku z pojazdami
	}
	plik.close();
	return pojazdy;
}


void Pojazd::aktualizuj_plik(Pojazd* pojazdy)	//przyjmowany argument to tablica pojazdow
{
	int jest = -1;	//zmienna na indeks pojazdu

	for (int i = 0; i < pojazdy[i].get_liczba_pojazdow(); i++)
		if (pojazdy[i].get_numer_rejestracyjny() == this->numer_rejestracyjny) 
		{
			jest = i;	//jesli pojazd jest juz w pliku to zapisujemy jego indeks w "jest"
			break;
		}

	//jesli zmienna "jest" pozostala bez zmian (-1) tzn ze nie ma pojazdu w pliku
	if (jest == -1) //pojazdu nie ma w pliku
	{
		ofstream plik;	//edytowanie pliku z dopisywaniem
		plik.open("Pojazdy.txt", ios::out|ios::app);
		if (pojazdy[0].get_liczba_pojazdow() != 0)
			plik << "\n";
		plik << this->numer_rejestracyjny << " ";
		plik << this->rodzaj << " ";
		plik << this->marka << " ";
		plik << this->model << " ";
		plik << this->rok << " ";
		plik << this->silnik << " ";
		plik << this->przebieg << " ";
		plik << this->cena_za_godzine << " ";
		plik << this->dostepny;
		plik.close();
	}
	else
	{
		ofstream plik;	//edytowanie pliku z nadpisaniem
		plik.open("Pojazdy.txt");
		for (int i = 0; i < pojazdy[i].get_liczba_pojazdow(); i++)
		{
			if (i == jest) continue;	//pomijane okrazenie w petli zeby pojazdu nie zapisac 2x
			if (!(i == 1 && jest == 0))	//warunek zeby nie bylo linii odstepu w przypadku pustego pliku
				if (i != 0)	 plik << "\n";
			plik << pojazdy[i].numer_rejestracyjny << " ";
			plik << pojazdy[i].rodzaj << " ";
			plik << pojazdy[i].marka << " ";
			plik << pojazdy[i].model << " ";
			plik << pojazdy[i].rok << " ";
			plik << pojazdy[i].silnik << " ";
			plik << pojazdy[i].przebieg << " ";
			plik << pojazdy[i].cena_za_godzine << " ";
			plik << pojazdy[i].dostepny;
		}

		//na koncu dopisujemy pojazd z aktualnymi danymi
		if (pojazdy[0].get_liczba_pojazdow() != 1)
			plik << "\n";
		plik << this->numer_rejestracyjny << " ";
		plik << this->rodzaj << " ";
		plik << this->marka << " ";
		plik << this->model << " ";
		plik << this->rok << " ";
		plik << this->silnik << " ";
		plik << this->przebieg << " ";
		plik << this->cena_za_godzine << " ";
		plik << this->dostepny;

		plik.close();
	}
}

//gettery
string Pojazd::get_numer_rejestracyjny()
{
	return Pojazd::numer_rejestracyjny;
}
string Pojazd::get_rodzaj()
{
	return Pojazd::rodzaj;
}
string Pojazd::get_marka()
{
	return Pojazd::marka;
}
string Pojazd::get_model()
{
	return Pojazd::model;
}
int Pojazd::get_rok() 
{
	return Pojazd::rok;
}
string Pojazd::get_silnik()
{
	return Pojazd::silnik;
}
string Pojazd::get_przebieg()
{
	return Pojazd::przebieg;
}
bool Pojazd::get_dostepnosc()
{
	return Pojazd::dostepny;
}
int Pojazd::get_liczba_pojazdow()
{
	return Pojazd::liczba_pojazdow;
}
int Pojazd::get_cena_za_godzine()
{
	return Pojazd::cena_za_godzine;
}

//settery
void Pojazd::set_dostepny(bool dostep)
{
	Pojazd::dostepny = dostep;
}