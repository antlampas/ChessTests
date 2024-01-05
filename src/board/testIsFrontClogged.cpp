#include "catch2/catch_test_macros.hpp"

#include <iostream>
#include <algorithm>
#include "board.hpp"

TEST_CASE("Is Front Clogged?", "[isfrontclogged]")
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
    std::for_each(currentBoard.rbegin(),currentBoard.rend(),[](columnType column){std::for_each(column.begin(),column.end(),[](squareType square){square!="e" ? std::cout << square << " " : std::cout << square << "  ";}); std::cout << std::endl;});

    CHECK(b.isFrontClogged("c2","c3"));
    CHECK(b.isFrontClogged("h7","h8"));
    CHECK(b.isFrontClogged("c5","c6"));
    CHECK_FALSE(b.isFrontClogged("a1","a2"));
    CHECK_FALSE(b.isFrontClogged("c3","c4"));
    CHECK_FALSE(b.isFrontClogged("e5","e6"));
}