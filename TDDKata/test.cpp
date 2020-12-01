#include "pch.h"
#include "Calculator.h"

	TEST(TestCalcTDD, TestEmptyString) {
		Calculator test_calc;
		ASSERT_EQ(test_calc.Add(""), -1); //Код ошибки -1 - пустая строка
	}

	TEST(TestCalcTDD, TestZero) {
		Calculator test_calc;
		ASSERT_EQ(test_calc.Add("0,10"), 10); //Результат вычислений
	}

	TEST(TestCalcTDD, TestCorrectExpression1) {
		Calculator test_calc;
		ASSERT_EQ(test_calc.Add("7456,55"), 7511); //Результат вычислений
	}

	TEST(TestCalcTDD, TestCorrectExpression) {
		Calculator test_calc;
		ASSERT_EQ(test_calc.Add("34,5623345"), 5623379); //Результат вычислений
	}

	TEST(TestCalcTDD, TestEmptyFirstArgument) {
		Calculator test_calc;
		ASSERT_EQ(test_calc.Add(",55"), -2); //Код ошибки -2 - недостаточно аргументов
	}

	TEST(TestCalcTDD, TestEmptySecondArgument) {
		Calculator test_calc;
		ASSERT_EQ(test_calc.Add("10,"), -2); //Код ошибки -2 - недостаточно аргументов
	}

	TEST(TestCalcTDD, TestThreeParam) {
		Calculator test_calc;
		ASSERT_EQ(test_calc.Add("10,50,10"), 70); //Результат вычислений
	}

	TEST(TestCalcTDD, TestFourParam) {
		Calculator test_calc;
		ASSERT_EQ(test_calc.Add("10,50,10,130"), 200); //Результат вычислений
	}

	TEST(TestCalcTDD, TestRandomOf100Param) {
		Calculator test_calc;
		int countParam = 4 + rand()%96;
		std::cout << "Random Count = " << countParam;
		char inputStr[300]; //Максимальная длина строки
		int summaryResult = 0;
		char* ptr = inputStr;
		for (int i = 0; i < countParam; i++) {
			int randomNum = rand() % 99;
			summaryResult += randomNum;
			sprintf(ptr, "%d,", randomNum);
			ptr = strchr(ptr, ',') + 1;
		}
		*(ptr-1) = '\0';
		ASSERT_EQ(test_calc.Add(inputStr), summaryResult); //Результат вычислений
	}
