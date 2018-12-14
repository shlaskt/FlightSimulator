//
// Created by eyal on 12/13/18.
//

#ifndef FLIGHTSIMULATOR_NUM_H
#define FLIGHTSIMULATOR_NUM_H

#include "Expression.h"
#include <string>

using namespace std;

class Num : public Expression {
private:
    double num;
public:
    Num(string num);

    double getNum() const;

    virtual double calculate();
    friend ostream &operator<<(ostream &stream, const Num &num);
};


#endif //FLIGHTSIMULATOR_NUM_H
