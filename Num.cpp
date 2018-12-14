//
// Created by eyal on 12/13/18.
//

#include "Num.h"

/**
 * get string and convert it to double.
 * @param num string represent double.
 */
Num::Num(string num) {
    this->num = stod(num);
}

/**
 * get the number value.
 * @return the number value.
 */
double Num::getNum() const {
    return num;
}

/**
 * operator << output
 * cout
 * print  num expressions.
 * @param stream to print in
 * @param print the number.
 * @return infint in string
 */
ostream &operator<<(ostream &stream, const Num &num) {
    stream << (to_string(num.getNum()));
    return stream;
}