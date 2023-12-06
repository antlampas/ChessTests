#include <catch2/catch_test_macros.hpp>

#include <string>
#include <utility>
#include <string>
#include <vector>
#include "board.hpp"

TEST_CASE("Encode Coordinates", "[encodecoordinates]")
{
    board b;
    std::vector<char> columnNames {97,98,99,100,101,102,103,104};

    for(auto i: {0,1,2,3,4,5,6,7})
        for(auto j: {0,1,2,3,4,5,6,7})
            CHECK(b.encodeCoordinates(std::pair<int,int>(i,j)) == std::string(1,columnNames.at(j)).append(1,char(i+49)));

    for(auto i: {9,10,11,12,13,14,15,16})
        for(auto j: {9,10,11,12,13,14,15,16})
            CHECK(b.encodeCoordinates(std::pair<int,int>(i,j)) == "");
}