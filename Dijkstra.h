//
// Created by tomer on 12/18/18.
//

#ifndef FLIGHTSIMULATOR_DIJKSTRA_H
#define FLIGHTSIMULATOR_DIJKSTRA_H

#include "BinaryExpressions/PlusExpression.h"
#include "Num.h"
#include "BinaryExpressions/MinusExpression.h"
#include "BinaryExpressions/MultiplyExpression.h"
#include "BinaryExpressions/DivideExpression.h"
#include "ExpressionInterfaces/Expression.h"
#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class Dijkstra {
    map<string, double> *var_to_val;

    int precedence(char op);

    vector<Expression *> to_delete;
public:
    Dijkstra(map<string, double> *var_to_val);

private:
    Expression *applyOp(double a, double b, char op);

    vector<string> splitLine(const string &str, char sign);

    double calculate(string tokens);

    double evaluate(string tokens);

public:
    double virtual operator()(char *str);

    double virtual operator()(string str);

    virtual ~Dijkstra();
};


#endif //FLIGHTSIMULATOR_DIJKSTRA_H
