#include <iostream>
#include "InputManagement.h"
#include "Dijkstra.h"
#include <string>
/**
 * for now, do nothing.
 * @return
 */
using namespace std;


int main() {
    map<string,double> map;
    map["key"]=5;
    Dijkstra shunting_yard(map);
    cout << shunting_yard("  key * (  6 ) ") << "\n";
//    cout << shunting_yard("( 2.3 * -6 . 4 )") << "\n";
//    cout << shunting_yard("100 * 2 + 12") << "\n";
//    cout << shunting_yard("100 * (2 + 12 )") << "\n";
//    cout << shunting_yard("100 * (2 + 12 ) / 14");

//    vector<string> temp = lexer("OpenDataServer 5,-3  ");
//    cout << "Hii" << endl;
      return 0;

}