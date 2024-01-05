include(ExternalProject)
include(FetchContent)

cmake_minimum_required(VERSION 3.15)

project(ChessTests DESCRIPTION "Tests for FALPChess" HOMEPAGE_URL "https://github.com/antlampas/ChessTests" LANGUAGES "CXX")

FetchContent_Declare(catch2 PREFIX "src" GIT_REPOSITORY "https://github.com/catchorg/Catch2.git" GIT_TAG "devel" GIT_PROGRESS true)
FetchContent_Declare(chess  PREFIX "src" GIT_REPOSITORY "https://github.com/antlampas/Chess.git" GIT_TAG "main"  GIT_PROGRESS true)

FetchContent_MakeAvailable(catch2 chess)

if("${CMAKE_BUILD_TYPE}" MATCHES "Debug")
    add_definitions(-DDEBUG)
endif()

if(BOARD)
    add_definitions(-DTESTBOARD)
endif(BOARD)

if(TIMER)
    add_definitions(-DTESTTIMER)
endif(TIMER)

if(TURNMANAGER)
    add_definitionS(-DTESTTURNMANAGER)
endif(TURNMANAGER)

include_directories(include)

add_subdirectory(src ${CMAKE_BUILD_TYPE})