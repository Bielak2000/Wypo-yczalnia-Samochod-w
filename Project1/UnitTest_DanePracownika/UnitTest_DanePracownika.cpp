#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Pracownik.h"
#include "../Project1/Pracownik.cpp"
#include "../Project1/Osoba.h"
#include "../Project1/Osoba.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestDanePracownika
{
	TEST_CLASS(UnitTestDanePracownika)
	{
	public:
		
		TEST_METHOD(Dane_Pracownika_sprawdzKonstKolejnosc)
		{
			string imie = "Pracownik";
			string nazw = "Superpracownikalski";
			string pesel = "99999999999";
			string adres = "Pracownikowo, ul. pracownicza 2";
			string numer = "983290139";

			Pracownik p(imie, nazw, pesel, adres, numer);

			Assert::AreEqual(p.Imie, imie);
			Assert::AreEqual(p.Nazwisko, nazw);
			Assert::AreEqual(p.Pesel, pesel);
			Assert::AreEqual(p.Adres, adres);
			Assert::AreEqual(p.Numer_telefonu, numer);
			Assert::AreEqual(p.Login, imie + nazw);
			Assert::AreEqual(p.Haslo, pesel);
		}
	};
}
