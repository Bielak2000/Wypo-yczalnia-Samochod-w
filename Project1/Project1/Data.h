#ifndef DATA_H
#define DATA_H

class Data
{
private:
	int dzien;
	int miesiac;
	int rok;
	int godzina;

public:
	Data(int dzzien=0, int miiesiac=0, int rook=0, int goodzina=0);//konstruktor pleniacy rowniez role konstruktora domyslnego
	void zmien_date();//meotda do zmiany daty
	static bool czy_koliduje(Data zajety_od, Data zajety_do, Data termin_od, Data termin_do);

	//gettery 
	int get_dzien();
	int get_miesiac();
	int get_rok();
	int get_godzina();

	//settery
	void set_dzien(int dzienn);
	void set_miesiac(int miesiacc);
	void set_rok(int rokk);
	void set_godzina(int godzinaa);
};

#endif
