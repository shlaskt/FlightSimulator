#include <iostream>
#include "InputManagement.h"
#include "Dijkstra.h"
#include "Sockets/DataReaderServer.h"
#include <string>
/**
 * for now, do nothing.
 * @return
 */
using namespace std;


int main() {
//    VarDataBase varDataBase;
//    DataReaderServer dataReaderServer(varDataBase);
//    int sockfd = dataReaderServer.open(5400, 10);
//    dataReaderServer.readSocket(sockfd);
    map<string,double> map;
    map["key1"]=5.2;
    map["key2"]=4;
    Dijkstra shunting_yard(map);
    cout << shunting_yard(" - 6 * 5 + ( key1 * ( 3 + 2 - ( key1 - - 4 ) ) ) ") << "\n";
//    cout << shunting_yard("( 2.3 * -6 . 4 )") << "\n";
//    cout << shunting_yard("100 * 2 + 12") << "\n";
//    cout << shunting_yard("100 * (2 + 12 )") << "\n";
//    cout << shunting_yard("100 * (2 + 12 ) / 14");

//    vector<string> temp = lexer("OpenDataServer 5,-3  ");
//    cout << "Hii" << endl;
      return 0;

}