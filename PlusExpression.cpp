//
// Created by eyal on 12/13/18.
//
#include "PlusExpression.h"

/**
 * calculate + between 2 expressions.
 * @return the calculation of the two expressions.
 */
double PlusExpression::calculate() {
    return (this->getLeft()->calculate() + this->getRight()->calculate());
}

/**
 * use the binary constructor to initilize all the values.
 * @param left expressions.
 * @param right expressions.
 */
PlusExpression::PlusExpression(Expression *left, Expression *right) : BinaryExpression(left, right) {}

/**
 * operator << output
 * cout
 * print the expressions with +.
 * @param stream to print in
 * @param plus expressions to print it
 * @return infint in string
 */
ostream &operator<<(ostream &stream, const PlusExpression &plus_expression) {
    stream << plus_expression.getLeft() << "+" << plus_expression.getRight();
    return stream;
}