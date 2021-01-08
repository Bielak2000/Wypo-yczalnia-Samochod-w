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
	Data(int d=0, int m=0, int r=0, int g=0);
	void zmien_date();
};

#endif
