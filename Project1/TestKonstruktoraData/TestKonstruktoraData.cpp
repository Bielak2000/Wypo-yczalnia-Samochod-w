#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Data.h"
#include "../Project1/Data.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace TestKonstruktoraData
{
	TEST_CLASS(TestKonstruktoraData)
	{
	public:
		
		TEST_METHOD(KonstruktorData)
		{
			int d = 10;
			int m = 10;
			int r = 2020;
			int g = 15;

			Data D(d, m, r, g);

			Assert::AreEqual(D.get_dzien(), d);
			Assert::AreEqual(D.get_miesiac(), m);
			Assert::AreEqual(D.get_rok(), r);
			Assert::AreEqual(D.get_godzina(), g);

		}
	};
}
