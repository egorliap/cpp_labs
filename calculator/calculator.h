#pragma once
#include <string>
#include <stack>
#include "loader.h"
#include "token.h"
#include "tokenizer.h"

class Calculator {
private:
    Loader& loader;

    std::string skim_expression(const std::string& expression);

    void shunting_yard(const std::vector<Token>& expr, std::vector<Token>& outQueue);

    double process_expression(std::vector<Token>& expression);

    double process_function(const std::string& funcname, double arg1);
    double process_function(const std::string& funcname, double arg1, double arg2);
public:
    Calculator(Loader& loader);

    ~Calculator();

    void evaluate_expression(const std::string& expression);
};
