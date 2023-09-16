cmake_minimum_required(VERSION 3.24)
project(AudioManager)

set(CMAKE_CXX_STANDARD 20)

add_library(AudioManager SHARED
        src/AudioManager.cpp
        src/Device.cpp
        src/Filter.cpp
        src/Connection.cpp)

target_include_directories(AudioManager PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)

add_subdirectory("${CMAKE_SOURCE_DIR}/portaudio" portaudio_folder)

target_link_libraries(AudioManager PUBLIC portaudio)