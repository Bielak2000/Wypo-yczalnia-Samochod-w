#ifndef WYPOZYCZENIE_H
#define WYPOZYCZENIE_H
//sadasdasdasd
class Wypozyczenie
{

private:
	Data Data_do;
	string Numer_rejestracyjny;
	boolean Zakonczone;
	Osoba klient;
	Data termin_platnosci;

public:
	boolean zmien_okres();

	void zakoncz_wypozyczenie();

	Data zwroc_date_zakonczenia();

	void dodaj_auto(string nr);

	void dane_klienta(Osoba klient);

	void podaj_termin();

	void zaplac();

	void skroc_okres(Data rozpoczecie, Data zakonczenie);

	void wydluz_okres(Data rozpoczecie, Data zakonczenie);

	void zmien_termin_platnosci(Data d);

	Data zwroc_date_rozpoczecia();
};

#endif
