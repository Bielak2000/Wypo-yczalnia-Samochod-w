#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Pojazd.h"
#include "../Project1/Pojazd.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestZmienPrzebieg
{
	TEST_CLASS(TestZmienPrzebieg)
	{
	public:
		
		TEST_METHOD(TestZmienPrzebiegWPojazd)
		{
			Pojazd p;
			p.set_przebieg("22012");
			string km = "26000";
			p.zmien_przebieg(km);
			Assert::AreEqual(p.get_przebieg(), km);
		}
	};
}
