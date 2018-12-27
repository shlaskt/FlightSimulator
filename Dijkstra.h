//
// Created by Tomer & Eyal on 20/12/18.
//

#ifndef FLIGHT_DIJKSTRA_H
#define FLIGHT_DIJKSTRA_H


#include "ExpressionInterfaces/BinaryExpression.h"
#include "BinaryExpressions/Plus.h"
#include "Num.h"

#include "BinaryExpressions/Minus.h"
#include "BinaryExpressions/Mul.h"
#include "Commands/Div.h"
#include "ExpressionInterfaces/Expression.h"
#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

class Dijkstra {
    map<string,double>* var_to_val;
    int precedence(char op);

public:
    Dijkstra(map<string, double>* var_to_val);


private:
    Expression* applyOp(double a, double b, char op);
    vector<string> splitLine(const string &str, char sign);
    vector<BinaryExpression*> deleteVector;

    double calculate(string tokens);
    double evaluate(string tokens);

public:
    double virtual operator()(char* str);
    double virtual dijkstratoi(string str);
    void addToDelete(BinaryExpression* exp);
    ~Dijkstra(){
        vector<BinaryExpression*>::iterator it = this->deleteVector.begin();
        for(it;it!=this->deleteVector.end();++it){
            delete (*it)->getRight();
            delete (*it)->getLeft();
            delete (*it);
        }
    }

};


#endif //FLIGHT_DIJKSTRA_H
