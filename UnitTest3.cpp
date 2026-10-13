#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>
#include "../lab5.2/lab5.2.cpp"   // шлях до вашого проєкту

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SeriesTests
{
    TEST_CLASS(SeriesTests)
    {
    public:

        // ---------- Функція A ----------

        TEST_METHOD(A_FirstStep_GivesX3Over3)
        {
            double x = 0.5;
            double a = -x;          // перший доданок
            A(x, 1, a);             // має бути x^3 / 3
            Assert::AreEqual(std::pow(x, 3) / 3, a, 1e-12);
        }

        TEST_METHOD(A_SecondStep_GivesMinusX5Over5)
        {
            double x = 0.5;
            double a = std::pow(x, 3) / 3;
            A(x, 2, a);             // має бути -x^5 / 5
            Assert::AreEqual(-std::pow(x, 5) / 5, a, 1e-12);
        }

        TEST_METHOD(A_ZeroX_StaysZero)
        {
            double a = 0.0;
            A(0.0, 3, a);
            Assert::AreEqual(0.0, a, 1e-15);
        }

        // ---------- Функція S ----------

        TEST_METHOD(S_ZeroX_ReturnsHalfPiAndOneIteration)
        {
            int n = -1;
            double s = 0;
            S(0.0, 1e-4, n, s);
            Assert::AreEqual(PI / 2, s, 1e-12);
            Assert::AreEqual(1, n);
        }

        TEST_METHOD(S_KnownCase_X05_Eps1e4_GivesN5)
        {
            int n = 0;
            double s = 0;
            S(0.5, 1e-4, n, s);
            Assert::AreEqual(5, n);
            Assert::AreEqual(PI / 2 - std::atan(0.5), s, 1e-4);
        }

        TEST_METHOD(S_MatchesArcctg_ForSeveralX)
        {
            const double eps = 1e-5;
            const double xs[] = { -1.0, -0.7, -0.3, 0.1, 0.5, 0.9, 1.0 };

            for (double x : xs)
            {
                int n = 0;
                double s = 0;
                S(x, eps, n, s);
                Assert::AreEqual(PI / 2 - std::atan(x), s, eps);
            }
        }

        TEST_METHOD(S_SmallerEps_NeedsMoreOrEqualTerms)
        {
            int n1 = 0, n2 = 0;
            double s1 = 0, s2 = 0;
            S(0.8, 1e-2, n1, s1);
            S(0.8, 1e-6, n2, s2);
            Assert::IsTrue(n2 > n1);
        }

        TEST_METHOD(S_Symmetry_SOfMinusXEqualsPiMinusSOfX)
        {
            const double eps = 1e-6;
            int n = 0;
            double sPos = 0, sNeg = 0;
            S(0.6, eps, n, sPos);
            S(-0.6, eps, n, sNeg);
            Assert::AreEqual(PI - sPos, sNeg, 2 * eps);
        }
    };
}