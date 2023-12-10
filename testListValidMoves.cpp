#include <catch2/catch_test_macros.hpp>

#include <random>
#include <algorithm>
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

                        testingBoard.at(rowIndex).at(columnIndex) = std::string(team)+std::string(piece);

                        board b(testingBoard);

                        std::vector<std::string> validMoves = b.listValidMoves(coordinates);

                        if(!(team == "w" && piece == "p" && row == "8") && !(team == "b" && piece == "p" && row == "1"))
                            CHECK(!validMoves.empty());
                        else
                            CHECK(validMoves.empty());
                    }
        
        std::random_device r;
        std::mt19937 g(r());

        std::vector<std::string> whitePawns(8,"wp");
        std::vector<std::string> blackPawns(8,"bp");
        std::vector<std::string> pieces {"wp","wp","wp","wp","wp","wp","wp","wp","wr","wr","wn","wn","wb","wb","wk","wq","bp","bp","bp","bp","bp","bp","bp","bp","br","br","bn","bn","bb","bb","bk","bq"};

        std::shuffle(pieces.begin(),pieces.end(),g);

        boardMapType randomBoard = boardMapType(8,std::vector<std::string>(8,std::string("e")));

        for(auto p: pieces)
            randomBoard.at(r()%8).at(r()%8) = p;

        board b(randomBoard);

        for(auto row: {"1","2","3","4","5","6","7","8"})
            for(auto column: {"a","b","c","d","e","f","g","h"})
            {
                std::string coordinates = std::string(column)+std::string(row);
                std::vector<std::string> validMoves = b.listValidMoves(coordinates);
                char team  = b.getPieceInSquare(coordinates).at(0);
                char piece = b.getPieceInSquare(coordinates).at(1);

                if(!(team == 'w' && piece == 'p' && row == '8') && !(team == 'b' && piece == 'p' && row == '1'))
                    CHECK(!validMoves.empty());
                else
                    CHECK(validMoves.empty());
            }
}