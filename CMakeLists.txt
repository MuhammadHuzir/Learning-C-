cmake_minimum_required(VERSION 4.1)
project(Learning_C__)

set(CMAKE_CXX_STANDARD 20)

add_executable(calculator calculator.cpp)
add_executable(file_based_system file_based_system.cpp)
add_executable(student_info_system main.cpp student_info_system.cpp)
add_executable(guess_number guess_number.cpp)
add_executable(class_based_guessing_number class_based_guessing_number.cpp)