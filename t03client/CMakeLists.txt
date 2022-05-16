cmake_minimum_required(VERSION 3.10)
project(t03client)

set(CMAKE_CXX_STANDARD 17)


include_directories( ../pbinclude )
file(GLOB_RECURSE code_sources  "../pbinclude/*.cc" )
add_executable( t03client



        ${code_sources}

        serverApp.cpp
        connHandle.cpp
        connCmd.cpp
        connClient.cpp
        player.cpp

        main.cpp

        )

target_link_libraries(t03client protobuf pthread )