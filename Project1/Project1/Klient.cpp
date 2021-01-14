#include "Klient.h"
#include "Wypozyczenie.h"
#include <iostream>

using namespace std;

Klient::Klient(string Im, string Naz, string Pes, string Addr, string Numer):
	Osoba(Im,Naz,Pes,Addr,Numer)
{
}

bool Klient::wypozycz(string nr, Pojazd* tablica_pojazdow)
{
	for (int i = 0; i < tablica_pojazdow[0].liczba_pojazdow; i++)
	{
		if (tablica_pojazdow[i].Numer_rejestracyjny == nr)
		{
			if (tablica_pojazdow[i].Dostepny)
				return true;
			else
				return false;
		}
	}
	return false;
}

void Klient::zarzadzaj_wypozyczeniem()
{
	// TODO - implement Klient::zarzadzaj_wypozyczeniem
	throw "Not yet implemented";
}

void Klient::wyswietl_oferte(Pojazd* tablica_pojazdow)
{
	for (int i = 0; i < tablica_pojazdow[0].liczba_pojazdow; i++)
	{
		tablica_pojazdow[i].liczba_pojazdow;
	}
}

void Klient::dokonaj_platnosci(Wypozyczenie w)
{
	// TODO - implement Klient::dokonaj_platnosci
	throw "Not yet implemented";
}

void Klient::zwroc_pojazd(Wypozyczenie w)
{
	// TODO - implement Klient::zwroc_pojazd
	throw "Not yet implemented";
}
