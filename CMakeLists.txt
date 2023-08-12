cmake_minimum_required(VERSION 3.25)
project(Pong)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(BUILD_SHARED_LIBS OFF)

#Fetch content to get sfml source
include(FetchContent)

add_executable(Pong main.cpp Engine.cpp Engine.h Player.cpp Player.h Ball.cpp Ball.h)

FETCHCONTENT_DECLARE(
        sfml
        GIT_REPOSITORY https://github.com/SFML/SFML
        GIT_TAG 11b73743c42cf7ecd7c596ba83fdbf1150ffa96c # release-2.6.0
)

FetchContent_MakeAvailable(sfml)

target_link_libraries(Pong PRIVATE sfml-graphics)
target_sources(Pong PRIVATE
        main.cpp
        )

if(CMAKE_CXX_COMPILER_ID STREQUAL Clang OR CMAKE_CXX_COMPILER_ID STREQUAL GNU)
    target_compile_options(Pong PRIVATE -Wall -Wextra -Wpedantic)
endif()