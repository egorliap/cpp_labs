#pragma once
#include <vector>
#include "token.h"

enum State
{
    S0, // ���������
    S1, // ����������� ������/���������
    S2, // ������ ������ ����� � �����
    S3, // ������ floating-point ����� � �����
    S4, // ������ ������� � �����
    S5  // ����������� ����������� �����/������� �� ������
};


void tokenize(const std::string& expr, std::vector<Token>& tokens);