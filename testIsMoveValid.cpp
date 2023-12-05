#include <catch2/catch_test_macros.hpp>

#include "board.hpp"

TEST_CASE("Is move valid?", "[ismovevalid]")
{
    board b;
    
    CHECK(b.isMoveValid("a1","a2") == true);
    CHECK(b.isMoveValid("a1","b1") == true);
    CHECK(b.isMoveValid("a2","b2") == false);
}