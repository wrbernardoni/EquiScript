# CMakeList.txt : CMake project for Equi, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Equi "Equi.cpp" "Equi.h")

target_link_libraries(Equi PUBLIC EquiCore)
target_include_directories(Equi PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/EquiCore")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Equi PROPERTY CXX_STANDARD 20)
endif()

# Tests
add_test(NAME Equi.Equi.Runs COMMAND Equi -v)
