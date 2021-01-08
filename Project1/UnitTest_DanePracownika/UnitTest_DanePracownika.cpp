#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Pracownik.h"
#include "../Project1/Pracownik.cpp"

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
			string haslo = "pracowniczka123";
			string login = "PracownikMiesiaca";

			Pracownik w(string imie, string nazw, string pesel, string adres, string numer);

			Assert::AreEqual(w.Imie, imie);
			Assert::AreEqual(w.Nazwisko, nazw);
			Assert::AreEqual(w.Pesel, pesel);
			Assert::AreEqual(w.Adres, adres);
			Assert::AreEqual(w.Numer_telefonu, numer);
			Assert::AreEqual(w.Login, imie+nazw);
			Assert::AreEqual(w.Haslo, pesel);
		}
	};
}
