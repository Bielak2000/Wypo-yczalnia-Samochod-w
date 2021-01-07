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
			Data d(10, 10, 2020, 15);
			d.zmien_date(12, 12, 2021, 14);
			Assert::AreEqual(12, d.dzien);
			Assert::AreEqual(12, d.miesiac);
			Assert::AreEqual(2021, d.rok);
			Assert::AreEqual(14, d.godzina);
		}
	};
}
