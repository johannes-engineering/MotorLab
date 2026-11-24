cmake_minimum_required(VERSION 3.23)

project(MotorLab)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(src/maths)
add_subdirectory(src/model)
add_subdirectory(src/controller)

add_executable(MotorLab
    src/main.cpp
)

target_link_libraries(MotorLab
    PRIVATE
        ModelLib
        Controller
)
