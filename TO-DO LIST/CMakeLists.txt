cmake_minimum_required(VERSION 3.23)
project(task4)

set(CMAKE_CXX_STANDARD 14)

add_executable(task4 main.cpp sqlite-amalgamation-3430100/sqlite3.h  sqlite-amalgamation-3430100/sqlite3.c)
