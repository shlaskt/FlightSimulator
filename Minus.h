//
// Created by reut on 13/12/18.
//

#ifndef FLIGHT_MINUS_H
#define FLIGHT_MINUS_H


#include "ExpressionInterfaces/BinaryExpression.h"

class Minus: public BinaryExpression {
public:
    virtual double calculate();
    Minus(Expression *left,Expression *right);
};


#endif //FLIGHT_MINUS_H
