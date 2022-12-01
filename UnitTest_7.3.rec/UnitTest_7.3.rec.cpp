#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_7.3.rec/lab_7.3.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest73rec
{
	TEST_CLASS(UnitTest73rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int result;
			int i, j, s, s1;
			int a[3][3] = {
			  {1, 5, -8},
			  {2, 15, 7},
			  {3, 7, 9},
			};
			int* pa[3] = { a[0], a[1], a[2] };
			result = Sum(pa, 3, 3, 0, 0, 0, 0); ;
			Assert::AreEqual(result, 43);


		}
	};
}
