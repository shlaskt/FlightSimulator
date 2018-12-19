cmake_minimum_required(VERSION 3.13)
project(FlightSimulator)
#set(CMAKE_CXX_FLAGS "-std=c++14 -pthread")

set(CMAKE_CXX_STANDARD 14)

add_executable(FlightSimulator main.cpp ExpressionInterfaces/Expression.h ExpressionInterfaces/BinaryExpression.cpp ExpressionInterfaces/BinaryExpression.h UnaryExpressions/UnaryExpression.cpp UnaryExpressions/UnaryExpression.h BinaryExpressions/PlusExpression.cpp BinaryExpressions/PlusExpression.h BinaryExpressions/MinusExpression.cpp BinaryExpressions/MinusExpression.h BinaryExpressions/MultiplyExpression.cpp BinaryExpressions/MultiplyExpression.h BinaryExpressions/DivideExpression.cpp BinaryExpressions/DivideExpression.h UnaryExpressions/NegExpression.cpp UnaryExpressions/NegExpression.h Num.cpp Num.h Dijkstra.cpp Dijkstra.h InputManagement.cpp InputManagement.h DataManagement/DataBase.cpp DataManagement/DataBase.h ExpressionInterfaces/ExpressionCommand.cpp ExpressionInterfaces/ExpressionCommand.h
Sockets/Client.cpp Sockets/Client.h Sockets/DataReaderServer.cpp Sockets/DataReaderServer.h Commands/Command.h Commands/OpenDataServer.cpp Commands/OpenDataServer.h Commands/ConnectCommand.cpp Commands/ConnectCommand.h)