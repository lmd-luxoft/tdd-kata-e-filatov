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
		char inputStr[] = "10,50,10";
		int result = 70;
		ASSERT_EQ(test_calc.Add(inputStr), result);//Результат вычислений
	}

	TEST(TestCalcTDD, TestFourParam) {
		Calculator test_calc;
		char inputStr[] = "10,50,10,130";
		int result = 200;
		ASSERT_EQ(test_calc.Add(inputStr), result);//Результат вычислений
	}

	TEST(TestCalcTDD, Test20Param) {
		Calculator test_calc;
		char inputStr[] = "10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10";
		int result = 200;
		ASSERT_EQ(test_calc.Add(inputStr), result); //Результат вычислений
	}

	TEST(TestCalcTDD, TestCorrectParamWithNExpression1) {
		Calculator test_calc;
		char inputStr[] = "1\n2,3";
		int result = 6;
		ASSERT_EQ(test_calc.Add(inputStr), result); //Результат вычислений
	}

	TEST(TestCalcTDD, TestCorrectParamWithNExpression2) {
		Calculator test_calc;
		char inputStr[] = "10,10,10,10,10\n10,10,10,10,10\n10,10,10,10,10,10,10,10,10,10";
		int result = 200;
		ASSERT_EQ(test_calc.Add(inputStr), result); //Результат вычислений
	}

	TEST(TestCalcTDD, TestIncorrectParamExpression1) {
		Calculator test_calc;
		char inputStr[] = "1,\n";
		int result = -3;
		ASSERT_EQ(test_calc.Add(inputStr), result); //-3 - Неверный формат строки
	}

	TEST(TestCalcTDD, TestIncorrectParamExpression2) {
		Calculator test_calc;
		char inputStr[] = "10,10,1\n,10,10\n10,10,1\n,10,10\n10,10,10,10,10,10,10,10,10,10";
		int result = -3;
		ASSERT_EQ(test_calc.Add(inputStr), result); //-3 - Неверный формат строки
	}

	TEST(TestCalcTDD, TestCorrectNewSemantic1) {
		Calculator test_calc;
		char inputStr[] = "//;\n10;10;10;10;10;10;10;10";
		int result = 80;
		ASSERT_EQ(test_calc.Add(inputStr), result); 
	}

	TEST(TestCalcTDD, TestCorrectNewSemantic2) {
		Calculator test_calc;
		char inputStr[] = "//!\n10!10!10!10!10!10!10!10";
		int result = 80;
		ASSERT_EQ(test_calc.Add(inputStr), result);
	} 

	TEST(TestCalcTDD, TestIncorrectNewSemantic1) {
		Calculator test_calc;
		char inputStr[] = "//;;\n10;;10;;10"; //Предположим, что по ТЗ сепатор сосотоит только из одного символа
		int result = -4;
		ASSERT_EQ(test_calc.Add(inputStr), result);
	}

	TEST(TestCalcTDD, TestIncorrectNewSemantic2) {
		Calculator test_calc;
		char inputStr[] = "//1\n1011011011011010110110"; //Числововой сепаратор недопустим
		int result = -4;
		ASSERT_EQ(test_calc.Add(inputStr), result);
	}

	TEST(TestCalcTDD, TestIncorrectNewSemantic3) {
		Calculator test_calc;
		char inputStr[] = "//;\n10!10!10"; //Неверный формат строки
		int result = -3;
		ASSERT_EQ(test_calc.Add(inputStr), result);
	}

	TEST(TestCalcTDD, TestIncorrectNewSemantic4) {
		Calculator test_calc;
		char inputStr[] = "/;\n10;10;10"; //Неверный формат строки, только один '/'
		int result = -3;
		ASSERT_EQ(test_calc.Add(inputStr), result);
	}

		


