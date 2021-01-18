#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Wypozyczenie.h"
#include "../Project1/Wypozyczenie.cpp"
#include "../Project1/Data.h"
#include "../Project1/Data.cpp"
#include "../Project1/Platnosc.h"
#include "../Project1/Platnosc.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestPeselKlienta
{
	TEST_CLASS(TestPeselKlienta)
	{
	public:
		
		TEST_METHOD(Test_czy_dodano_poprawny_pesel)
		{
			string pesel = "00294291538";
			Wypozyczenie w;
			w.pesel_klienta(pesel);
			Assert::AreEqual(pesel, w.get_pesel());
		}
	};
}
