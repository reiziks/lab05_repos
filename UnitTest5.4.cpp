// Unit-тест до завдання № 5.4 (варіант 27)
// Native Unit Test Project (Visual Studio).
// Шлях у #include вкажіть відповідно до назви вашого проекту з 5.4
// (у посібнику: #include "../Project7/Source.cpp").

#include "pch.h"
#include "CppUnitTest.h"
#include "../lab5.4/lab5.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest54
{
    TEST_CLASS(UnitTest54)
    {
    public:
        const double eps = 1e-9;

        // сума i^2 для i = 1..10 дорівнює 385, знаменник 1 + 100 = 101
        TEST_METHOD(Iterative_K1_N10)
        {
            Assert::AreEqual(385. / 101., S0(1, 10), eps);
        }

        // один доданок: N^2 / (N^2 + N^2) = 0.5
        TEST_METHOD(SingleTerm_K_equals_N)
        {
            Assert::AreEqual(0.5, S0(3, 3), eps);
            Assert::AreEqual(0.5, S1(3, 3, 3, 0), eps);
            Assert::AreEqual(0.5, S2(3, 3, 3, 0), eps);
            Assert::AreEqual(0.5, S3(3, 3, 3), eps);
            Assert::AreEqual(0.5, S4(3, 3, 3), eps);
        }

        // від'ємне K: i = -2..4, сума i^2 = 35, знаменник 4 + 16 = 20
        TEST_METHOD(NegativeK)
        {
            const double expected = 35. / 20.;
            Assert::AreEqual(expected, S0(-2, 4), eps);
            Assert::AreEqual(expected, S1(-2, 4, -2, 0), eps);
            Assert::AreEqual(expected, S2(-2, 4, 4, 0), eps);
            Assert::AreEqual(expected, S3(-2, 4, -2), eps);
            Assert::AreEqual(expected, S4(-2, 4, 4), eps);
        }

        // усі рекурсивні способи збігаються з ітераційним
        TEST_METHOD(AllMethodsAgree)
        {
            const int K[] = { 1, 0, 2, -5, 7 };
            const int N[] = { 10, 6, 2, 5, 20 };
            for (int j = 0; j < 5; j++)
            {
                const double s0 = S0(K[j], N[j]);
                Assert::AreEqual(s0, S1(K[j], N[j], K[j], 0), eps);
                Assert::AreEqual(s0, S2(K[j], N[j], N[j], 0), eps);
                Assert::AreEqual(s0, S3(K[j], N[j], K[j]), eps);
                Assert::AreEqual(s0, S4(K[j], N[j], N[j]), eps);
            }
        }

        // порожній діапазон (K > N) – сума дорівнює 0
        TEST_METHOD(EmptyRange)
        {
            Assert::AreEqual(0., S0(5, 3), eps);
            Assert::AreEqual(0., S1(5, 3, 5, 0), eps);
            Assert::AreEqual(0., S2(5, 3, 3, 0), eps);
            Assert::AreEqual(0., S3(5, 3, 5), eps);
            Assert::AreEqual(0., S4(5, 3, 3), eps);
        }
    };
}