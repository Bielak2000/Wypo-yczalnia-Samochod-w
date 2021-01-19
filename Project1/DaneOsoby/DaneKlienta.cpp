
#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Klient.h"
#include "../Project1/Klient.cpp"
#include "../Project1/Pojazd.h"
#include "../Project1/Pojazd.cpp"
#include "../Project1/Osoba.h"
#include "../Project1/Osoba.cpp"
#include "../Project1/Wypozyczenie.h"
#include "../Project1/Wypozyczenie.cpp"
#include "../Project1/Data.h"
#include "../Project1/Data.cpp"
#include "../Project1/Platnosc.h"
#include "../Project1/Platnosc.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace DaneKlienta
{
	TEST_CLASS(DaneKlienta)
	{
	public:
		
		TEST_METHOD(Dane_Klienta_sprawdzKonstKolejnosc)
		{
			string imie = "Jola";
			string nazw = "Brzeczyszczykiewicz";
			string pesel = "12345678901";
			string adres = "Warszawa, ul. Lajtowa 5";
			string numer = "123456789";

			Klient p(imie,nazw,pesel,adres,numer);

			Assert::AreEqual(p.get_imie(),imie);
			Assert::AreEqual(p.get_nazwisko(),nazw);
			Assert::AreEqual(p.get_pesel(), pesel);
			Assert::AreEqual(p.get_adres(), adres);
			Assert::AreEqual(p.get_numer_telefonu(), numer);
		}
	};
}
