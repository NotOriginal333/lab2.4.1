#include "pch.h"
#include "CppUnitTest.h"
#include "../lab2.4.1/Matrix.h"
#include "../lab2.4.1/Matrix.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Matrix matrix1(3);
			matrix1[0][0] = 1;
			int element = matrix1[0][0];
			Assert::AreEqual(1, element);
		}
	};
}
