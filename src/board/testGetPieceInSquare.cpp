#include <catch2/catch_test_macros.hpp>

#include <string>
#include "board.hpp"

TEST_CASE("Get Piece In Square", "[getpieceinsquare]")
{
    board b;

    for(char i='a';i<'i';i++)
        for(int j=0;j<8;j++)
        {
            std::string piece = b.getPieceInSquare(std::string(1,i).append(1,char(j+49)));
            CHECK((piece == "e" || piece == "wp" || piece == "wr" || piece == "wn" || piece == "wb" || piece == "wk" || piece == "wq" || piece == "bp" || piece == "br" || piece == "bn" || piece == "bb" || piece == "bk" || piece == "bq"));
        }
}