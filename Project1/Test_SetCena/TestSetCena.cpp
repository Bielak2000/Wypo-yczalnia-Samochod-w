#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Platnosc.h"
#include "../Project1/Platnosc.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestSetCena
{
	TEST_CLASS(TestSetCena)
	{
	public:
		
		TEST_METHOD(TestUstawCene)
		{
			Platnosc p;
			int cena = 200;
			p.set_kwota(cena);
			Assert::AreEqual(p.get_kwota(), cena);
		}
	};
}
