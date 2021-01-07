#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Data.h"
#include "../Project1/Data.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestZmienDate
{
	TEST_CLASS(TestZmienDate)
	{
	public:

		TEST_METHOD(ZmienDane)
		{
			int d = 10;
			int m = 10;
			int r = 2020;
			int g = 15;
			Data D(d, m, r, g);
			Assert::AreEqual(10, D.dzien);
			Assert::AreEqual(10, D.miesiac);
			Assert::AreEqual(2020, D.rok);
			Assert::AreEqual(15, D.godzina);
		}
	};
}
