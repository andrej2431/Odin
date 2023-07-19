cmake_minimum_required(VERSION 3.26)
project(Odin)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory("/home/andrej/Code/Odin/portaudio" portaudio_folder)

add_executable(Odin main.cpp test/test.cpp test/test.h)

target_link_libraries(Odin portaudio_static)
