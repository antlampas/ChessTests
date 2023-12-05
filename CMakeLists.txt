cmake_minimum_required(VERSION 3.15)

project(ChessTests)

find_package(Catch2 3 REQUIRED)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif (NOT CMAKE_BUILD_TYPE)

add_executable(tests
                testBoard.cpp
                testBoardStatus.cpp
                testDecodeCoordinates.cpp
                testDecodePieceName.cpp
                testGetPieceInSquare.cpp
                testIsColumnClogged.cpp
                testIsCoordinateValid.cpp
                testIsDiagonalClogged.cpp
                testIsFrontClogged.cpp
                testIsMoveClogged.cpp
                testIsMoveValid.cpp
                testIsPieceNameValid.cpp
                testIsRowClogged.cpp
                testListValidMoves.cpp
                testMove.cpp
            )

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(tests PUBLIC board)