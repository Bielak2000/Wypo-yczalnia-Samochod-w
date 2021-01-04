#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Wypozyczenie.h"
#include "../Project1/Wypozyczenie.cpp"

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
			Assert::AreEqual(pesel, w.pesel);
		}
	};
}
