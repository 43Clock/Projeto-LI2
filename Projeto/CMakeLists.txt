cmake_minimum_required(VERSION 3.13)
project(PEO C)

set(CMAKE_C_STANDARD 99)

add_executable(proj main.c estado.h estado.c auxiliares.c auxiliares.h substituir.c Interface.c bot.c)