# Install script for directory: C:/Users/andre/Documents/School/C++/Odin/OdinApp/AudioManager/portaudio

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/OdinApp")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/Qt/Tools/mingw1120_64/bin/objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/portaudio" TYPE FILE FILES "C:/Users/andre/Documents/School/C++/Odin/OdinApp/AudioManager/portaudio/README.md")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/portaudio" TYPE FILE FILES "C:/Users/andre/Documents/School/C++/Odin/OdinApp/AudioManager/portaudio/LICENSE.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "C:/Users/andre/Documents/School/C++/Odin/OdinApp/Build/portaudio_folder/portaudio-2.0.pc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "C:/Users/andre/Documents/School/C++/Odin/OdinApp/AudioManager/portaudio/include/portaudio.h"
    "C:/Users/andre/Documents/School/C++/Odin/OdinApp/AudioManager/portaudio/include/pa_win_ds.h"
    "C:/Users/andre/Documents/School/C++/Odin/OdinApp/AudioManager/portaudio/include/pa_win_waveformat.h"
    "C:/Users/andre/Documents/School/C++/Odin/OdinApp/AudioManager/portaudio/include/pa_win_wmme.h"
    "C:/Users/andre/Documents/School/C++/Odin/OdinApp/AudioManager/portaudio/include/pa_win_waveformat.h"
    "C:/Users/andre/Documents/School/C++/Odin/OdinApp/AudioManager/portaudio/include/pa_win_wasapi.h"
    "C:/Users/andre/Documents/School/C++/Odin/OdinApp/AudioManager/portaudio/include/pa_win_waveformat.h"
    "C:/Users/andre/Documents/School/C++/Odin/OdinApp/AudioManager/portaudio/include/pa_win_wdmks.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/andre/Documents/School/C++/Odin/OdinApp/Build/portaudio_folder/libportaudio.dll.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/andre/Documents/School/C++/Odin/OdinApp/Build/portaudio_folder/libportaudio.dll")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libportaudio.dll" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libportaudio.dll")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "C:/Qt/Tools/mingw1120_64/bin/strip.exe" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libportaudio.dll")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/andre/Documents/School/C++/Odin/OdinApp/Build/portaudio_folder/libportaudio.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/portaudio/portaudioTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/portaudio/portaudioTargets.cmake"
         "C:/Users/andre/Documents/School/C++/Odin/OdinApp/Build/portaudio_folder/CMakeFiles/Export/90a8b282bce0779409342a760050f91f/portaudioTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/portaudio/portaudioTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/portaudio/portaudioTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/portaudio" TYPE FILE FILES "C:/Users/andre/Documents/School/C++/Odin/OdinApp/Build/portaudio_folder/CMakeFiles/Export/90a8b282bce0779409342a760050f91f/portaudioTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/portaudio" TYPE FILE FILES "C:/Users/andre/Documents/School/C++/Odin/OdinApp/Build/portaudio_folder/CMakeFiles/Export/90a8b282bce0779409342a760050f91f/portaudioTargets-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/portaudio" TYPE FILE FILES
    "C:/Users/andre/Documents/School/C++/Odin/OdinApp/Build/cmake/portaudio/portaudioConfig.cmake"
    "C:/Users/andre/Documents/School/C++/Odin/OdinApp/Build/cmake/portaudio/portaudioConfigVersion.cmake"
    )
endif()

