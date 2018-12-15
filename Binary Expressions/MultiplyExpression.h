//
// Created by eyal on 12/13/18.
//

#ifndef FLIGHTSIMULATOR_MULTIPLYEXPRESSION_H
#define FLIGHTSIMULATOR_MULTIPLYEXPRESSION_H

#include "BinaryExpression.h"
#include "Expression.h"
#include <iostream>

using namespace std;

class MultiplyExpression : public BinaryExpression {
public:
    virtual double calculate();

    MultiplyExpression(Expression *left, Expression *right);

    friend ostream &operator<<(ostream &stream, const MultiplyExpression &MultiplyExpression);
};


#endif //FLIGHTSIMULATOR_MULTIPLYEXPRESSION_H
