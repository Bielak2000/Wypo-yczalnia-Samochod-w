#include "Platnosc.h"

//Konstruktor
Platnosc::Platnosc(int kw) :kwota(kw), sposob_platnosci("NIEZDEFINIOWANY"), potwierdzenie(false)
{}

//Metoda sprawdzaj¹ca czy dokonano p³atnoœci (getter pola potwierdzenie)
bool Platnosc::czy_zaplacono()
{
	return potwierdzenie;
}

//Settery
void Platnosc::set_potwierdzenie(bool potw)
{
	potwierdzenie = potw;
}
void Platnosc::set_kwota(int cena)
{
	this->kwota = cena;
}
void Platnosc::set_sposob_platnosci(string sposob)
{
	Platnosc::sposob_platnosci = sposob;
}

//Gettery
string Platnosc::get_sposob_platnosci()
{
	return Platnosc::sposob_platnosci;
}
int Platnosc::get_kwota()
{
	return Platnosc::kwota;
}
bool Platnosc::get_potwierdzenie()
{
	return Platnosc::potwierdzenie;
}