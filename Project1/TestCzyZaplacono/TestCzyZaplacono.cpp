#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Platnosc.h"
#include "../Project1/Platnosc.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestCzyZaplacono
{
	TEST_CLASS(TestCzyZaplacono)
	{
	public:

		TEST_METHOD(CzyZaplacono)
		{
			Platnosc p;
			p.set_potwierdzenie(true);
			Assert::AreEqual(p.czy_zaplacono(), true);
		}
	};
}
