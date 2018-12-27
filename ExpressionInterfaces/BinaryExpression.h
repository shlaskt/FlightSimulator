//
// Created by reut on 13/12/18.
//

#ifndef FLIGHT_BINARYEXPRESSION_H
#define FLIGHT_BINARYEXPRESSION_H

#include "Expression.h"
class BinaryExpression: public Expression {

private:
    Expression *left;
    Expression *right;
public:
    virtual double calculate()=0;
    Expression *getLeft();
    Expression *getRight();
    BinaryExpression(Expression* left,Expression* right);

};


#endif //FLIGHT_BINARYEXPRESSION_H
