cmake_minimum_required(VERSION 3.10)
project(t02client)

set(CMAKE_CXX_STANDARD 17)


include_directories( ../pbinclude )
file(GLOB_RECURSE code_sources  "../pbinclude/*.cc" )
add_executable( t02client



        ${code_sources}

        serverApp.cpp
        connHandle.cpp
        connCmd.cpp
        connClient.cpp
        main.cpp

        )

target_link_libraries(t02client protobuf pthread )