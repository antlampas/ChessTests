#include <catch2/catch_test_macros.hpp>

#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include "board.hpp"

TEST_CASE("Decode Coordinates", "[decodecoordinates]")
{
    board b;

    std::vector<std::string> coordinates;

    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
        {
            const char& column = char(i+97);
            const char& row    = char(j+49);
            coordinates.push_back(std::string(1,column)+std::string(1,row));
            
            CHECK((b.decodeCoordinates(coordinates.at(i+j))) == (std::pair<int,int>(i,j)));
        }
}