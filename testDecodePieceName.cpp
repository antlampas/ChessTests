#include <catch2/catch_test_macros.hpp>

#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include "board.hpp"

TEST_CASE("Decode piece name", "[decodepiecename]")
{
    board b;
    std::vector<char> pieces {'p','r','n','b','k','q'};
    std::vector<std::string> whitePieces {"wp","wr","wn","wb","wk","wq"};
    std::vector<std::string> blackPieces {"bp","br","bn","bb","bk","bq"};
    std::vector<std::string> wrongPieces {"a","b","p","_","é","è","+","˚}","ì'","-",",.","òàù","132"};

    for(std::pair<std::vector<std::string>::iterator,std::vector<char>::iterator> iter{whitePieces.begin(),pieces.begin()};iter.first!=whitePieces.end(),iter.second!=pieces.end();iter.first++,iter.second++)
        CHECK((b.decodePieceName(*iter.first)) == (std::pair<char,char>('w',*iter.second)));
    for(std::pair<std::vector<std::string>::iterator,std::vector<char>::iterator> iter{blackPieces.begin(),pieces.begin()};iter.first!=blackPieces.end(),iter.second!=pieces.end();iter.first++,iter.second++)
        CHECK((b.decodePieceName(*iter.first)) == (std::pair<char,char>('b',*iter.second)));
    for(auto p=wrongPieces.begin();p!=wrongPieces.end();p++)
        CHECK((b.decodePieceName(*p)) == (std::pair<char,char>()));
}