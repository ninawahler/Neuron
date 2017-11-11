cmake_minimum_required (VERSION 2.6)
Project (Brunel)
set(CMAKE_CXX_FLAGS "-W -Wall -pedantic -std=c++11 -g")

enable_testing()
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable (Brunel Neuron.cpp Network.cpp main.cpp)
add_executable (unittest Neuron.cpp Network.cpp unittest.cpp)

target_link_libraries(unittest gtest gtest_main)
add_test(Brunel_unittest unittest)

###### Doxygen generation ######

# We first check if Doxygen is present.
find_package(Doxygen)
if(DOXYGEN_FOUND)

    # We then check if the Doxygen.in configuration file exists
    IF(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/build/Doxyfile)
        message(FATAL_ERROR "Doxygen configuration file is needed to build the documentation:
         - ${CMAKE_CURRENT_SOURCE_DIR}/build/Doxyfile not found.
         - Generate one in the project folder with doxygen -g Doxyfile")
    ENDIF(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/build/Doxyfile)

    # We configure the doxyfile for make.
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/build/Doxyfile ${CMAKE_CURRENT_BINARY_DIR}/build/Doxyfile @ONLY)
    add_custom_target(doc
        ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/build/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
ELSE(DOXYGEN_FOUND)
    message(FATAL_ERROR "Doxygen is needed to build the documentation.")
ENDIF(DOXYGEN_FOUND)
