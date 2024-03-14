#get_directory_property(MYDEFS COMPILE_DEFINITIONS)

add_executable(boardTests
                testBoard.cpp
                testBoardStatus.cpp
                testDecodeCoordinates.cpp
                testDecodePieceName.cpp
                testEncodeCoordinates.cpp
                testGetPieceInSquare.cpp
                testIsColumnClogged.cpp
                testIsCoordinateValid.cpp
                testIsDiagonalClogged.cpp
                testIsFrontClogged.cpp
                testIsMoveClogged.cpp
                testIsMoveValid.cpp
#                testIsPieceNameValid.cpp
#                testIsRowClogged.cpp
                testListValidMoves.cpp
                testMove.cpp
            )
target_link_libraries(boardTests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(boardTests PUBLIC board)

add_test(NAME boardTests COMMAND boardTests)