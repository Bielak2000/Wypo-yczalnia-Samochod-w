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
	Data(int d=0, int m=0, int r=0, int g=0);
	void zmien_date();
	static bool czy_koliduje(Data zajetyOd, Data zajetyDo, Data terminOd, Data terminDo);
	int get_dzien();
	int get_miesiac();
	int get_rok();
	int get_godzina();

	void set_dzien(int d);
	void set_miesiac(int m);
	void set_rok(int r);
	void set_godzina(int g);
};

#endif
