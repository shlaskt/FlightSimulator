//
// Created by eyal on 12/18/18.
//

#include "InputManagement.h"

/**
 * sets the spaces to be ok.
 * @param line to convert.
 * @return the line after fine spaces.
 */
string addSpaces(string line) {
    string output;
    bool in_quotation_marks = false;
    if (line == "") return line;
    for (char ch : line) {
        switch (ch) {
            case ' ': {
                if (output.back() != ' ' && !output.empty()) output += ' ';
                break;
            }
            case '\"': {
                output += ch;
                in_quotation_marks = !in_quotation_marks;
                break;
            }
            case '+':
            case '-':
            case '*':
            case '/':
            case '=':
            case '>':
            case '<':
            case '!':
            case ',':
            case '{':
            case '}':
            case ')':
            case '(': {
                if (!in_quotation_marks) {
                    //first letter of the line, no space.
                    if (output.empty() || output.back() == ' ') {
                        output += ch;
                        output += ' ';
                    } else {
                        output += ' ';
                        output += ch;
                        output += ' ';
                    }
                    break;
                }
            }
            default: {
                output += ch;
            }
        }
    }
    //if the last char is space, delete it.
    if (output.back() == ' ') output.pop_back();
    return output;
}

/**
 * split line to vector by separate sign
 * e.x - splitLine("hey-you-o", v, '-')
 *          --> v = {"hey", "you", "o"}
 * @param line to split
 * @param sign to separte
 */
vector<string> splitLine(const string &line, char sign) {
    stringstream stream(line);
    string split;
    vector<string> spaces_split;
    while (getline(stream, split, sign)) {
        spaces_split.push_back(split);
    }
    return spaces_split;
}

vector<string> lexer(string line) {
    return splitLine(addSpaces(line), ' ');
}

void lexerTests() {
    bool sucseed = true;
    if (addSpaces("(h1+h2)/2") != "( h1 + h2 ) / 2") {
        cout << "\"(h1+h2)/2\" test failed" << endl;
        sucseed = false;
    }
    if (addSpaces("6*3") != "6 * 3") {
        cout << "\"6 * 3\" test failed" << endl;
        sucseed = false;
    }
    if (addSpaces("x=var/3") != "x = var / 3") {
        cout << "\"x=var/3\" test failed" << endl;
        sucseed = false;
    }
    if (addSpaces("    x=var1   +   var2") != "x = var1 + var2") {
        cout << "\"x = var1 + var2\" test failed" << endl;
        sucseed = false;
    }
    if (addSpaces("-5") != "- 5") {
        cout << "\"- 5 \" test failed" << endl;
        sucseed = false;
    }
    if (sucseed) {
        cout << "all lexer spaces tests passed";
    }
}

/**
 * get iterator to start and to end, and make it one string of exprresion.
 * @param it start.
 * @param end iteartor end.
 * @return string exprresion.
 */
string makeExpression(int &index, vector<string> vec) {
    string expression;
    bool is_this_operator;
    bool is_next_operator;
    bool is_this_right_parenthesis = false;
    bool is_quote;
    string current = vec[index];
    // case is a quote add all the quote to one expression.
    if (current[0] == '\"') {
        expression += vec[index];
        if (current.back() == '\"') return expression;
        do {
            ++index;
            // if only one expression end function.
            //forword iterator.
            current = vec[index];
            expression = expression + " " + current;
        } while (current.back() != '\"');
        return expression;
    }
    do {
        // adding value to expression.
        expression += current;
        if (current == "+" || current == "-" || current == "*" || current == "/"
            || current == "(" || current == ")") {
            is_this_operator = true;
            if (current == ")") is_this_right_parenthesis = true;
        } else { is_this_operator = false; }
        //forword the iterator.
        if (index == vec.size() - 1) {
            break;
        }
        ++index;
        //update current.
        current = vec[index];
        // check if operator.
        if (current == "+" || current == "-" || current == "*" || current == "/"
            || current == "(" || current == ")") {
            is_next_operator = true;
        } else {
            // if there is right paranthesis and after it a number.
            if (is_this_right_parenthesis && index != vec.size()) {
                break;
            }
            is_next_operator = false;
        }
        is_this_right_parenthesis = false;
    } while ((is_this_operator || is_next_operator) && index != vec.size() && current != ",");
    // if reached to the end, return it -- * twice because end loop do ++ becuase need to read the current value.
    --index;
    //added spaces to make it valid.
    return addSpaces(expression);
}

/**
 * get line as a parameter and return vector in each index store expression.
 * @param line to parse.
 * @return vector after paresed.
 */
vector<string> parser(string line) {
    int index = 0;
    vector<string> lexered_line = lexer(line);
    if (lexered_line.size() == 0) {
        throw runtime_error("error in lexering line");
    }
    // get first value and forword the iterator.
    //    vector<string>::iterator it = (lexered_line.begin());
    vector<string> parserd_line;
    // save expression in one place together.
    bool is_neg = true;
    for (int i = 0; index < lexered_line.size() && i < lexered_line.size(); index++, i++) {
        string expression = "";
        //string current = *it;
        string current = lexered_line[index];
        /**
         * need to check if it is a minus repressent neg and not minus operator:
         * 3 option that the minus is neg:
         * 1) '-' after operator =, meant it is neg.
         * 2) '-' after first argument in the line. first argument is always command, so again its neg.
         * 3) '-' in third argument or after. in this case there has to be ',' before the neg sign.
         */

        if (current == "-") {
            // if ((*prev(it, 1) == "=") || i == 1 || (i > 1 && (*prev(it, 1) == ","))) {
            if (lexered_line[index - 1] == "=" || i == 1 || (i > 1 && lexered_line[index - 1] == ","))
                // send the end of the iterator to know when to stop.
//                vector<string>::iterator it_end = lexered_line.end();
                // call the makeExpression with the vector the string from "-" include.
                expression += makeExpression(index, lexered_line);
            parserd_line.push_back(expression);
            continue;
        } else if (current[0] == '\"') {
//            vector<string>::iterator it_end = lexered_line.end();
            expression += makeExpression(index, lexered_line);
            parserd_line.push_back(expression);
        } else if (current == "+" || current == "-" || current == "*" ||
                   current == "/" || current == "(") {
            // send the end of the iterator to know when to stop.
//            vector<string>::iterator it_end = lexered_line.end();
            //send to function that make expression.
            if (current == "(") {
                // call the makeExpression with the vector the string from '(' include.
                expression += makeExpression(index, lexered_line);
            } else {
                // its an operator, sent the vector from before the operator.
                int prev_index = index - 1;
                expression += makeExpression(prev_index, lexered_line);
                // update the iterator to its place
                index = prev_index;
                // need to remove the previous argument added that need to be begin of expression.
                parserd_line.pop_back();
            }
            // add the exprresion to the parserd vector:
            parserd_line.push_back(expression);
        } else {
            // relate to "," ass a value only if it's not a separator before neg expression.
            if (current == "," && lexered_line[index + 1] == "-") continue;
            //incase no need to make expression, add the value of the vector as is.
            parserd_line.push_back(lexered_line[index]);
        }
    }
    return
            parserd_line;
}

void parserTests() {
    int test = 1;
    string test_string = "test";

    vector<string> parserd_line = parser("var tomer = -15+(10   *3)");
    if (parserd_line[0] == "var" && parserd_line[1] == "tomer" && parserd_line[2] == "=" &&
        parserd_line[3] == "- 15 + ( 10 * 3 )")
        cout << test_string << test << ": passed" << endl;
    else cout << test_string << test << ": failed" << endl;
    test++;
    parserd_line = parser("OpenDataServer = 1000 100");
    if (parserd_line[0] == "OpenDataServer" && parserd_line[1] == "=" && parserd_line[2] == "1000" &&
        parserd_line[3] == "100")
        cout << test_string << test << ": passed" << endl;
    else cout << test_string << test << ": failed" << endl;
    test++;
    parserd_line = parser("var breaks = bind \"/controls/flight/speedbrake\"");
    if (parserd_line[0] == "var" && parserd_line[1] == "breaks" && parserd_line[2] == "="
        && parserd_line[3] == "bind" && parserd_line[4] == "\"/controls/flight/speedbrake\"")
        cout << test_string << test << ": passed" << endl;
    else {
        cout << test_string << test << ": failed" << endl;
        cout << parserd_line[4] << endl;
    }
    test++;
    parserd_line = parser("while  a<5 {");
    if (parserd_line[0] == "while" && parserd_line[1] == "a" && parserd_line[2] == "<"
        && parserd_line[3] == "5" && parserd_line[4] == "{")
        cout << test_string << test << ": passed" << endl;
    else cout << test_string << test << ": failed" << endl;
    test++;
    parserd_line = parser("while  a!=5 {");
    if (parserd_line[0] == "while" && parserd_line[1] == "a" && parserd_line[2] == "!"
        && parserd_line[3] == "=" && parserd_line[4] == "5" && parserd_line[5] == "{")
        cout << test_string << test << ": passed" << endl;
    else cout << test_string << test << ": failed" << endl;
    test++;
    parserd_line = parser("connect 127.0.0.1 5402");
    if (parserd_line[0] == "connect" && parserd_line[1] == "127.0.0.1" && parserd_line[2] == "5402")
        cout << test_string << test << ": passed" << endl;
    else cout << test_string << test << ": failed" << endl;
    test++;
    parserd_line = parser("var alt = bind \"/instrumentation/altimeter/indicated-altitude-ft\"");
    if (parserd_line[0] == "var" && parserd_line[1] == "alt" && parserd_line[2] == "="
        && parserd_line[3] == "bind" && parserd_line[4] == "\"/instrumentation/altimeter/indicated-altitude-ft\"")
        cout << test_string << test << ": passed" << endl;
    else cout << test_string << test << ": failed" << endl;
    test++;
    parserd_line = parser("rudder = (h0-heading)/20");
    if (parserd_line[0] == "rudder" && parserd_line[1] == "=" && parserd_line[2] == "( h0 - heading ) / 20")
        cout << test_string << test << ": passed" << endl;
    else cout << test_string << test << ": failed" << endl;
    test++;
    parserd_line = parser("aileron = - roll /70");
    if (parserd_line[0] == "aileron" && parserd_line[1] == "=" && parserd_line[2] == "- roll / 70")
        cout << test_string << test << ": passed" << endl;
    else cout << test_string << test << ": failed" << endl;
    test++;
    parserd_line = parser("print \"done\"");
    if (parserd_line[0] == "print" && parserd_line[1] == "\"done\"")
        cout << test_string << test << ": passed" << endl;
    else cout << test_string << test << ": failed" << endl;
    test++;
}
