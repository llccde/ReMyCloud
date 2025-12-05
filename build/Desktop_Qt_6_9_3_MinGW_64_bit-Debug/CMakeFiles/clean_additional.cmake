# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appReMyCloud_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appReMyCloud_autogen.dir\\ParseCache.txt"
  "appReMyCloud_autogen"
  )
endif()
