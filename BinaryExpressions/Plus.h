//
// Created by Tomer & Eyal on 13/12/18.
//

#ifndef FLIGHT_PLUS_H
#define FLIGHT_PLUS_H


#include "../ExpressionInterfaces/BinaryExpression.h"

class Plus: public BinaryExpression {
public:
    virtual double calculate();
    Plus(Expression *left,Expression *right);

};

#endif //FLIGHT_PLUS_H
