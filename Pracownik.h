#ifndef PRACOWNIK_H
#define PRACOWNIK_H

class Pracownik : Osoba
{


public:
	boolean zatwierdz_wypozyczenie(string nr, string pesel);

	boolean zatwierdz_zwrot(string nr, string pesel);

	void zarzadzaj_wypozyczeniem(string pesel, string nr);
};

#endif
