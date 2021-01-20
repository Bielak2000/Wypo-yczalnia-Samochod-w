#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/wypozyczenie.h"
#include "../Project1/Wypozyczenie.cpp"
#include "../Project1/Data.h"
#include "../Project1/Data.cpp"
#include "../Project1/Platnosc.h"
#include "../Project1/Platnosc.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestWydluzOkres
{
	TEST_CLASS(TestWydluzOkres)
	{
	public:
		
		TEST_METHOD(TestWydluzWypozyczenie)
		{
			Wypozyczenie w;
			w.get_data_do().set_dzien(1);
			w.get_data_do().set_miesiac(1);
			w.get_data_do().set_rok(1);
			w.get_data_do().set_godzina(1);
			Data d;
			d.set_dzien(21);
			d.set_miesiac(11);
			d.set_rok(2030);
			d.set_godzina(19);
			w.wydluz_okres(d);
			Assert::AreEqual(w.get_data_do().get_dzien(), 21);
			Assert::AreEqual(w.get_data_do().get_miesiac(), 11);
			Assert::AreEqual(w.get_data_do().get_rok(), 2030);
			Assert::AreEqual(w.get_data_do().get_godzina(), 19);
		}
	};
}
