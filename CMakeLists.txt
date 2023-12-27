find_package(Catch2 3 REQUIRED)

cmake_minimum_required(VERSION 3.15)

project(ChessTests DESCRIPTION "Tests for FALPChess" HOMEPAGE_URL "https://github.com/antlampas/ChessTests" LANGUAGES "CXX")

if("${CMAKE_BUILD_TYPE}" MATCHES "Debug")
    add_definitions(-DDEBUG)
endif()

get_directory_property(MYDEFS COMPILE_DEFINITIONS)

if("${MYDEFS}" MATCHES "TESTBOARD")
    add_subdirectory(board)
endif()
if("${MYDEFS}" MATCHES "TESTTIMER")
    add_subdirectory(timer)
endif()
if("${MYDEFS}" MATCHES "TESTTURNMANAGER")
    add_subdirectory(turnManager)
endif()

include_directories(include)

add_subdirectory(src ${CMAKE_BUILD_TYPE})