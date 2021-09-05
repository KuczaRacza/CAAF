cmake_minimum_required(VERSION 3.6)
project(CAAF)

file(GLOB src "src/*.cpp")
add_executable(enc enc.cpp ${src})
add_executable(dec dec.cpp ${src})
set_property(TARGET enc PROPERTY CXX_STANDARD 20)
set_property(TARGET dec PROPERTY CXX_STANDARD 20)

