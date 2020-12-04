#ifndef WLASCICIEL_H
#define WLASCICIEL_H

class Wlasciciel : Pracownik
{


public:
	void dodaj_pojazd();

	void zmien_cene(string nr_rej);

	void usun_pojazd(string nr_rej);

	void zarzadzaj_dzialalnoscia();
};

#endif
