#include <catch2/catch_test_macros.hpp>

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

    std::vector<std::string> pieces      {"wp","wp","wp","wp","wp","wp","wp","wp","wr","wr","wn","wn","wb","wb","wk","wq","bp","bp","bp","bp","bp","bp","bp","bp","br","br","bn","bn","bb","bb","bk","bq"};
    std::vector<std::string> wrongPieces {"wp","wp","wp","wp","wp","wp","wp","wp","wr","wr","wn","wn","wb","wb","wk","wq","bp","bp","bp","bp","bp","bp","bp","bp","br","br","bn","bn","bb","bb","bk","df"};

    std::shuffle(pieces.begin(),pieces.end(),g);

    board b;
    
    boardMapType randomBoard = boardMapType(8,std::vector<std::string>(8,std::string("e")));

    for(auto p: pieces)
        randomBoard.at(r()%8).at(r()%8) = p;

    board c(randomBoard);

    randomBoard.clear();
    randomBoard = boardMapType(8,std::vector<std::string>(8,std::string("e")));

    for(auto p: wrongPieces)
        randomBoard.at(r()%8).at(r()%8) = p;

    board d(randomBoard);

    boardMapType currentBoard = b.boardStatus();

    std::for_each(currentBoard.begin(),currentBoard.end(),[](columnType column){std::for_each(column.begin(),column.end(),[](squareType square){square!="e" ? std::cout << square << " " : std::cout << square << "  ";}); std::cout << std::endl;});
    
    std::cout << std::endl << std::endl;
    
    currentBoard = c.boardStatus();
    
    std::for_each(currentBoard.begin(),currentBoard.end(),[](columnType column){std::for_each(column.begin(),column.end(),[](squareType square){square!="e" ? std::cout << square << " " : std::cout << square << "  ";}); std::cout << std::endl;});
    
    std::cout << std::endl << std::endl;

    currentBoard = d.boardStatus();
    
    std::for_each(currentBoard.begin(),currentBoard.end(),[](columnType column){std::for_each(column.begin(),column.end(),[](squareType square){square!="e" ? std::cout << square << " " : std::cout << square << "  ";}); std::cout << std::endl;});
    
    CHECK(true);
}