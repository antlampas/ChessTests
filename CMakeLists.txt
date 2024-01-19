include(FetchContent)

cmake_minimum_required(VERSION 3.15)

FetchContent_Declare(catch2 PREFIX "src" GIT_REPOSITORY "https://github.com/catchorg/Catch2.git" GIT_TAG "devel" GIT_PROGRESS true)
FetchContent_Declare(chess  PREFIX "src" GIT_REPOSITORY "https://github.com/antlampas/Chess.git" GIT_TAG "master"  GIT_PROGRESS true)

FetchContent_MakeAvailable(catch2 chess)

if("${CMAKE_BUILD_TYPE}" MATCHES "Debug")
add_definitions(-DDEBUG)
endif()

string(TOLOWER "${UNITS}" UNITS)

string(FIND "${UNITS}" "board" BOARD)
string(FIND "${UNITS}" "timer" TIMER)
string(FIND "${UNITS}" "turnmanager" TURNMANAGER)

set(CMAKE_BUILD_TYPE "${BUILD}")

project(ChessTests VERSION "${VERSION}" DESCRIPTION "Tests for FALPChess" HOMEPAGE_URL "https://github.com/antlampas/ChessTests" LANGUAGES "CXX")

if(BOARD GREATER -1)
    message("Testing board")
    add_definitions(-DTESTBOARD)
endif(BOARD GREATER -1)

if(TIMER GREATER -1)
    message("Testing timer")
    add_definitions(-DTESTTIMER)
endif(TIMER GREATER -1)

if(TURNMANAGER GREATER -1)
    message("Testing Turn Manager")
    add_definitionS(-DTESTTURNMANAGER)
endif(TURNMANAGER GREATER -1)

include_directories(include)

add_subdirectory(src ${CMAKE_BUILD_TYPE})