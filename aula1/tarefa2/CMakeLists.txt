cmake_minimum_required(VERSION 3.13)
project(tarefa2 C)

set(CMAKE_C_STANDARD 99)

add_executable(tarefa2 main.c)
target_link_libraries(tarefa2 m)