cmake_minimum_required(VERSION 3.15)

project(ChessTests
        VERSION "${VERSION}"
        DESCRIPTION "Tests for FALPChess"
        HOMEPAGE_URL "https://github.com/antlampas/ChessTests"
        LANGUAGES "CXX")

include(CTest)
include(FetchContent)

FetchContent_Declare(
  chess
  GIT_REPOSITORY https://github.com/antlampas/Chess.git
  GIT_BRANCH     master
)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.6.0
)

FetchContent_MakeAvailable(chess Catch2)

if("${CMAKE_BUILD_TYPE}" MATCHES "Debug")
add_definitions(-DDEBUG)
endif()

string(TOLOWER "${UNITS}" UNITS)

string(FIND "${UNITS}" "board" BOARD)
string(FIND "${UNITS}" "timer" TIMER)
string(FIND "${UNITS}" "turnmanager" TURNMANAGER)

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
    
include_directories(Chess/include)

add_subdirectory(Catch2 ${CMAKE_BUILD_TYPE}/Catch2)
add_subdirectory(Chess  ${CMAKE_BUILD_TYPE}/Chess)
add_subdirectory(src    ${CMAKE_BUILD_TYPE}/Tests)
