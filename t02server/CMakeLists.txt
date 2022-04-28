cmake_minimum_required(VERSION 3.10)
project(t02server)

set(CMAKE_CXX_STANDARD 17)

include_directories( ../pbinclude )
file(GLOB_RECURSE code_sources  "../pbinclude/*.cc" )
add_executable( t02server



        ${code_sources}

        serverApp.cpp
        connHandle.cpp
        connCmd.cpp
        connServer.cpp
        connClient.cpp
        timer.cpp

        main.cpp


       )

target_link_libraries(t02server  protobuf pthread )