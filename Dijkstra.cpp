//
// Created by tomer on 12/18/18.
//



// CPP program to evaluate a given
// expression where tokens are
// separated by space.
#include "Dijkstra.h"

/**
 * Ctor - get map values
 * @param var_to_val
 */
Dijkstra::Dijkstra(const map<string, double> &var_to_val) : var_to_val(var_to_val) {}


// Function to find precedence of
// operators.
int Dijkstra::precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to perform arithmetic operations.
Expression *Dijkstra::applyOp(double a, double b, char op) {
    switch (op) {
        case '+':
            return new PlusExpression(new Num(a), new Num(b));
        case '-':
            return new MinusExpression(new Num(a), new Num(b));
        case '*':
            return new MultiplyExpression(new Num(a), new Num(b));
        case '/':
            return new DivideExpression(new Num(a), new Num(b));
    }
}

// Function that returns value of
// expression after evaluation.
double Dijkstra::evaluate(string tokens) {
    bool first_op = false;
    int i;
    // stack to store integer values.
    stack<double> values;

    // stack to store operators.
    stack<char> ops;

    // negative number can be in 2 ways-> a. in the begining. b. after operator


    for (i = 0; i < tokens.length(); i++) {
        bool afterPoint = false;
        double float_num = 10;
        // Current token is a whitespace,
        // skip it.
        if (tokens[i] == ' ')
            continue;

            // Current token is an opening
            // brace, push it to 'ops'
        else if (tokens[i] == '(') {
            ops.push(tokens[i]);
        }

            // Current token is a number, push
            // it to stack for numbers.
        else if (isdigit(tokens[i])) {
            double val = 0;

            // There may be more than one
            // digits in number.
            while (i < tokens.length() && isdigit(tokens[i])
                   || tokens[i] == '.') {
                if (tokens[i] == '.') {
                    afterPoint = true;
                } else {
                    if (!afterPoint)
                        val = (val * 10) + (tokens[i] - '0');
                    else {
                        val += (tokens[i] - '0') / float_num;
                        float_num *= 10;
                    }
                }
                i++;
            }

            values.push(val);
        }

            // Closing brace encountered, solve
            // entire brace.
        else if (tokens[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                double val2 = values.top();
                values.pop();

//                double val1 = values.top();
//                values.pop();

                double val1;
                // check for neg number
                if (values.empty()) {
                    val1 = 0; // 0 - num = -num
                } else {
                    val1 = values.top();
                    values.pop();
                }
                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op)->calculate());
            }

            // pop opening brace.
            ops.pop();
        }

            // Current token is an operator.
        else {
            // While top of 'ops' has same or greater
            // precedence to current token, which
            // is an operator. Apply operator on top
            // of 'ops' to top two elements in values stack.
            first_op = true;
            while (!ops.empty() && precedence(ops.top())
                                   >= precedence(tokens[i])) {
                double val2 = values.top();
                values.pop();

                double val1;
                // check for neg number
                if (values.empty()) {
                    val1 = 0; // 0 - num = -num
                } else {
                    val1 = values.top();
                    values.pop();
                }

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op)->calculate());
            }

            // Push current token to 'ops'.
            ops.push(tokens[i]);
        }
    }

    // Entire expression has been parsed at this
    // point, apply remaining ops to remaining
    // values.
    while (!ops.empty()) {
        double val2 = values.top();
        values.pop();

//        double val1 = values.top();
//        values.pop();

        double val1;
        // check for neg number
        if (values.empty()) {
            val1 = 0; // 0 - num = -num
        } else {
            val1 = values.top();
            values.pop();
        }

        char op = ops.top();
        ops.pop();

        values.push(applyOp(val1, val2, op)->calculate());
    }

    // Top of 'values' contains result, return it.
    return values.top();
}

/**
 * split line to vector by separate sign
 * e.x - splitLine("hey-you-o", v, '-')
 *          --> v = {"hey", "you", "o"}
 * @param line to split
 * @param sign to separte
 */
vector<string> Dijkstra::splitLine(const string &str, char sign) {
    stringstream stream(str);
    string split;
    vector<string> spaces_split;
    while (getline(stream, split, sign)) {
        spaces_split.push_back(split);
    }
    return spaces_split;
}


double Dijkstra::operator()(char *str) {
    string string_before_evaluate_vars = (string) str;
    return calculate(string_before_evaluate_vars);

}

double Dijkstra::operator()(string str) {
    return calculate(str);
}

double Dijkstra::calculate(string string_before_evaluate_vars) {
    string string_after_evaluate_vars; // = ""
    // split the string to vector by whitespace
    vector<string> splited = splitLine(string_before_evaluate_vars, ' ');
    for (vector<string>::iterator it = splited.begin(); it != splited.end(); it++) {
        string somthing = (*it); // operator or number or var
        // if start with digit- it is number, place it back to the string
        // if it operator -place it back to the string
        if (isdigit(somthing[0]
                    || somthing == "+" || somthing == "-" || somthing == "*" || somthing == "-")) {
            string_after_evaluate_vars += somthing;
        } else {
            // it is a variable, evalute it
            double val = var_to_val.at(somthing); // throw exception if no var
            // place it back to the string
            string_after_evaluate_vars += to_string(val);
        }
    }

    double result = evaluate(string_after_evaluate_vars);
    return result;
}

