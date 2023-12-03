#include <catch2/catch_test_macros.hpp>

#include <utility>
#include "../board/board.hpp"

TEST_CASE("Decode piece name", "[decodepiecename]")
{
    board b;

    CHECK((b.decodePieceName("wp")) == (std::pair<char,char>('w','p')));
    CHECK((b.decodePieceName("wr")) == (std::pair<char,char>('w','r')));
    CHECK((b.decodePieceName("wn")) == (std::pair<char,char>('w','n')));
    CHECK((b.decodePieceName("wb")) == (std::pair<char,char>('w','b')));
    CHECK((b.decodePieceName("wk")) == (std::pair<char,char>('w','k')));
    CHECK((b.decodePieceName("wq")) == (std::pair<char,char>('w','q')));
    
    
    CHECK((b.decodePieceName("bp")) == (std::pair<char,char>('b','p')));
    CHECK((b.decodePieceName("br")) == (std::pair<char,char>('b','r')));
    CHECK((b.decodePieceName("bn")) == (std::pair<char,char>('b','n')));
    CHECK((b.decodePieceName("bb")) == (std::pair<char,char>('b','b')));
    CHECK((b.decodePieceName("bk")) == (std::pair<char,char>('b','k')));
    CHECK((b.decodePieceName("bq")) == (std::pair<char,char>('b','q')));


    CHECK((b.decodePieceName("a_")) == (std::pair<char,char>()));
    CHECK((b.decodePieceName("b-")) == (std::pair<char,char>()));
    CHECK((b.decodePieceName("b^")) == (std::pair<char,char>()));
    CHECK((b.decodePieceName("1k")) == (std::pair<char,char>()));
    CHECK((b.decodePieceName("k2")) == (std::pair<char,char>()));
    CHECK((b.decodePieceName("òè")) == (std::pair<char,char>()));
    CHECK((b.decodePieceName("#°")) == (std::pair<char,char>()));
    CHECK((b.decodePieceName("°+")) == (std::pair<char,char>()));
    CHECK((b.decodePieceName("§ù")) == (std::pair<char,char>()));
    CHECK((b.decodePieceName("˘§")) == (std::pair<char,char>()));
    CHECK((b.decodePieceName("{à")) == (std::pair<char,char>()));
    CHECK((b.decodePieceName("}°")) == (std::pair<char,char>()));
    CHECK((b.decodePieceName(")˚")) == (std::pair<char,char>()));
    CHECK((b.decodePieceName("(#")) == (std::pair<char,char>()));
}