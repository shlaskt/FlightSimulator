//
// Created by eyal on 12/13/18.
//

#ifndef FLIGHTSIMULATOR_PLUSEXPRESSION_H
#define FLIGHTSIMULATOR_PLUSEXPRESSION_H

#include "BinaryExpression.h"
#include "Expression.h"
#include <iostream>

using namespace std;

class PlusExpression : public BinaryExpression {
public:
    virtual double calculate();

    PlusExpression(Expression *left, Expression *right);

    friend ostream &operator<<(ostream &stream, const PlusExpression &plusExpression);
};


#endif //FLIGHTSIMULATOR_PLUSEXPRESSION_H
