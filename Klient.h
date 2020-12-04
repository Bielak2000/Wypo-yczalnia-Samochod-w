#ifndef KLIENT_H
#define KLIENT_H

class Klient : Osoba
{


public:
	boolean wypozycz(string nr);

	void zarzadzaj_wypozyczeniem();

	void wyswietl_oferte();

	void dokonaj_platnosci(Wypozyczenie w);

	void zwroc_pojazd(Wypozyczenie w);
};

#endif
