//
// Created by reut on 20/12/18.
//

#include "Dijkstra.h"

/**
 * Ctor - get map values
 * @param var_to_val
 */
Dijkstra::Dijkstra(map<string, double>* var_to_val){
    this->var_to_val = var_to_val;
}


/**
 * find precedence of operators
 * * and / before + and -
 * @param op
 * @return precedence
 */
int Dijkstra::precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

/**
 * calculate Expression
 *
 * @param a arg1
 * @param b arg2
 * @param op operator
 * @return arg1 operator arg2
 */
Expression *Dijkstra::applyOp(double a, double b, char op) {
    switch (op) {
        case '+': {
            BinaryExpression *newPlus = new Plus(new Num(a), new Num(b));
            addToDelete(newPlus);
            return newPlus;
        }
        case '-':{
            BinaryExpression *newMin = new Minus(new Num(a), new Num(b));
            addToDelete(newMin);
            return newMin;
        }
        case '*':{
            BinaryExpression *newMult = new Mul(new Num(a), new Num(b));
            addToDelete(newMult);
            return newMult;
        }
        case '/':{
            BinaryExpression *newDiv = new Div(new Num(a), new Num(b));
            addToDelete(newDiv);
            return newDiv;
        }
    }
}
void Dijkstra::addToDelete(BinaryExpression* exp){
    this->deleteVector.push_back(exp);

}

/**
 * returns value of  expression after evaluation.
 * @param tokens string with numbers and operators only
 * @return double
 */
double Dijkstra::evaluate(string tokens) {
    int i;
    bool is_op = false; // check for "-" that came after operator
    // stack to store integer values.
    stack<double> values;
    // stack to store operators.
    stack<char> ops;
    double is_neg = 1; // to double it in 1 /-1 if needed
    for (i = 0; i < tokens.length(); i++) {

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
        else if (isdigit(tokens[i]) || !is_op) {
            double val = 0;
            double float_num = 10;
            bool point = false;
            // check if neg
            if (tokens[i] == '-') {
                is_neg = -1;
                continue;
            }
            // There may be more than one
            // digits in number.
            while (i < tokens.length() &&
                   (isdigit(tokens[i]) || tokens[i] == '.')) {
                if (tokens[i] == '.') {
                    point = true;
                } else {
                    if (!point)
                        val = (val * 10) + (tokens[i] - '0');
                    else {
                        val += (tokens[i] - '0') / float_num;
                        float_num *= 10;
                    }
                }
                i++;
            }
            is_op = true;
            val *= is_neg; // -1 if shuold be neg, 1 o.w
            values.push(val);
            is_neg = 1;
        }
            // Closing brace encountered, solve entire brace.
        else if (tokens[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                // get 2 args
                double val2 = values.top();
                values.pop();
                double val1 = values.top();
                values.pop();
                // get op
                char op = ops.top();
                ops.pop();
                // calculate arg1 op arg2
                values.push(applyOp(val1, val2, op)->calculate());
            }
            ops.pop(); // pop opening brace.
        }
            // Current token is an operator.
        else {
            is_op = false;
            /*
             * While top of 'ops' has same or greater precedence to current token,
             * which is an operator. Apply operator on top of
             * 'ops' to top two elements in values stack.
             */
            while (!ops.empty() && precedence(ops.top()) >= precedence(tokens[i])) {
                // get 2 args
                double val2 = values.top();
                values.pop();
                double val1 = values.top();
                values.pop();
                // get op
                char op = ops.top();
                ops.pop();
                // calculate arg1 op arg2
                values.push(applyOp(val1, val2, op)->calculate());
            }
            // Push current token to 'ops'.
            ops.push(tokens[i]);
        }
    }

    /*
     * Entire expression has been parsed at this
     * point, apply remaining ops to remaining values.
     */
    while (!ops.empty()) {
        // get 2 args
        double val2 = values.top();
        values.pop();
        double val1 = values.top();
        values.pop();
        // get op
        char op = ops.top();
        ops.pop();
        // calculate arg1 op arg2
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

/**
 * get string and evaluate it with shunting yard algorithm
 * for char*
 * @param str string
 * @return double - the value after evaluate
 */
double Dijkstra::operator()(char *str) {
    string string_before_evaluate_vars = (string) str;
    return calculate(string_before_evaluate_vars);

}

/**
 * get string and evaluate it with shunting yard algorithm
 * for string
 * @param str string
 * @return double - the value after evaluate
 */
double Dijkstra::toVl(string str) {
    return calculate(str);
}

/**
 * get the string and evalute vars if have
 * send to evaluate in shunting yard algoritm
 * return the value- double
 * @param string_before_evaluate_vars
 * @return val
 */
double Dijkstra::calculate(string string_before_evaluate_vars) {
    string string_after_evaluate_vars; // = ""
    // split the string to vector by whitespace
    vector<string> splited = splitLine(string_before_evaluate_vars, ' ');
    char space = ' ';
    for (vector<string>::iterator it = splited.begin(); it != splited.end(); it++) {
        string argument = (*it); // operator or number or var
        // if start with digit- it is number, place it back to the string
        // if it operator -place it back to the string
        // add whitespace between every argument
        if (isdigit(argument[0])
            || argument == "+" || argument == "-" || argument == "*" || argument == "/"
            || argument == "(" || argument == ")" || argument == "") {
            string_after_evaluate_vars += (space + argument);
        } else {
            // it is a variable, evalute it
            double val = var_to_val->at(argument); // throw exception if no var
            // place it back to the string
            string_after_evaluate_vars +=(space + to_string(val));
        }
    }
    string_after_evaluate_vars+=space; // add one more whitespace

    double result = evaluate(string_after_evaluate_vars);
    if(result ==(-0)){ // edge case "-0"
        result=0;
    }
    return result;
}