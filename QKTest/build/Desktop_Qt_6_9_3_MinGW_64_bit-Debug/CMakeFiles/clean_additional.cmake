# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\TestMain_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TestMain_autogen.dir\\ParseCache.txt"
  "TestMain_autogen"
  )
endif()
