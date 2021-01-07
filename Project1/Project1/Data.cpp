#include <iostream>
#include "Data.h"

using namespace std;

Data::Data(int d, int m, int r, int g)
{
	dzien = d;
	miesiac = m;
	rok = r;
	godzina = g;
}

void Data::zmien_date(int d1, int m1, int r1, int g1)
{
	dzien = d1;
	miesiac = m1;
	rok = r1;
	godzina = g1;
}
