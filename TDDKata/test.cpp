#include "pch.h"
#include "Calculator.h"

	TEST(TestCalcTDD, TestEmptyString) {
		Calculator test_calc;
		ASSERT_EQ(test_calc.Add(""), -1); //��� ������ -1 - ������ ������
	}

	TEST(TestCalcTDD, TestZero) {
		Calculator test_calc;
		ASSERT_EQ(test_calc.Add("0,10"), 10); //��������� ����������
	}

	TEST(TestCalcTDD, TestCorrectExpression1) {
		Calculator test_calc;
		ASSERT_EQ(test_calc.Add("7456,55"), 7511); //��������� ����������
	}

	TEST(TestCalcTDD, TestCorrectExpression) {
		Calculator test_calc;
		ASSERT_EQ(test_calc.Add("34,5623345"), 5623379); //��������� ����������
	}

	TEST(TestCalcTDD, TestEmptyFirstArgument) {
		Calculator test_calc;
		ASSERT_EQ(test_calc.Add(",55"), -2); //��� ������ -2 - ������������ ����������
	}

	TEST(TestCalcTDD, TestEmptySecondArgument) {
		Calculator test_calc;
		ASSERT_EQ(test_calc.Add("10,"), -2); //��� ������ -2 - ������������ ����������
	}
