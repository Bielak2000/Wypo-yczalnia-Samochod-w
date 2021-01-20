#include "Platnosc.h"
/*
Platnosc::Platnosc(string sp, int kw, bool potw, bool odr):
	Sposob_platnosci(sp), Kwota(kw), Potwierdzenie(potw), Odroczenie(odr)
{

}*/

Platnosc::Platnosc(int kw) :Kwota(kw), Sposob_platnosci("NIEZDEFINIOWANY"), Potwierdzenie(false)
{}

bool Platnosc::czy_zaplacono()
{
	return Potwierdzenie;
}

bool Platnosc::mozliwosc_odroczenia()
{
	// TODO - implement Platnosc::mozliwosc_odroczenia
	throw "Not yet implemented";
}

void Platnosc::dokonaj_platnosci()
{
	// TODO - implement Platnosc::dokonaj_platnosci
	throw "Not yet implemented";
}

void Platnosc::set_potwierdzenie(bool potw)
{
	Potwierdzenie = potw;
}

string Platnosc::get_sposob_platnosci()
{
	return Platnosc::Sposob_platnosci;
}

int Platnosc::get_kwota()
{
	return Platnosc::Kwota;
}

bool Platnosc::get_potwierdzenie()
{
	return Platnosc::Potwierdzenie;
}

void Platnosc::set_kwota(int cena)
{
	this->Kwota = cena;
}


void Platnosc::set_sposob_platnosci(string sposob)
{
	Platnosc::Sposob_platnosci = sposob;
}
