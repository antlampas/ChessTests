# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/run/media/francesco/3997c5e4-723d-463a-9aea-52fb76423e07/Varie/Sorgenti/miei/Progetti C++/ChessTests/Chess/src/chess"
  "/run/media/francesco/3997c5e4-723d-463a-9aea-52fb76423e07/Varie/Sorgenti/miei/Progetti C++/ChessTests/Chess/src/chess-build"
  "/run/media/francesco/3997c5e4-723d-463a-9aea-52fb76423e07/Varie/Sorgenti/miei/Progetti C++/ChessTests/Chess"
  "/run/media/francesco/3997c5e4-723d-463a-9aea-52fb76423e07/Varie/Sorgenti/miei/Progetti C++/ChessTests/Chess/tmp"
  "/run/media/francesco/3997c5e4-723d-463a-9aea-52fb76423e07/Varie/Sorgenti/miei/Progetti C++/ChessTests/Chess/src/chess-stamp"
  "/run/media/francesco/3997c5e4-723d-463a-9aea-52fb76423e07/Varie/Sorgenti/miei/Progetti C++/ChessTests/Chess/src"
  "/run/media/francesco/3997c5e4-723d-463a-9aea-52fb76423e07/Varie/Sorgenti/miei/Progetti C++/ChessTests/Chess/src/chess-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/run/media/francesco/3997c5e4-723d-463a-9aea-52fb76423e07/Varie/Sorgenti/miei/Progetti C++/ChessTests/Chess/src/chess-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/run/media/francesco/3997c5e4-723d-463a-9aea-52fb76423e07/Varie/Sorgenti/miei/Progetti C++/ChessTests/Chess/src/chess-stamp${cfgdir}") # cfgdir has leading slash
endif()
