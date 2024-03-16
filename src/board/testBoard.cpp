#include "catch2/catch_test_macros.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include "board.hpp"

TEST_CASE("Board constructor", "[boardconstructor]")
{
    std::random_device r;
    std::mt19937 g(r());

    std::vector<std::string> pieces      {};
    std::vector<std::string> wrongPieces {};
    
    for(int i=0;i<7;i++) pieces.push_back("wp");
    pieces.insert(pieces.end(),{"wr","wn","wb","wk","wq","wb","wn","wr"});
    for(int i=0;i<7;i++) pieces.push_back("bp");
    pieces.insert(pieces.end(),{"br","bn","bb","bk","bq","bb","bn","br"});

    for(int i=0;i<7;i++) wrongPieces.push_back("wp");
    wrongPieces.insert(wrongPieces.end(),{"wr","wr","wn","wn","wb","wb","wk","wq"});
    for(int i=0;i<7;i++) wrongPieces.push_back("bp");
    wrongPieces.insert(wrongPieces.end(),{"br","br","bn","bn","bb","bb","bk","bq"});

    std::shuffle(pieces.begin(),pieces.end(),g);

    board b;
    
    boardMapType orderedBoard = boardMapType(8,columnType(8,squareType("e")));
    boardMapType randomBoard  = boardMapType(8,columnType(8,squareType("e")));

    for(int i=0;i<8;i++)
    {
        orderedBoard.at(1).at(i) = "wp";
        orderedBoard.at(6).at(i) = "bp";
    }
    
    orderedBoard.at(0) = std::vector<std::string>{"wr","wn","wb","wk","wq","wb","wn","wr"};
    orderedBoard.at(7) = std::vector<std::string>{"br","bn","bb","bk","bq","bb","bn","br"};

    for(auto row: orderedBoard)
    {
        for(auto column: row)
            std::cout << column << " ";
        std::cout << std::endl;
    }

    for(auto p: pieces)
        randomBoard.at(r()%8).at(r()%8) = p;

    board c(randomBoard);

    CHECK((b.boardStatus()) == (orderedBoard));
    CHECK((c.boardStatus()) == (randomBoard));
    
    randomBoard.clear();
    randomBoard = boardMapType(8,columnType(8,squareType("e")));

    for(auto p: wrongPieces)
        randomBoard.at(r()%8).at(r()%8) = p;

    board d(randomBoard);

    boardMapType currentBoard = b.boardStatus();
    currentBoard = c.boardStatus();
    currentBoard = d.boardStatus();
    
    CHECK(true);
}