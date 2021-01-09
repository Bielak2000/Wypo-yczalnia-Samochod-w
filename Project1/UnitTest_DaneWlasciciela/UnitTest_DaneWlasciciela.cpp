#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Wlasciciel.h"
#include "../Project1/Wlasciciel.cpp"
#include "../Project1/Pracownik.h"
#include "../Project1/Pracownik.cpp"

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
			string has = "LAB01";
			string log = "JanNowak";

			Wlasciciel w;

			Assert::AreEqual(w.Imie, im);
			Assert::AreEqual(w.Nazwisko, nazw);
			Assert::AreEqual(w.Pesel, pes);
			Assert::AreEqual(w.Adres, adr);
			Assert::AreEqual(w.Numer_telefonu, numer);
			Assert::AreEqual(w.Login, log);
			Assert::AreEqual(w.Haslo, has);
		}
	};
}
