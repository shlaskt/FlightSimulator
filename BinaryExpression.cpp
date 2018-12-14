//
// Created by eyal on 12/13/18.
//

#include "BinaryExpression.h"

/**
 * get the left expression.
 * @return left expression pointer.
 */
Expression *BinaryExpression::getRight() const {
    return this->left;
}

/**
 * get the right expression.
 * @return right expression pointer.
 */
Expression *BinaryExpression::getLeft() const {
    return this->right;
}

