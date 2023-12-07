#include <catch2/catch_test_macros.hpp>

#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include "board.hpp"

TEST_CASE("Decode Piece Name", "[decodepiecename]")
{
    using inBoardPieceType = std::vector<std::string>;
    using PieceType        = std::vector<char>;
    using doubleIterator   = std::pair<inBoardPieceType::iterator,PieceType::iterator>;

    board b;
    PieceType pieces {'p','r','n','b','k','q'};
    inBoardPieceType whitePieces {"wp","wr","wn","wb","wk","wq"};
    inBoardPieceType blackPieces {"bp","br","bn","bb","bk","bq"};
    inBoardPieceType wrongPieces {"a","b","p","_","é","è","+","˚}","ì'","-",",.","òàù","132"};

    for(doubleIterator iter(whitePieces.begin(),pieces.begin());iter.first!=whitePieces.end() && iter.second!=pieces.end();iter.first++,iter.second++)
        CHECK((b.decodePieceName(*iter.first)) == (std::pair<char,char>('w',*iter.second)));
    for(doubleIterator iter(blackPieces.begin(),pieces.begin());iter.first!=blackPieces.end() && iter.second!=pieces.end();iter.first++,iter.second++)
        CHECK((b.decodePieceName(*iter.first)) == (std::pair<char,char>('b',*iter.second)));
    for(auto p=wrongPieces.begin();p!=wrongPieces.end();p++)
        CHECK((b.decodePieceName(*p)) == (std::pair<char,char>()));
}