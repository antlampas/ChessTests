#include "catch2/catch_test_macros.hpp"

#include <iostream>
#include <algorithm>
#include "board.hpp"

TEST_CASE("Is Diagonal Clogged?", "[isdiagonalclogged]")
{
    boardMapType boardMap = boardMapType(8,columnType(8,squareType("e")));

    boardMap.at(2).at(2) = "br";
    boardMap.at(5).at(5) = "wk";
    boardMap.at(4).at(4) = "bq";
    boardMap.at(2).at(5) = "bp";
    boardMap.at(5).at(2) = "bp";
    boardMap.at(0).at(1) = "bp";
    boardMap.at(0).at(4) = "wp";
    boardMap.at(6).at(3) = "wp";
    boardMap.at(7).at(7) = "wp";

    board b(boardMap);
    
    boardMapType currentBoard = b.boardStatus();
    
    CHECK_FALSE(b.isDiagonalClogged("b1","e4"));
    CHECK(b.isDiagonalClogged("a1","e5"));
}