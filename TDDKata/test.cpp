#include "pch.h"
#include "Calculator.h"
Calculator test_calc;
	TEST(TestCalcTDD, TestEmptyString) {
		ASSERT_EQ(test_calc.Add(""), -1); //Код ошибки -1 - пустая строка
	}

	TEST(TestCalcTDD, TestZero) {
		ASSERT_EQ(test_calc.Add("0,10"), 10); //Результат вычислений
	}

	TEST(TestCalcTDD, TestCorrectExpression1) {
		ASSERT_EQ(test_calc.Add("7456,55"), 7511); //Результат вычислений
	}

	TEST(TestCalcTDD, TestCorrectExpression) {
		ASSERT_EQ(test_calc.Add("34,5623345"), 5623379); //Результат вычислений
	}

	TEST(TestCalcTDD, TestEmptyFirstArgument) {
		ASSERT_EQ(test_calc.Add(",55"), -2); //Код ошибки -2 - недостаточно аргументов
	}

	TEST(TestCalcTDD, TestEmptySecondArgument) {
		ASSERT_EQ(test_calc.Add("10,"), -2); //Код ошибки -1 - недостаточно аргументов
	}
