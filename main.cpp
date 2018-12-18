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

    Dijkstra shunting_yard;
    cout << shunting_yard("( -2 * 6 )") << "\n";
    cout << shunting_yard("( 2 * 6 )") << "\n";
    cout << shunting_yard("100 * 2 + 12") << "\n";
    cout << shunting_yard("100 * (2 + 12 )") << "\n";
    cout << shunting_yard("100 * (2 + 12 ) / 14");

//    vector<string> temp = lexer("OpenDataServer 5,-3  ");
//    cout << "Hii" << endl;
      return 0;

}