cmake_minimum_required(VERSION 3.16.3)
project(multitheadapp)

set(CMAKE_CXX_STANDARD 14)

add_executable(multitheadapp main.cpp HairdressSalon.h "Client.cpp" "HairdressSalon.cpp" "colormod.h")
