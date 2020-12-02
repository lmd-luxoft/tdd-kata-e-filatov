#include "pch.h"
#include "Calculator.h"

int Calculator::Add(std::string expression)
{
    return 0;
}

/*
* @result
* >=0 - result of operation
* -1 - Empty expression
* -2 - Less argument`s count
* -3 - Incorrect input string
* -4 - Incorrect separator
*/
int Calculator::Add(char* in_expression)
{
    int cuttedNum = 0;
    int result = 0;
    int paramCount = 0;
    char expression_copy [256];
    char* expression = expression_copy;
    char* pos = 0;
    char separator = 0;

    strcpy(expression, in_expression);
    
    if(!strlen(expression)) {
        return -1; //Пустая строка
    }

    const char* det = strstr(expression, "//");
    if(det == expression){
        if (expression[3] == '\n') {
            separator = expression[2];
            if ((separator < '0') || (separator > '9')) {
                expression = &expression[4];
                pos = expression;
            }
            else {
                return -4;
            }
        }
        else {
            return -4;
        }
    }
    else {
        pos = expression;
        while (pos = strchr(pos, '\n')) {
            *pos = ',';
        }
        separator = ',';
    }

    if (CheckStringOnIncorrectSymbols(expression, separator)) {
        return -3;
    }

    pos = strchr(expression, separator);
    if (!pos) {
        return -2; //Не найден разделитель - недостаточно агрументов
    }
    if (pos == expression) {
        return -2; //Нет первого аргумента
    }

    result = CalculateExpressionSum(expression, separator);

    //delete expression;

    return result;
}

int Calculator::CheckStringOnIncorrectSymbols(char* input, char separator) {
    do{
        if (((*input < '0') || (*input > '9')) && (*input != separator)) {
            return 1;
        }
        input++;
    } while (*input);
}

int Calculator::CalculateExpressionSum(char* input, char separator) {
    int result = 0;
    int cuttedNum = 0;
    int paramCount = 0;

    do {
        if (paramCount) {
            input++;
        }
        if ((*input < '0') || (*input > '9')) {
            return -3; //Некорректная строка, после разделителя не число
        }
        sscanf(input, "%d", &cuttedNum); //Взяли аргумент
        paramCount++;
        result += cuttedNum;
    } while (input = strchr(input, separator));

    if (paramCount < 2) {
        return -2; //Недостаточно аргументов
    }

    return result;
}
