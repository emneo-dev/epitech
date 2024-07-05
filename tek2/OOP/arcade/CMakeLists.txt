cmake_minimum_required(VERSION 3.16)

set(TARGET "arcade")
set(SOURCE "src")
set(NIBBLER "arcade_nibbler")
set(NCURSES "arcade_ncurses")

project(${TARGET}
        VERSION 1.0.0
        DESCRIPTION "Arcaac"
        LANGUAGES CXX)

add_library(${NIBBLER} SHARED ${SOURCE}/Nibbler.cpp)
add_library(${NCURSES} SHARED ${SOURCE}/NCurses.cpp)
set_target_properties(${NIBBLER} PROPERTIES PREFIX "")
set_target_properties(${NCURSES} PROPERTIES PREFIX "")
add_executable(${TARGET}
    ${SOURCE}/main.cpp
    ${SOURCE}/Scene.cpp
    ${SOURCE}/LibraryHandler.cpp
    ${SOURCE}/Entity.cpp
    ${SOURCE}/Nibbler.cpp
    ${SOURCE}/AGame.cpp
    ${SOURCE}/MainMenu.cpp
)

add_custom_command(TARGET ${NCURSES} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy arcade_ncurses.so ../lib/arcade_ncurses.so
)
add_custom_command(TARGET ${NIBBLER} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy arcade_nibbler.so ../lib/arcade_nibbler.so
)
add_custom_command(TARGET ${TARGET} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy arcade ../arcade
)

target_link_libraries(${NCURSES} -lncurses)
target_link_libraries(${TARGET} -ldl)
target_compile_features(${TARGET} PRIVATE cxx_std_14)
target_compile_options(${TARGET} PRIVATE -Wall -Wextra)
target_compile_options(${NIBBLER} PRIVATE -Wall -Wextra)
target_compile_options(${NCURSES} PRIVATE -Wall -Wextra)
