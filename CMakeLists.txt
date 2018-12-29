cmake_minimum_required(VERSION 3.12)
project(flight)

##set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")
add_executable(flight main.cpp
        Command.h openServerCommand.cpp openServerCommand.h
        Expression.h
        BinaryExpression.cpp
        BinaryExpression.h
        Mul.cpp Mul.h Div.cpp Div.h Plus.cpp Plus.h Minus.cpp Minus.h
        Num.cpp Num.h DataReaderServer.cpp DataReaderServer.h DataMaps.cpp
        DataMaps.h Interpreter.cpp Interpreter.h VarCommand.cpp VarCommand.h
        AssignCommand.cpp AssignCommand.h WhileCommand.cpp WhileCommand.h
        ConnectCommand.cpp ConnectCommand.h ExpressionCommand.cpp
        ExpressionCommand.h Client.cpp Client.h PrintCommand.cpp
        PrintCommand.h Dijkstra.cpp Dijkstra.h IfCommand.cpp IfCommand.h SleepCommand.cpp
        SleepCommand.h ExitCommand.cpp ExitCommand.h
        FileReader.cpp FileReader.h InputReadInterface.h StdinReader.cpp StdinReader.h
        Controller.cpp Controller.h InputManage.cpp InputManage.h)