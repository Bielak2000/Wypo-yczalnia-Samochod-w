#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Data.h"
#include "../Project1/Data.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestDataKolidowanie
{
	TEST_CLASS(UnitTestDataKolidowanie)
	{
	public:
		
		TEST_METHOD(Czy_Metoda_Sprawdzajaca_Kolidowanie_Dat_DzialaPoprawnie)
		{
			Data d1(10,1,2021,15);
			Data d2(10,3,2021,15);		//nie kolidujace miesiace
			Data d3(12,4,2021,13);
			Data d4(15,6,2021,18);
			Assert::AreEqual(Data::czy_koliduje(d1, d2, d3, d4), false);	//nie koliduje

			Data d5(10, 1, 2021, 15);
			Data d6(11, 3, 2021, 18);	//kolidujace miesiace, nie kolidujace dni		
			Data d7(12, 3, 2021, 13);
			Data d8(15, 6, 2021, 18);
			Assert::AreEqual(Data::czy_koliduje(d5, d6, d7, d8), false);	//nie koliduje

			Data d11(9, 4, 2021, 15);
			Data d21(10, 4, 2021, 15);	//wszystkie miesiace kolidujace, nie kolidujace dni
			Data d31(11, 4, 2021, 13);
			Data d41(15, 4, 2021, 18);
			Assert::AreEqual(Data::czy_koliduje(d11, d21, d31, d41), false);	//nie koliduje


			Data d12(10, 1, 2021, 15);
			Data d22(10, 4, 2021, 14);	//kolidujace dni (te same daty rozpoczecia)
			Data d32(10, 1, 2021, 13);
			Data d42(15, 6, 2021, 18);
			Assert::AreEqual(Data::czy_koliduje(d12, d22, d32, d42), true);	//koliduje

			Data d13(10, 1, 2021, 15);
			Data d23(21, 3, 2021, 15);	//kolidujace miesiace i dni
			Data d33(21, 3, 2021, 13);
			Data d43(15, 6, 2021, 18);
			Assert::AreEqual(Data::czy_koliduje(d13, d23, d33, d43), true);	//koliduje


			Data d14(10, 3, 2021, 15);
			Data d24(13, 3, 2021, 15);	//wszystkie misiace kolidujace, kolidujace dni
			Data d34(12, 3, 2021, 13);
			Data d44(15, 3, 2021, 18);
			Assert::AreEqual(Data::czy_koliduje(d14, d24, d34, d44), true);	//koliduje
		}
	};
}
