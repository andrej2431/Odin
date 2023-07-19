cmake_minimum_required(VERSION 3.23)
project(Rocnikovy_projekt)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory("/home/andrej/School/Rocnikovy_projekt/portaudio" portaudio_folder)

add_executable(Rocnikovy_projekt main.cpp test/test.cpp test/test.h)

target_link_libraries(Rocnikovy_projekt portaudio_static)
