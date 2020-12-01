#include "pch.h"
#include "Calculator.h"

int Calculator::Add(std::string expression)
{
    return 0;
}

int Calculator::Add(char* expression)
{
    int cuttedNum = 0;
    int result = 0;
    int paramCount = 0;
    char firstNumChar[16];
    
    if (!strlen(expression)) {
        return -1; //Пустая строка
    }
    char* pos = expression;
    while (pos = strchr(pos, '\n')) {
        *pos = ',';
    }

    pos = strchr(expression, ',');
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
    } while (pos = strchr(pos, ','));

    if (paramCount<2) {
        return -2; //Недостаточно аргументов
    }

    return result;
}
