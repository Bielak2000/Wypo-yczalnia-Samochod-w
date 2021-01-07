#ifndef DATA_H
#define DATA_H

class Data
{

public:
	int dzien;
	int miesiac;
	int rok;
	int godzina;

public:
	Data(int d, int m, int r, int g);
	void zmien_date(int d1, int m1, int r1, int g1);
};

#endif
