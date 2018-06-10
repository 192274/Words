cmake_minimum_required(VERSION 3.2)
project(SFML_Game)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_CXX_FLAGS "-fpermissive -std=c++0x")

set(SOURCE_FILES main.cpp Dictionary.cpp Dictionary.h Game.cpp Game.h Round.cpp Round.h GameGUI.cpp GameGUI.h GameState.h GameDrawable.cpp GameDrawable.h)
add_executable(SFML_Game ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "/home/w/Workplace/SFML_Game/cmake-build-debug/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(SFML_Game ${SFML_LIBRARIES})
endif()