cmake_minimum_required(VERSION 3.2)
project(Pong)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Source/main.cpp Source/Bat.cpp Source/Bat.h Source/Ball.cpp Source/Ball.h)
add_executable(Pong ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Pong ${SFML_LIBRARIES})
endif()