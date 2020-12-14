cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Example VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#Set include and output directory
set (INCLUDE_DIR "../inc")
include_directories(${INCLUDE_DIR})

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")


#Compile file
add_executable (test ../src/Items.cc ../src/Porte.cc ../src/Not.cc ../src/And2.cc ../src/Stimuli.cc ../src/Or2.cc ../src/test_classe_items.cc ../src/Input.cc ../src/Output.cc)
target_compile_options     (test PUBLIC  -fexceptions -std=c++14)


#Set test for console output

enable_testing()

set (EXPECTED_OUTPUT "0111")
add_test(output_test ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/test)
set_tests_properties(output_test PROPERTIES PASS_REGULAR_EXPRESSION ${EXPECTED_OUTPUT})

#You can add command-line parameters when declaring a test. Ex:
#add_test(output_test ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/test "mon_fichier.dot")
