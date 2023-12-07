#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <vector>
#include <string>
#include "board.hpp"

TEST_CASE("List Valid Moves", "[listvalidmoves]")
{
    std::vector<std::vector<std::string>> testingBoard(8,std::vector<std::string>(8,"e"));

    for(auto row: {"1","2","3","4","5","6","7","8"})
        for(auto column: {"a","b","c","d","e","f","g","h"})
            for(auto team: {"w","b"})
                for(auto piece: {"p","r","n","b","k","q"})
                {
                    testingBoard.at(row).at(column) = team+piece;
                    
                    board b(testingBoard);

                    std::string coordinates = column+row;

                    int rowIndex    = int(row)    - 49;
                    int columnIndex = int(column) - 97;

                    std::vector<std::string> validMoves = b.listValidMoves(coordinates);

                    if(!validMoves.empty())
                    {
                        for(auto move: validMoves)
                            std::cout << move << " ";
                        std::cout << std::endl;
                    }
                    CHECK(!validMoves.empty());
                }
        



    // board b;

    // for(auto coordinates: {"a2","b2","c2","d2","e2","f2","g2","h2"})
    // {
    //     std::vector<std::string> validMoves = b.listValidMoves(coordinates);
    //     if(!validMoves.empty())
    //     {
    //         for(auto move: validMoves)
    //             std::cout << move << " ";
    //         std::cout << std::endl;
    //     }
    //     CHECK(!validMoves.empty());
    }
}