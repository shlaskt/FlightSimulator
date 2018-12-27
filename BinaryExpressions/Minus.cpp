//


// Created by reut on 13/12/18.
//

#include "Minus.h"
double Minus::calculate(){
    return( this->getLeft()->calculate())-(this->getRight()->calculate());
}
Minus::Minus(Expression *left, Expression *right) :BinaryExpression(left,right){}