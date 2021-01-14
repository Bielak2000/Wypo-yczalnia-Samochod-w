#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Klient.h"
#include "../Project1/Klient.cpp"
#include "../Project1/Pojazd.h"
#include "../Project1/Pojazd.cpp"
#include "../Project1/Osoba.h"
#include "../Project1/Osoba.cpp"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestWypozyczPojazd
{
	TEST_CLASS(TestWypozyczPojazd)
	{
	public:
		
		TEST_METHOD(Wypozycz)
		{
			bool b = false;
			Pojazd p[2];
			p[0].Dostepny=1;
			p[0].Numer_rejestracyjny = "TEST123";
			Klient k("Adam", "Razowicz", "99462034626", "Krakow ul. Urzednicza 1", "362788473");
			b = k.wypozycz("TEST123", p);
			Assert::AreEqual(b, true);
		}
	};
}
