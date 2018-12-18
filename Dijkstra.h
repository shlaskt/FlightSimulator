//
// Created by tomer on 12/18/18.
//

#ifndef FLIGHTSIMULATOR_DIJKSTRA_H
#define FLIGHTSIMULATOR_DIJKSTRA_H


#include "ExpressionInterfaces/Expression.h"
#include <iostream>
#include <string>
using namespace std;

class Dijkstra : public Expression {
    int precedence(char op);

    Expression* applyOp(double a, double b, char op);

    double evaluate(string tokens);

public:
    virtual double calculate();

};


#endif //FLIGHTSIMULATOR_DIJKSTRA_H
