//
// Created by eyal on 12/13/18.
//

#include "BinaryExpression.h"
/**
 * Ctor
 * @param left
 * @param right
 */
BinaryExpression::BinaryExpression(Expression *left, Expression *right) : left(left), right(right) {}


/**
 * get the left expression.
 * @return left expression pointer.
 */
Expression *BinaryExpression::getRight() const {
    return this->right;
}

/**
 * get the right expression.
 * @return right expression pointer.
 */
Expression *BinaryExpression::getLeft() const {
    return this->left;
}

