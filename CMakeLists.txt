cmake_minimum_required(VERSION 3.12)
project(flight)

##set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")
add_executable(flight main.cpp LexerClass.cpp LexerClass.h
        Command.h openServerCommand.cpp openServerCommand.h
        ExpressionInterfaces/Expression.h
        ExpressionInterfaces/BinaryExpression.cpp
        ExpressionInterfaces/BinaryExpression.h
        Mul.cpp Mul.h Div.cpp Div.h Plus.cpp Plus.h Minus.cpp Minus.h
        Num.cpp Num.h DataReaderServer.cpp DataReaderServer.h Maps.cpp
        Maps.h Parser.cpp Parser.h DefineVarCommand.cpp DefineVarCommand.h
        EqualCommand.cpp EqualCommand.h LoopCommand.cpp LoopCommand.h
        ConnectCommand.cpp ConnectCommand.h ExpressionInterfaces/ExpressionCommand.cpp
        ExpressionInterfaces/ExpressionCommand.h DataClient.cpp DataClient.h PrintCommand.cpp
        PrintCommand.h Dijkstra.cpp Dijkstra.h IfCommand.cpp IfCommand.h SleepCommand.cpp
        SleepCommand.h ExitCommand.cpp ExitCommand.h)