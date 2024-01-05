include(ExternalProject)

#find_package(Catch2 3 REQUIRED)

cmake_minimum_required(VERSION 3.15)

project(ChessTests DESCRIPTION "Tests for FALPChess" HOMEPAGE_URL "https://github.com/antlampas/ChessTests" LANGUAGES "CXX")

ExternalProject_Add(chess PREFIX "${CHESSPREFIX}")

if("${CMAKE_BUILD_TYPE}" MATCHES "Debug")
    add_definitions(-DDEBUG)
endif()

include_directories(include)

add_subdirectory(src ${CMAKE_BUILD_TYPE})