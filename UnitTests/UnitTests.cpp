#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\headn\Desktop\New folder (5)\Labs 4 HURAY\ConsoleApplication1\ConsoleApplication1\logic.h"
#include "C:\Users\headn\Desktop\New folder (5)\Labs 4 HURAY\ConsoleApplication1\ConsoleApplication1\InputN.h"
#include "C:\Users\headn\Desktop\New folder (5)\Labs 4 HURAY\ConsoleApplication1\ConsoleApplication1\InputRange.h"
#include "C:\Users\headn\Desktop\New folder (5)\Labs 4 HURAY\ConsoleApplication1\ConsoleApplication1\InputStep.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestss
{
	TEST_CLASS(CalculationTest){
	public:
        TEST_METHOD(TestNegativeX_n2_x_minus1){
            double x = -1.0;
            int n = 2;
            double expected = 0.3533333;
            double actual = calculateY(x, n);
            Assert::AreEqual(expected, actual, 0.0001, L"Test failed for x = -1, n = 2");
        }
        TEST_METHOD(TestPositiveX_n4_x1){
            double x = 1.0;
            int n = 4;
            double expected = -16040.675;
            double actual = calculateY(x, n);
            Assert::AreEqual(expected, actual, 0.0001, L"Test failed for x = 1, n = 4");
        }
        TEST_METHOD(TestZeroX_n3_x0){
            double x = 0.0;
            int n = 3;
            double expected = -1915.0;
            double actual = calculateY(x, n);
            Assert::AreEqual(expected, actual, 0.0001, L"Test failed for x = 0, n = 3");
        }
	};
    TEST_CLASS(InputNTests) {
    public:
        TEST_METHOD(TestInputN_FailsFor_Double){
            double test_val = 2.5;
            Assert::ExpectException<std::invalid_argument>([&]() { ValidateN(test_val); }, L"Test failed for n = 2.5");
        }
        TEST_METHOD(TestInputN_FailsFor_One) {
            double test_val = 1.0;
            Assert::ExpectException<std::invalid_argument>([&]() { ValidateN(test_val); }, L"Test failed for n = 1.0");
        }
        TEST_METHOD(TestInputN_FailsFor_Zero){
            double test_val = 0.0;
            Assert::ExpectException<std::invalid_argument>([&]() { ValidateN(test_val); }, L"Test failed for n = 0");
        }
        TEST_METHOD(TestInputN_PassesFor_Four) {
            double test_val = 4.0;
            int expected = 4;
            int actual = ValidateN(test_val);
            Assert::AreEqual(expected, actual, L"Test failed for n = 4");
        }
    };
    TEST_CLASS(InputRangeTests){
    public:
        TEST_METHOD(TestValidateRange_FailsWhen_A_greater_B){
            double a = 10.0;
            double b = 5.0;
            Assert::ExpectException<std::invalid_argument>([&]() {ValidateRange(a, b);}, L"Test failed due to a > b");
        }
        TEST_METHOD(TestValidateRange_PassesWhen_A_less_B){
            double a = 5.0;
            double b = 10.0;
            ValidateRange(a, b);
        }
        TEST_METHOD(TestValidateRange_PassesWhen_A_equals_B){
            double a = 5.0;
            double b = 5.0;
            ValidateRange(a, b);
        }
    };
    TEST_CLASS(InputStepTests){
    public:
        TEST_METHOD(TestValidateStep_Fails_0){
            double step = 0;
            Assert::ExpectException<std::invalid_argument>([&]() {ValidateStep(step); }, L"Test failed due to step=0");
        }
        TEST_METHOD(TestValidateStep_Fails_Negativ){
            double step = -8.0;
            Assert::ExpectException<std::invalid_argument>([&]() {ValidateStep(step); }, L"Test failed due to step<0");
        }
        TEST_METHOD(TestValidateStep_Passes){
            double step = 10.5;
            ValidateStep(step);
        }
    };
}
