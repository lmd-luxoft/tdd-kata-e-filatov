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
    char firstNumChar[16];
    
    if (!strlen(expression)) {
        return -1; //������ ������
    }

    char* pos = 0;
    pos = strchr(expression, ',');
    if (!pos) {
        return -2; //�� ������ ����������� - ������������ ����������
    }
    if (pos == expression) {
        return -2; //��� ������� ���������
    }

    sscanf(expression, "%d", &cuttedNum);
   
    result += cuttedNum;

    if (!strlen(++pos)) {
        return -2; //������������ ����������
    }

    sscanf(pos, "%d", &cuttedNum);

    result += cuttedNum;
    
    return result;
}
