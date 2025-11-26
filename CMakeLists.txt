cmake_minimum_required(VERSION 3.10)
project(helloworld LANGUAGES CXX)

# -----------------------------------
# Пути к Boost
# -----------------------------------
set(BOOST_ROOT "C:/boost_1_89_0")
set(BOOST_INCLUDEDIR "${BOOST_ROOT}/include")
set(BOOST_LIBRARYDIR "${BOOST_ROOT}/stage/lib")

# -----------------------------------
# BUILD_NUMBER
# -----------------------------------
if(NOT DEFINED BUILD_NUMBER)
  set(BUILD_NUMBER 0 CACHE STRING "Build number")
endif()

# Генерация version.h
configure_file(${CMAKE_SOURCE_DIR}/include/version.h.in ${CMAKE_BINARY_DIR}/generated/version.h @ONLY)
include_directories(${CMAKE_BINARY_DIR}/generated)

# -----------------------------------
# Библиотека helloworld_lib
# -----------------------------------
add_library(helloworld_lib src/lib.cpp)
target_include_directories(helloworld_lib PUBLIC 
    ${CMAKE_BINARY_DIR}/generated
    ${CMAKE_SOURCE_DIR}/src
)

# -----------------------------------
# Исполняемый файл helloworld
# -----------------------------------
add_executable(helloworld src/main.cpp)
target_link_libraries(helloworld PRIVATE helloworld_lib)
target_include_directories(helloworld PRIVATE 
    ${CMAKE_BINARY_DIR}/generated
    ${CMAKE_SOURCE_DIR}/src
)

# -----------------------------------
# Тесты с Boost.Test
# -----------------------------------
find_package(Boost 1.89 REQUIRED COMPONENTS unit_test_framework)

enable_testing()

add_executable(test_version tests/test_version.cpp)
target_link_libraries(test_version PRIVATE helloworld_lib Boost::unit_test_framework)
target_include_directories(test_version PRIVATE 
    ${CMAKE_BINARY_DIR}/generated
    ${CMAKE_SOURCE_DIR}/src
)

add_test(NAME version_test COMMAND test_version)

# -----------------------------------
# Сообщение о пути к Boost
# -----------------------------------
message(STATUS "Boost include dir: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost libraries: ${Boost_LIBRARIES}")
