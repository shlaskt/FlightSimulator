//
// Created by reut on 13/12/18.
//

#include "BinaryExpression.h"
Expression* BinaryExpression:: getLeft(){

    return this->left;
}
Expression* BinaryExpression:: getRight(){
    return this->right;
}
BinaryExpression::BinaryExpression(Expression *left,Expression *right) {
    this->left=left;
    this->right=right;
}