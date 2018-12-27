//
// Created by reut on 13/12/18.
//

#include "Mul.h"
double Mul::calculate(){
    return (this->getLeft()->calculate()*this->getRight()->calculate());
}
Mul::Mul(Expression *left, Expression *right) :BinaryExpression(left,right){}