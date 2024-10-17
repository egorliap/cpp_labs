#pragma once
#include <string>

class Token
{
public:
    // ���
    enum Type
    {
        OPERATOR,      // �������/�������� ��������
        L_PARANTHESIS, // ����������� ������
        R_PARANTHESIS, // ����������� ������
        INT_LITERAL,   // ����� �����
        FLOAT_LITERAL, // ����� � ��������� ������ 
        FUNCTION,      // �������
        SEPARATOR      // ����������� ���������� �������
    };

    // ���������������
    enum OperatorAssociativity
    {
        NONE,  // ����� - �� ��������
        RIGHT, // ������������������
        LEFT   // �����������������
    };

    Token(std::string token, Type type, OperatorAssociativity asc = NONE);

    // ���������
    int getPrecendance() const;

    const Type& getType() const { return type; }
    const OperatorAssociativity& getAsc() const { return opAsc; }
    const std::string& getStr() const { return str; }

private:
    Type type;
    OperatorAssociativity opAsc;
    std::string str;
};