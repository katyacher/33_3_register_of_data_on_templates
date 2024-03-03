cmake_minimum_required(VERSION 3.8.0)
project(33_3_register_of_data_on_templates VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
add_subdirectory(src)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

