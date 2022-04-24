cmake_minimum_required(VERSION 3.10)
project(t01server)

set(CMAKE_CXX_STANDARD 17)



add_executable(t01server
        serverApp.cpp
        connHandle.cpp
        connCmd.cpp
        connServer.cpp
        connClient.cpp

        main.cpp


        )

target_link_libraries(t01server pthread )