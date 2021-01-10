#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Pojazd.h"
#include "../Project1/Pojazd.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestDanePojazduPlik
{
	TEST_CLASS(UnitTestDanePojazduPlik)
	{
	public:
		
		TEST_METHOD(TestDzialaniaZapisywaniaPliku)
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

			Pojazd p1(nr,rodz,mar,mod,r,sil,przeb,cen,dost);
			p1.aktualizuj_plik();
		}
	};
}
