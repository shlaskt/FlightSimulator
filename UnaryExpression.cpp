//
// Created by eyal on 12/13/18.
//

#include "UnaryExpression.h"
/**
 * get the unary expression.
 * @return unary expression.
 */
Expression *UnaryExpression::getExpression() const {
    return this->expression;
}
/**
 * Unary constractor with one expression.
 * @param expression to get it.
 */
UnaryExpression::UnaryExpression(Expression *expression) : expression(expression) {}