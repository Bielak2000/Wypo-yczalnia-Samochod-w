#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Wlasciciel.h"
#include "../Project1/Wlasciciel.cpp"
#include "../Project1/Pracownik.h"
#include "../Project1/Pracownik.cpp"
#include "../Project1/Osoba.h"
#include "../Project1/Osoba.cpp"
#include "../Project1/Data.h"
#include "../Project1/Data.cpp"
#include "../Project1/Wypozyczenie.h"
#include "../Project1/Wypozyczenie.cpp"
#include "../Project1/Platnosc.h"
#include "../Project1/Platnosc.cpp"
#include "../Project1/Pojazd.h"
#include "../Project1/Pojazd.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestDaneWlasciciela
{
	TEST_CLASS(DaneWlasciciela)
	{
	public:
		
		TEST_METHOD(Dane_Wlasciciela_sprawdzPoprawnosc)
		{
			string im = "Jan";
			string nazw = "Nowak";
			string pes = "92839284782";
			string adr = "Warszawa, ul. Szkolna 5";
			string numer = "983290139";
			string has = "92839284782";
			string log = "JanNowak";

			Wlasciciel w;

			Assert::AreEqual(w.get_imie(), im);
			Assert::AreEqual(w.get_nazwisko(), nazw);
			Assert::AreEqual(w.get_pesel(), pes);
			Assert::AreEqual(w.get_adres(), adr);
			Assert::AreEqual(w.get_numer_telefonu(), numer);
			Assert::AreEqual(w.get_login(), log);
			Assert::AreEqual(w.get_haslo(), has);
		}
	};
}
