#include "pch.h"
#include "CppUnitTest.h"
#include "../lab5.1/lab5.1.cpp"   // підключаємо модуль із функцією g()

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
    TEST_CLASS(UnitTest2)
    {
    public:

        // g(2, 3, 1) = 2^2 + 3^2 - 1^2 = 4 + 9 - 1 = 12
        TEST_METHOD(TestG_Positive)
        {
            double t = g(2, 3, 1);
            Assert::AreEqual(12.0, t, 0.001);
        }

        // g(0, 0, 0) = 0
        TEST_METHOD(TestG_Zero)
        {
            double t = g(0, 0, 0);
            Assert::AreEqual(0.0, t, 0.001);
        }

        // g(1, -2, 3) = 1 + 4 - 9 = -4  (від'ємний результат та від'ємний аргумент)
        TEST_METHOD(TestG_Negative)
        {
            double t = g(1, -2, 3);
            Assert::AreEqual(-4.0, t, 0.001);
        }
    };
}