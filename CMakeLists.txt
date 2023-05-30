cmake_minimum_required(VERSION 3.24)
project(projectCPP)

set(CMAKE_CXX_STANDARD 23)

add_executable(projectCPP main.cpp Haslo.cpp Haslo.h Szyfr.cpp Szyfr.h WyborZMenu.cpp WyborZMenu.h FileOperations.cpp FileOperations.h StringOperations.cpp StringOperations.h)
