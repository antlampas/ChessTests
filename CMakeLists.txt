include(ExternalProject)

cmake_minimum_required(VERSION 3.15)

project(ChessTests DESCRIPTION "Tests for FALPChess" HOMEPAGE_URL "https://github.com/antlampas/ChessTests" LANGUAGES "CXX")

ExternalProject_Add(catch2 PREFIX "src" GIT_REPOSITORY  "https://github.com/catchorg/Catch2" GIT_PROGRESS true)
ExternalProject_Add(chess  PREFIX "src" GIT_REPOOSITORY "https://github.com/antlampas/Chess" GIT_PROGRESS true)

if("${CMAKE_BUILD_TYPE}" MATCHES "Debug")
    add_definitions(-DDEBUG)
endif()

include_directories(include)

add_subdirectory(src ${CMAKE_BUILD_TYPE})