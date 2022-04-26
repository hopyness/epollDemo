cmake_minimum_required(VERSION 3.10)
project(testFunction)

set(CMAKE_CXX_STANDARD 17)



add_executable(testFunction

        timeT.cpp
        main.cpp


       )

target_link_libraries(testFunction pthread )