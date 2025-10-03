# CMakeList.txt : CMake project for Equi, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_library (EquiCore "EquiCore.cpp" "EquiCore.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EquiCore PROPERTY CXX_STANDARD 20)
endif()

# Tests
