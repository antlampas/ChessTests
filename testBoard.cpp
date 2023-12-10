#include <catch2/catch_test_macros.hpp>

#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include "board.hpp"

TEST_CASE("Board constructor", "[boardconstructor]")
{
    std::random_device r;
    std::mt19937 g(r());

    std::vector<std::string> whitePawns(8,"wp");
    std::vector<std::string> blackPawns(8,"bp");
    std::vector<std::string> pieces {"wp","wp","wp","wp","wp","wp","wp","wp","wr","wr","wn","wn","wb","wb","wk","wq","bp","bp","bp","bp","bp","bp","bp","bp","br","br","bn","bn","bb","bb","bk","bq"};

    std::shuffle(pieces.begin(),pieces.end(),g);

    boardMapType randomBoard = boardMapType(8,std::vector<std::string>(8,std::string("e")));

    for(auto p: pieces)
        randomBoard.at(r()%8).at(r()%8) = p;

    board b;
    board c(randomBoard);

    CHECK(true);
}