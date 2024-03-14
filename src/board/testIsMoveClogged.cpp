#include "catch2/catch_test_macros.hpp"

#include <iostream>
#include <algorithm>
#include "board.hpp"

TEST_CASE("Is Move Clogged?", "[ismoveclogged]")
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
    
    CHECK_FALSE(b.isMoveClogged("c3","c8"));
    CHECK_FALSE(b.isMoveClogged("f6","f7"));
    CHECK_FALSE(b.isMoveClogged("e5","e6"));
    CHECK_FALSE(b.isMoveClogged("f3","f4"));
    CHECK_FALSE(b.isMoveClogged("c6","c7"));
    CHECK_FALSE(b.isMoveClogged("b1","b2"));
    CHECK_FALSE(b.isMoveClogged("e1","e2"));
    CHECK_FALSE(b.isMoveClogged("d7","d8"));
    CHECK_FALSE(b.isMoveClogged("h8","g8"));
}