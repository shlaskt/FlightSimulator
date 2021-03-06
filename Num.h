//
// Created by Eyal on 13/12/18.
//

#ifndef FLIGHT_NUM_H
#define FLIGHT_NUM_H


#include "ExpressionInterfaces/Expression.h"

class Num : public Expression {

private:
    double num;
public:
    virtual double calculate();

    Num(double num);

};


#endif //FLIGHT_NUM_H
