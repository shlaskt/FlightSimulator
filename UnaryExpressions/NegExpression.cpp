//
// Created by eyal on 12/13/18.
//

#include "NegExpression.h"

/**
 * calculate the negate of the expresstion.
 * @return the calculation of the two expressions.
 */
double NegExpression::calculate() {
    return (-(this->getExpression()->calculate()));
}

/**
 * use the unary constructor to initilize the value.
 * @param expression expression to build.
 */
NegExpression::NegExpression(Expression *expression) : UnaryExpression(expression) {}

/**
 * operator << output
 * cout
 * print the expressions with +.
 * @param stream to print in
 * @param Neg expressions to print it
 * @return infint in string
 */
ostream &operator<<(ostream &stream, const NegExpression &neg_expression) {
    stream << "-" << neg_expression.getExpression();
    return stream;
}