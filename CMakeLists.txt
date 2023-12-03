cmake_minimum_required(VERSION 3.27.7)

find_package(Catch2 3 REQUIRED)

add_executable(tests 
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