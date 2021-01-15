#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Pojazd.h"
#include "../Project1/Pojazd.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace TestZmienPrzebieg
{
	TEST_CLASS(TestZmienPrzebieg)
	{
	public:
		
		TEST_METHOD(TestZmienPrzebiegWPojazd)
		{
			string kmo = "26000";
			Pojazd p;
			p.zmien_przebieg(kmo);
			Assert::AreEqual(p.get_przebieg(), kmo);
		}
	};
}
