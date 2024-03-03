cmake_minimum_required(VERSION 3.8.0)

add_executable(33_3_register_of_data_on_templates main.cpp ${MY_INCLUDE_DIR}/register.h register.cpp)


target_include_directories(33_3_register_of_data_on_templates PUBLIC ${MY_INCLUDE_DIR})