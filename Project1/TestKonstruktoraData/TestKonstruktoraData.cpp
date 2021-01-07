#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Data.h"
#include "../Project1/Data.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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

			Data d(d, m, r, g);

			Assert::AreEqual(d.dzien, d);
			Assert::AreEqual(d.miesiac, m);
			Assert::AreEqual(d.rok, r);
			Assert::AreEqual(d.godzina, g);
		}
	};
}
