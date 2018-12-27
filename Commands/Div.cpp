//
// Created by reut on 13/12/18.
//

#include "Div.h"
double Div::calculate(){
    return( this->getLeft()->calculate())/(this->getRight()->calculate());
}
Div::Div(Expression *left, Expression *right) :BinaryExpression(left,right){}