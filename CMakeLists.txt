cmake_minimum_required(VERSION 3.12)
project(flight)

##set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")
add_executable(flight main.cpp LexerClass.cpp LexerClass.h
        Commands/Command.h openServerCommand.cpp openServerCommand.h
        ExpressionInterfaces/Expression.h
        ExpressionInterfaces/BinaryExpression.cpp
        ExpressionInterfaces/BinaryExpression.h
        Mul.cpp Mul.h Commands/Div.cpp Commands/Div.h Plus.cpp Plus.h Minus.cpp Minus.h
        Num.cpp Num.h Commands/DataReaderServer.cpp Commands/DataReaderServer.h Maps.cpp
        Maps.h Parser.cpp Parser.h Commands/DefineVarCommand.cpp Commands/DefineVarCommand.h
        Commands/EqualCommand.cpp Commands/EqualCommand.h Commands/LoopCommand.cpp Commands/LoopCommand.h
        Commands/ConnectCommand.cpp Commands/ConnectCommand.h ExpressionInterfaces/ExpressionCommand.cpp
        ExpressionInterfaces/ExpressionCommand.h Commands/DataClient.cpp Commands/DataClient.h PrintCommand.cpp
        PrintCommand.h Dijkstra.cpp Dijkstra.h Commands/IfCommand.cpp Commands/IfCommand.h SleepCommand.cpp
        SleepCommand.h Commands/ExitCommand.cpp Commands/ExitCommand.h)