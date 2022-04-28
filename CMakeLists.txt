cmake_minimum_required(VERSION 3.10)
project(epollDemo)


add_subdirectory(t01server)
add_subdirectory(t01client)


add_subdirectory(t02server)
add_subdirectory(t02client)

add_subdirectory(testFunction)
#add_subdirectory(client1) epoll4 testC11