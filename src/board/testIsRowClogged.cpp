#include "catch2/catch_test_macros.hpp"

#include "board.hpp"

TEST_CASE("Is Row Clogged", "[isrowclogged]")
{
    boardMapType testingBoard {boardMapType(8,std::vector<std::string>(8,std::string("e")))};
    
    board b;

    CHECK(false);
}