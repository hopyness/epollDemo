cmake_minimum_required(VERSION 3.10)
project(t01client)

set(CMAKE_CXX_STANDARD 17)



add_executable(t01client
        serverApp.cpp
        connHandle.cpp
        connCmd.cpp
        connClient.cpp
        main.cpp

        )

target_link_libraries(t01client pthread )