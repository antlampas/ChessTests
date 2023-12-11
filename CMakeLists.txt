find_package(Catch2 3 REQUIRED)

add_executable(tests
                testBoard.cpp
                testBoardStatus.cpp
                testDecodeCoordinates.cpp
                testDecodePieceName.cpp
                testEncodeCoordinates.cpp
                testGetPieceInSquare.cpp
                testIsColumnClogged.cpp
                testIsCoordinateValid.cpp
                testIsDiagonalClogged.cpp
#                testIsFrontClogged.cpp
#                testIsMoveClogged.cpp
                testIsMoveValid.cpp
#                testIsPieceNameValid.cpp
#                testIsRowClogged.cpp
                testListValidMoves.cpp
                testMove.cpp
            )

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(tests PUBLIC board)