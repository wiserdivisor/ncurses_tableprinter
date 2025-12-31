cmake_minimum_required(VERSION 4.0)
project(tableprinter)

set(CMAKE_CXX_STANDARD 17)

find_package(Curses REQUIRED)
set(CURSES_NEED_WIDE TRUE)
add_executable(tableprinter main.cpp)

target_link_libraries(tableprinter ${CURSES_LIBRARIES})