//
// Created by eyal on 12/13/18.
//

#ifndef FLIGHTSIMULATOR_MINUSEXPRESSION_H
#define FLIGHTSIMULATOR_MINUSEXPRESSION_H

#include "../ExpressionInterfaces/Expression.h"
#include "../ExpressionInterfaces/BinaryExpression.h"
#include <iostream>

using namespace std;

class MinusExpression : public BinaryExpression {
public:
    virtual double calculate();

    MinusExpression(Expression *left, Expression *right);

    friend ostream &operator<<(ostream &stream, const MinusExpression &plusExpression);
};


#endif //FLIGHTSIMULATOR_MINUSEXPRESSION_H
