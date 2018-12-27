//
// Created by reut on 13/12/18.
//

#include "Plus.h"
double Plus::calculate(){
    return( this->getLeft()->calculate())+(this->getRight()->calculate());
}
Plus::Plus(Expression *left, Expression *right):BinaryExpression(left,right) {

}

