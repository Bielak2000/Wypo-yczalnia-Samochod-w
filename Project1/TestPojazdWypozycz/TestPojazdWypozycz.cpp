#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Pojazd.h"
#include "../Project1/Pojazd.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestPojazdWypozycz
{
	TEST_CLASS(TestPojazdWypozycz)
	{
	public:
		
		TEST_METHOD(Pojazd_Wypozycz)
		{
			Pojazd p;
			p.set_dostepny(true);
			p.wypozycz();
			Assert::AreEqual(p.get_dostepnosc(), false);
		}
	};
}
