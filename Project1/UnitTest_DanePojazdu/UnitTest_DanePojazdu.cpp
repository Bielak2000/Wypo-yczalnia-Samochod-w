#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Pojazd.h"
#include "../Project1/Pojazd.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestDanePojazdu
{
	TEST_CLASS(UnitTestDanePojazdu)
	{
	public:
		
		TEST_METHOD(Test_get_i_konstruktora)
		{
			string nr = "XX123";
			string rodz = "sam";
			string mar = "Subaru";
			string mod = "XV";
			int r = 2020;
			string sil = "SUPERSILNIK";
			string przeb = "300km";
			int cen = 250;
			bool dost = true;

			Pojazd p1(nr, rodz, mar, mod, r, sil, przeb, cen, dost);

			Assert::AreEqual(p1.get_numer_rejestracyjny(), nr);
			Assert::AreEqual(p1.get_rodzaj(), rodz);
			Assert::AreEqual(p1.get_marka(), mar);
			Assert::AreEqual(p1.get_rok(), r);
			Assert::AreEqual(p1.get_silnik(), sil);
			Assert::AreEqual(p1.get_przebieg(), sil);
			Assert::AreEqual(p1.get_cena_za_godzine(), cen);
			Assert::AreEqual(p1.get_dostepnosc(), dost);
		}
	};
}
