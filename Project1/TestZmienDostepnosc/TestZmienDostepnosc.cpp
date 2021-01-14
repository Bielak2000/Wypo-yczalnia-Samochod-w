#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Pojazd.h"
#include "../Project1/Pojazd.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestZmienDostepnosc
{
	TEST_CLASS(TestZmienDostepnosc)
	{
	public:
		
		TEST_METHOD(ZmianaDostepnosci)
		{
			Pojazd p;
			p.Dostepny = false;
			p.zmien_dostepnosc();
			Assert::AreEqual(p.Dostepny, true);
		}
	};
}
