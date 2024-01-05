#include "catch2/catch_test_macros.hpp"

#include "board.hpp"

TEST_CASE("Move", "[move]")
{
    board b;
    
    CHECK(b.move("a1","b2") == false);
    CHECK(b.move("a1","a2") == false);
    CHECK(b.move("b2","b3") == true);
    CHECK(b.move("c1","b2") == true);
    CHECK(b.move("b1","a3") == true);
}