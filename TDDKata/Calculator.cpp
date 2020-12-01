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
        return -1; //������ ������
    }
    char* pos = expression;
    while (pos = strchr(pos, '\n')) {
        *pos = ',';
    }

    pos = strchr(expression, ',');
    if (!pos) {
        return -2; //�� ������ ����������� - ������������ ����������
    }
    if (pos == expression) {
        return -2; //��� ������� ���������
    }

    sscanf(expression, "%d", &cuttedNum); //����� ������ ��������
    paramCount++;
    result += cuttedNum;

    do{
        if (strlen(++pos)) {
            if ((*pos < '0') || (*pos > '9')) {
                return -3; //������������ ������, ����� ����������� �� �����
            }
            sscanf(pos, "%d", &cuttedNum);
            result += cuttedNum;
            paramCount++;
        }
    } while (pos = strchr(pos, ','));

    if (paramCount<2) {
        return -2; //������������ ����������
    }

    return result;
}
