cmake_minimum_required(VERSION 3.10)
project(t03server)

set(CMAKE_CXX_STANDARD 17)

include_directories( ../pbinclude )
file(GLOB_RECURSE code_sources  "../pbinclude/*.cc" )
add_executable( t03server



        ${code_sources}

        serverApp.cpp
        connHandle.cpp
        connCmd.cpp
        connServer.cpp
        connClient.cpp
        timer.cpp
        lobby.cpp

        main.cpp


       )

target_link_libraries(t03server  protobuf pthread )