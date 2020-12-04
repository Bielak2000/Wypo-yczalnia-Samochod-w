#ifndef PLATNOSC_H
#define PLATNOSC_H

class Platnosc
{

private:
	string Sposob_platnosci;
	int Kwota;
	boolean Potwierdzenie;
	boolean Odroczenie;

public:
	boolean czy_zaplacono();

	boolean mozliwosc_odroczenia();

	void dokonaj_platnosci();

	void zaplac_karta();

	void zaplac_gotowka();
};

#endif
