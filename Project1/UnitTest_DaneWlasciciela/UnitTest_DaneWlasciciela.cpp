﻿#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Wlasciciel.h"
#include "../Project1/Wlasciciel.cpp"
#include "../Project1/Pracownik.h"
#include "../Project1/Pracownik.cpp"
#include "../Project1/Osoba.h"
#include "../Project1/Osoba.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestDaneWlasciciela
{
	TEST_CLASS(DaneWlasciciela)
	{
	public:
		
		TEST_METHOD(Dane_Wlasciciela_sprawdzPoprawnosc)
		{
			string imie = "Jan";
			string nazw = "Nowak";
			string pesel = "92839284782";
			string adres = "Warszawa, ul. Szkolna 5";
			string numer = "983290139";
			string haslo = "92839284782";
			string login = "JanNowak";

			Wlasciciel w;

			Assert::AreEqual(w.Imie, imie);
			Assert::AreEqual(w.Nazwisko, nazw);
			Assert::AreEqual(w.Pesel, pesel);
			Assert::AreEqual(w.Adres, adres);
			Assert::AreEqual(w.Numer_telefonu, numer);
			Assert::AreEqual(w.Login, login);
			Assert::AreEqual(w.Haslo, haslo);
		}
	};
}
