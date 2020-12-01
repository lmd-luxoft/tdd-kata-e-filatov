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
#define SEPARATOR_DEFINEDER "//"
int Calculator::Add(char* expression)
{
    int cuttedNum = 0;
    int result = 0;
    int paramCount = 0;
    char firstNumChar[16];
    char* pos = 0;
    char separator = 0;
    
    if(!strlen(expression)) {
        return -1; //Пустая строка
    }

    const char* det = strstr(expression, "//");
    if(det == expression){
    //if (1 == strcmp(expression, SEPARATOR_DEFINEDER)) {
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

    sscanf(expression, "%d", &cuttedNum); //Взяли первый аргумент
    paramCount++;
    result += cuttedNum;

    do{
        if (strlen(++pos)) {
            if ((*pos < '0') || (*pos > '9')) {
                return -3; //Некорректная строка, после разделителя не число
            }
            sscanf(pos, "%d", &cuttedNum);
            result += cuttedNum;
            paramCount++;
        }
    } while (pos = strchr(pos, separator));

    if (paramCount<2) {
        return -2; //Недостаточно аргументов
    }

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
