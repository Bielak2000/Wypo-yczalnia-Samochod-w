#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Klient.h"
//#include "../Project1/Klient.cpp"

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

			Assert::AreEqual(p.Imie,imie);
			Assert::AreEqual(p.Nazwisko,nazw);
			Assert::AreEqual(p.Pesel, pesel);
			Assert::AreEqual(p.Adres, adres);
			Assert::AreEqual(p.Numer_telefonu, numer);
		}
	};
}
