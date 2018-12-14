//
// Created by eyal on 12/13/18.
//

#include "DivideExpression.h"

/**
 * calculate / between 2 expressions.
 * @return the calculation of the two expressions.
 */
double DivideExpression::calculate() {
    return (this->getLeft()->calculate() / this->getRight()->calculate());
}

/**
 * use the binary constructor to initilize all the values.
 * @param left expressions.
 * @param right expressions.
 */
DivideExpression::DivideExpression(Expression *left, Expression *right) : BinaryExpression(left, right) {}

/**
 * operator << output
 * cout
 * print the expressions with /.
 * @param stream to print in
 * @param Divide expressions to print it
 * @return infint in string
 */
ostream &operator<<(ostream &stream, const DivideExpression &divide_expression) {
    stream << divide_expression.getLeft() << "/" << divide_expression.getRight();
    return stream;
}