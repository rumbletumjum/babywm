cmake_minimum_required(VERSION 3.21)
project(babywm C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(X11 REQUIRED)

add_executable(babywm babywm.c)
target_link_libraries(babywm ${X11_LIBRARIES})
