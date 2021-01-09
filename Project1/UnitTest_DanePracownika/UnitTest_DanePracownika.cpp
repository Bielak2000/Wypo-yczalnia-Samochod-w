#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Pracownik.h"
#include "../Project1/Pracownik.cpp"
#include "../Project1/Osoba.h"
#include "../Project1/Osoba.cpp"
#include "../Project1/Data.h"
#include "../Project1/Data.cpp"
#include "../Project1/Wypozyczenie.h"
#include "../Project1/Wypozyczenie.cpp"

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

			Assert::AreEqual(p.get_imie(), imie);
			Assert::AreEqual(p.get_nazwisko(), nazw);
			Assert::AreEqual(p.Osoba::get_pesel(), pesel);
			Assert::AreEqual(p.get_adres(), adres);
			Assert::AreEqual(p.get_numer_telefonu(), numer);
			Assert::AreEqual(p.get_login(), imie + nazw);
			Assert::AreEqual(p.get_haslo(), pesel);
		}
	};
}
