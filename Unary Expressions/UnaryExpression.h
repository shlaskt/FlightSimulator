//
// Created by eyal on 12/13/18.
//

#ifndef FLIGHTSIMULATOR_UNARYEXPRESSION_H
#define FLIGHTSIMULATOR_UNARYEXPRESSION_H


#include "Expression.h"

class UnaryExpression : public Expression {
private:
    Expression *expression;
public:
    virtual double calculate() = 0;

    Expression *getExpression() const;

    UnaryExpression(Expression *expression);
};


#endif //FLIGHTSIMULATOR_UNARYEXPRESSION_H
