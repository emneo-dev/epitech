cmake_minimum_required(VERSION 3.16)
project(nanotekspice)

set(CMAKE_CXX_STANDARD 14)

file(GLOB PROJ_SRC
        "src/*.cpp"
        )

add_executable(nanotekspice
        ${PROJ_SRC})

target_include_directories(nanotekspice PRIVATE ./include)