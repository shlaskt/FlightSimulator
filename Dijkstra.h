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
    int precedence(char op);

    Expression* applyOp(double a, double b, char op);

    double evaluate(string tokens);

public:
    double virtual operator()(char* str);
    double virtual operator()(string str);

};


#endif //FLIGHTSIMULATOR_DIJKSTRA_H
