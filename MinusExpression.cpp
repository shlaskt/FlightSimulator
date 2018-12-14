//
// Created by eyal on 12/13/18.
//
#include "MinusExpression.h"

/**
 * calculate - between 2 expressions.
 * @return the calculation of the two expressions.
 */
double MinusExpression::calculate() {
    return (this->getLeft()->calculate() - this->getRight()->calculate());
}

/**
 * use the binary constructor to initilize all the values.
 * @param left expressions.
 * @param right expressions.
 */
MinusExpression::MinusExpression(Expression *left, Expression *right) : BinaryExpression(left, right) {}

/**
 * operator << output
 * cout
 * print the expressions with -.
 * @param stream to print in
 * @param Minus expressions to print it
 * @return infint in string
 */
ostream &operator<<(ostream &stream, const MinusExpression &minus_expression) {
    stream << minus_expression.getLeft() << "-" << minus_expression.getRight();
    return stream;
}