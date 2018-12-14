//
// Created by eyal on 12/13/18.
//

#include "MultiplyExpression.h"

/**
 * calculate * between 2 expressions.
 * @return the calculation of the two expressions.
 */
double MultiplyExpression::calculate() {
    return (this->getLeft()->calculate() * this->getRight()->calculate());
}

/**
 * use the binary constructor to initilize all the values.
 * @param left expressions.
 * @param right expressions.
 */
MultiplyExpression::MultiplyExpression(Expression *left, Expression *right) : BinaryExpression(left, right) {}

/**
 * operator << output
 * cout
 * print the expressions with *.
 * @param stream to print in
 * @param Multiply expressions to print it
 * @return infint in string
 */
ostream &operator<<(ostream &stream, const MultiplyExpression &multiply_expression) {
    stream << multiply_expression.getLeft() << "*" << multiply_expression.getRight();
    return stream;
}