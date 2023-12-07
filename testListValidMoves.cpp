#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <vector>
#include <string>
#include "board.hpp"

TEST_CASE("List Valid Moves", "[listvalidmoves]")
{
        for(auto piece: {"p","r","n","b","k","q"})
            for(auto team: {"w","b"})
                for(auto row: {"1","2","3","4","5","6","7","8"})
                    for(auto column: {"a","b","c","d","e","f","g","h"})
                    {
                        std::vector<std::vector<std::string>> testingBoard(8,std::vector<std::string>(8,"e"));
                        std::string coordinates = std::string(column)+std::string(row);

                        int rowIndex    = int(row[0])    - 49;
                        int columnIndex = int(column[0]) - 97;

                        // std::cout << "rowIndex: " << rowIndex << std::endl << "columnIndex: " << columnIndex << std::endl << std::endl;
                        testingBoard.at(rowIndex).at(columnIndex) = std::string(team)+std::string(piece);

                        board b(testingBoard);

                        std::cout << "Coordinates: " << coordinates << std::endl;
                        std::cout << "Piece: " << b.getPieceInSquare(coordinates) << std::endl;
                        
                        std::vector<std::string> validMoves = b.listValidMoves(coordinates);
                        
                        if(!validMoves.empty())
                        {
                            std::cout << "Valid Moves: ";
                            for(auto move: validMoves)
                                std::cout << move << " ";
                            std::cout << std::endl << std::endl;
                        }
                        CHECK(!validMoves.empty());
                    }
}