# CMakeList.txt : CMake project for Equi, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Equi "Equi.cpp" "Equi.h" "CommandLineParser.h" "CommandLineParser.cpp")

target_link_libraries(Equi PUBLIC EquiCore)
target_include_directories(Equi PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/EquiCore")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Equi PROPERTY CXX_STANDARD 20)
endif()

# Tests
add_test(NAME Equi.Equi.Runs COMMAND Equi -v)

add_test(NAME Equi.Equi.Versioning COMMAND Equi -v)
set_tests_properties(Equi.Equi.Versioning
  PROPERTIES PASS_REGULAR_EXPRESSION "Equi version ${EquiLang_VERSION_MAJOR}.${EquiLang_VERSION_MINOR}"
  )

add_test(NAME Equi.Equi.BadCommandLine COMMAND Equi -v --badcommandargument)
set_property(TEST Equi.Equi.BadCommandLine PROPERTY WILL_FAIL TRUE)
