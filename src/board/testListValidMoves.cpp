#include "catch2/catch_test_macros.hpp"

#include <random>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include "board.hpp"

TEST_CASE("List Valid Moves", "[listvalidmoves]")
{
    boardMapType testingBoard(8,std::vector<std::string>(8,"e"));
    board b(testingBoard);

    std::random_device r;
    std::mt19937 g(r());

    std::vector<std::string> pieces {"wp","wp","wp","wp","wp","wp","wp","wp","wr","wr","wn","wn","wb","wb","wk","wq","bp","bp","bp","bp","bp","bp","bp","bp","br","br","bn","bn","bb","bb","bk","bq"};

    std::shuffle(pieces.begin(),pieces.end(),g);

    for(auto p: pieces)
        testingBoard.at(r()%8).at(r()%8) = p;

    b = std::move(board(testingBoard));

    for(auto row: {"1","2","3","4","5","6","7","8"})
    {
        for(auto column: {"a","b","c","d","e","f","g","h"})
        {
            std::string coordinates {std::string(column)+std::string(row)};
            std::string p {b.getPieceInSquare(coordinates)};
            std::vector<std::string> validMoves {b.listValidMoves(coordinates)};

            if(p != "e")
            {
                char team  {p.at(0)};
                char piece {p.at(1)};

                if(!(team == 'w' && piece == 'p' && row == "8") && !(team == 'b' && piece == 'p' && row == "1"))
                    CHECK(validMoves.empty() == false);
                else
                    CHECK(validMoves.empty() == true);
            }
        }
    }
}