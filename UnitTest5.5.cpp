

#include "pch.h"
#include "CppUnitTest.h"
#include "../lab5.5/lab5.5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest55
{
    TEST_CLASS(UnitTest55)
    {
    public:
        // допоміжна функція: C(n, k) і глибина рекурсії
        static int Binom(int n, int k, int& depth)
        {
            depth = 0;
            return C(n, k, 1, depth);
        }

        TEST_METHOD(Value_5_2)
        {
            int depth;
            Assert::AreEqual(10, Binom(5, 2, depth));
        }

        TEST_METHOD(Value_6_3)
        {
            int depth;
            Assert::AreEqual(20, Binom(6, 3, depth));
        }

        TEST_METHOD(Value_10_4)
        {
            int depth;
            Assert::AreEqual(210, Binom(10, 4, depth));
        }

        // базові випадки: k = 0 та k = n дають 1 без рекурсивних викликів
        TEST_METHOD(BaseCases)
        {
            int depth;
            Assert::AreEqual(1, Binom(7, 0, depth));
            Assert::AreEqual(1, depth);
            Assert::AreEqual(1, Binom(7, 7, depth));
            Assert::AreEqual(1, depth);
            Assert::AreEqual(1, Binom(0, 0, depth));
            Assert::AreEqual(1, depth);
        }

        // симетрія: C(n, k) = C(n, n - k)
        TEST_METHOD(Symmetry)
        {
            int d1, d2;
            for (int n = 0; n <= 10; n++)
                for (int k = 0; k <= n; k++)
                    Assert::AreEqual(Binom(n, k, d1), Binom(n, n - k, d2));
        }

        // порівняння з формулою n! / (k! (n-k)!)
        TEST_METHOD(AgainstFactorialFormula)
        {
            int fact[11] = { 1 };
            for (int i = 1; i <= 10; i++)
                fact[i] = fact[i - 1] * i;

            int depth;
            for (int n = 0; n <= 10; n++)
                for (int k = 0; k <= n; k++)
                    Assert::AreEqual(fact[n] / (fact[k] * fact[n - k]),
                        Binom(n, k, depth));
        }

        // глибина рекурсії: n при 0 < k < n, та 1 при k = 0 або k = n
        TEST_METHOD(Depth)
        {
            int depth;
            Binom(4, 2, depth);
            Assert::AreEqual(4, depth);
            Binom(5, 2, depth);
            Assert::AreEqual(5, depth);
            Binom(10, 4, depth);
            Assert::AreEqual(10, depth);
            Binom(6, 6, depth);
            Assert::AreEqual(1, depth);
        }
    };
}