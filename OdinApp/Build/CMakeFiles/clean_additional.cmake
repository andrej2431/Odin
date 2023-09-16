# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\OdinApp_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\OdinApp_autogen.dir\\ParseCache.txt"
  "OdinApp_autogen"
  )
endif()
