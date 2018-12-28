cmake_minimum_required(VERSION 3.12)
project(flight)

##set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")
add_executable(flight main.cpp
        Commands/Command.h Commands/openServerCommand.cpp Commands/openServerCommand.h
        ExpressionInterfaces/Expression.h
        ExpressionInterfaces/BinaryExpression.cpp
        ExpressionInterfaces/BinaryExpression.h
        BinaryExpressions/Mul.cpp BinaryExpressions/Mul.h BinaryExpressions/Div.cpp BinaryExpressions/Div.h BinaryExpressions/Plus.cpp BinaryExpressions/Plus.h BinaryExpressions/Minus.cpp BinaryExpressions/Minus.h
        Num.cpp Num.h Commands/DataReaderServer.cpp Commands/DataReaderServer.h DataMaps.cpp
        DataMaps.h Interpreter.cpp Interpreter.h Commands/VarCommand.cpp Commands/VarCommand.h
        Commands/AssignCommand.cpp Commands/AssignCommand.h Commands/WhileCommand.cpp Commands/WhileCommand.h
        Commands/ConnectCommand.cpp Commands/ConnectCommand.h ExpressionInterfaces/ExpressionCommand.cpp
        ExpressionInterfaces/ExpressionCommand.h Commands/Client.cpp Commands/Client.h Commands/PrintCommand.cpp
        Commands/PrintCommand.h Dijkstra.cpp Dijkstra.h Commands/IfCommand.cpp Commands/IfCommand.h Commands/SleepCommand.cpp
        Commands/SleepCommand.h Commands/ExitCommand.cpp Commands/ExitCommand.h
        InputReader/FileReader.cpp InputReader/FileReader.h InputReader/InputReadInterface.h InputReader/StdinReader.cpp InputReader/StdinReader.h Controller.cpp Controller.h InputReader/InputManage.cpp InputReader/InputManage.h)