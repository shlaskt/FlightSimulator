//
// Created by Tomer & Eyal on 13/12/18.
//

#ifndef FLIGHT_DIV_H
#define FLIGHT_DIV_H


#include "../ExpressionInterfaces/BinaryExpression.h"

class Div: public BinaryExpression {
public:
    virtual double calculate();
    Div(Expression *left,Expression *right);

};


#endif //FLIGHT_DIV_H
