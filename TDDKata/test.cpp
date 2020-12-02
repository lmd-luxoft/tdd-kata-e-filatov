#include "pch.h"
#include "Calculator.h"
#include "TestFixture.h"
#include "TestFixtureWithParam.h"

	//Simple test
	TEST(TestCalcTDD, TestZero) {
		Calculator test_calc;
		ASSERT_EQ(test_calc.Add("0,10"), 10); //Результат вычислений
	}

	//Simple test with fixture
	TEST_F(TestFixture, TestEmptyString) {
		char input [] = "";
		int result = test_calc->Add(input);
		ASSERT_EQ(result, -1); //Код ошибки -1 - пустая строка
	}

	//Multi-test with using fixture & params
	//Main idea - isung test cases from external sources
	TEST_P(TestFixtureWithParam, MultiTest) {
		char* input = GetParam()._input;
		int excepted_result = GetParam()._result;
		int actual_result = test_calc->Add(input);
		ASSERT_EQ(excepted_result, actual_result);
	}
