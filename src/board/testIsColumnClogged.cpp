#include "catch2/catch_test_macros.hpp"

#include <iostream>
#include <algorithm>
#include "board.hpp"

TEST_CASE("Is Column Clogged?", "[iscolumnclogged]")
{
    boardMapType boardMap = boardMapType(8,columnType(8,squareType("e")));

    boardMap.at(0).at(0) = "wr";
    boardMap.at(3).at(0) = "wp";
    boardMap.at(7).at(0) = "wq";
    boardMap.at(0).at(3) = "bp";
    boardMap.at(3).at(3) = "wp";
    boardMap.at(7).at(3) = "wp";
    boardMap.at(0).at(7) = "wp";
    boardMap.at(3).at(7) = "wp";
    boardMap.at(7).at(7) = "wp";

    board b(boardMap);
    
    boardMapType currentBoard = b.boardStatus();
    
    CHECK(b.isColumnClogged("a1","a7"));
    CHECK(b.isColumnClogged("d1","d7"));
    CHECK_FALSE(b.isColumnClogged("a1","a4"));
    CHECK_FALSE(b.isColumnClogged("a4","a7"));
    CHECK_FALSE(b.isColumnClogged("d1","d4"));
    CHECK_FALSE(b.isColumnClogged("d4","d7"));
    CHECK_FALSE(b.isColumnClogged("a1","a3"));
    CHECK_FALSE(b.isColumnClogged("a4","a6"));
    CHECK_FALSE(b.isColumnClogged("b1","b7"));
}