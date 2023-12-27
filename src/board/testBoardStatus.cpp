#include <catch2/catch_test_macros.hpp>

#include <vector>
#include <string>
#include <typeinfo>
#include "board.hpp"

TEST_CASE("Board status", "[boardstatus]")
{
    board b;

    using boardType = std::vector<std::vector<std::string>>;

    CHECK(typeid(b.boardStatus()) == typeid(boardType));
}