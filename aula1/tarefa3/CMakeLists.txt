cmake_minimum_required(VERSION 3.13)
project(tarefa3 C)

set(CMAKE_C_STANDARD 99)

add_executable(tarefa3 main.c)
target_link_libraries(tarefa3 m)