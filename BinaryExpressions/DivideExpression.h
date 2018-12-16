//
// Created by eyal on 12/13/18.
//

#ifndef FLIGHTSIMULATOR_DIVIDEEXPRESSION_H
#define FLIGHTSIMULATOR_DIVIDEEXPRESSION_H


#include "../ExpressionInterfaces/Expression.h"
#include "../ExpressionInterfaces/BinaryExpression.h"
#include <iostream>

using namespace std;

class DivideExpression : public BinaryExpression {
public:
    virtual double calculate();

    DivideExpression(Expression *left, Expression *right);

    friend ostream &operator<<(ostream &stream, const DivideExpression &DivideExpression);
};



#endif //FLIGHTSIMULATOR_DIVIDEEXPRESSION_H
