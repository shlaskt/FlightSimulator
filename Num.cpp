//
// Created by eyal on 12/13/18.
//

#include "Num.h"

/**
 * get string and convert it to double.
 * @param num string represent double.
 */
Num::Num(string string_num) {
    this->num = stod(string_num);
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
 * @return string
 */
ostream &operator<<(ostream &stream, const Num &num) {
    stream << (to_string(num.getNum()));
    return stream;
}

Num::Num(double number) {
    this->num = number;
}
/**
 * return the num value.
 * @return num value by double.
 */
double Num::calculate() {
    return num;
}
