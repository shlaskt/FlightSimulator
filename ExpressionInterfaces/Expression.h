

#ifndef FLIGHT_EXPRESSION_H
#define FLIGHT_EXPRESSION_H
#include <string>
#include <algorithm>
#include <map>
#include <list>
using namespace std;

class Expression
{
public:
    virtual double calculate()=0;
};

#endif //FLIGHT_EXPRESSION_H
