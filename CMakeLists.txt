cmake_minimum_required(VERSION 3.21)
project(babywm C)

set(CMAKE_C_STANDARD 99)

find_package(X11 REQUIRED)

add_executable(bwm babywm.c)
target_link_libraries(bwm ${X11_LIBRARIES})
