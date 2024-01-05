#include "catch2/catch_test_macros.hpp"

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
            const char& row    = char(i+49);
            const char& column = char(j+97);
            coordinates.push_back(std::string(1,column)+std::string(1,row));
        }
    
    std::vector<std::string>::iterator c = coordinates.begin();

    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            if(c!= coordinates.end())
            {
                std::pair<int,int> decodedCoordinates {b.decodeCoordinates(*c)};
                std::pair<int,int> checkCoordinates {i,j};
                c++;
                CHECK(((decodedCoordinates.first == checkCoordinates.first) && (decodedCoordinates.second == checkCoordinates.second)) == true);
            }
}