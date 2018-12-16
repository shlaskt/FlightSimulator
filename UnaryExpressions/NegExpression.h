//
// Created by eyal on 12/13/18.
//

#ifndef FLIGHTSIMULATOR_NEGEXPRESSION_H
#define FLIGHTSIMULATOR_NEGEXPRESSION_H


#include "UnaryExpression.h"
#include "../ExpressionInterfaces/Expression.h"
#include <iostream>

using namespace std;

class NegExpression : public UnaryExpression {
public:
    virtual double calculate();

    NegExpression(Expression *expression);

    friend ostream &operator<<(ostream &stream, const NegExpression &NegExpression);
};



#endif //FLIGHTSIMULATOR_NEGEXPRESSION_H
