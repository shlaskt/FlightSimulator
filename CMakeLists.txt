cmake_minimum_required(VERSION 3.13)
project(FlightSimulator)

set(CMAKE_CXX_STANDARD 14)

add_executable(FlightSimulator main.cpp Expression.h BinaryExpression.cpp BinaryExpression.h UnaryExpression.cpp UnaryExpression.h PlusExpression.cpp PlusExpression.h MinusExpression.cpp MinusExpression.h MultiplyExpression.cpp MultiplyExpression.h DivideExpression.cpp DivideExpression.h NegExpression.cpp NegExpression.h Num.cpp Num.h)