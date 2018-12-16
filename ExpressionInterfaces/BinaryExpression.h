//
// Created by eyal on 12/13/18.
//

#ifndef FLIGHTSIMULATOR_BINARYEXPRESSION_H
#define FLIGHTSIMULATOR_BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression : public Expression {
private:
    Expression *left;
    Expression *right;
public:
    BinaryExpression(Expression *left, Expression *right);

    virtual double calculate() = 0;

    Expression *getLeft() const;

    Expression *getRight() const;

};

BinaryExpression::BinaryExpression(Expression *left, Expression *right) : left(left), right(right) {}


#endif //FLIGHTSIMULATOR_BINARYEXPRESSION_H
