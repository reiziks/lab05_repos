#include "pch.h"
#include "CppUnitTest.h"
#include "../lab5.3/lab5.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest5
{
    TEST_CLASS(UnitTest5)
    {
    public:

        // ---- гілка |x| >= 1 або x == 0: (cos^2 x + 1) / e^x ----

        TEST_METHOD(S_Zero)
        {
            Assert::AreEqual(2.0, s(0.0), 1e-9);
        }

        TEST_METHOD(S_One)
        {
            Assert::AreEqual(0.475273, s(1.0), 1e-6);
        }

        TEST_METHOD(S_MinusOne)
        {
            Assert::AreEqual(3.511821, s(-1.0), 1e-6);
        }

        TEST_METHOD(S_Two)
        {
            Assert::AreEqual(0.158772, s(2.0), 1e-6);
        }

        // ---- гілка |x| < 1, x != 0: сума ряду / sin(2x) ----

        TEST_METHOD(S_Half)
        {
            Assert::AreEqual(1.396603, s(0.5), 1e-6);
        }

        TEST_METHOD(S_MinusHalf_EvenFunction)
        {
            Assert::AreEqual(1.396603, s(-0.5), 1e-6);
            Assert::AreEqual(s(0.5), s(-0.5), 1e-12);
        }

        TEST_METHOD(S_Quarter)
        {
            Assert::AreEqual(1.086916, s(0.25), 1e-6);
        }

        TEST_METHOD(S_MinusZeroPointThree)
        {
            Assert::AreEqual(1.127534, s(-0.3), 1e-6);
        }

        TEST_METHOD(S_JustBelowOne_UsesSeriesBranch)
        {
            Assert::AreEqual(3.988571, s(0.999999), 1e-5);
        }

        // ---- вираз z(t) = s(2t+1) + 2*s(t^2) + sqrt(s(1)) ----

        TEST_METHOD(Z_AtZero)
        {
            double z = s(2 * 0.0 + 1) + 2 * s(0.0 * 0.0) + sqrt(s(1));
            Assert::AreEqual(5.164674, z, 1e-6);
        }

        TEST_METHOD(Z_AtMinusHalf)
        {
            double t = -0.5;
            double z = s(2 * t + 1) + 2 * s(t * t) + sqrt(s(1));
            Assert::AreEqual(4.863233, z, 1e-6);
        }

        TEST_METHOD(Z_AtOne)
        {
            double t = 1.0;
            double z = s(2 * t + 1) + 2 * s(t * t) + sqrt(s(1));
            Assert::AreEqual(1.738530, z, 1e-6);
        }
    };
}