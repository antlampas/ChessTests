#include "catch2/catch_test_macros.hpp"

#include "board.hpp"

TEST_CASE("Is Coordinate Valid?", "[iscoordinatevalid]")
{
    board b;

    std::vector<std::string> validCoordinates;
    //std::vector<std::string> notValidCoordinates;

    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
        {
            const char& column = char(i+97);
            const char& row    = char(j+49);
            validCoordinates.push_back(std::string(1,column)+std::string(1,row));

            CHECK(b.isCoordinateValid(validCoordinates.at(i+j)) == true);
        }
}