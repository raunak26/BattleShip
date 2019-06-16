cmake_minimum_required(VERSION 3.13)
project(BattleshipMVC)

set(CMAKE_CXX_STANDARD 14)

#CMakeList help taken from CSIF

add_library(BattleshipMVC STATIC BeginGame.cpp BeginGame.h View.cpp View.h Creation.cpp Creation.h Player.cpp Player.h Move.cpp Move.h HumanPlayer.cpp HumanPlayer.h AiPlayer.cpp AiPlayer.h NumPlayer.cpp NumPlayer.h BoardView.cpp BoardView.h Utility.cpp Utility.h Game.cpp Game.h EndGame.cpp EndGame.h Board.cpp Board.h Ship.cpp Ship.h Grid.cpp Grid.h AttackMove.cpp AttackMove.h DeclareResult.cpp DeclareResult.h CheatingAi.cpp CheatingAi.h RandomAI.cpp RandomAI.h HuntDestroyAI.cpp HuntDestroyAI.h)
target_include_directories(BattleshipMVC PUBLIC .)
target_compile_options(BattleshipMVC PRIVATE ${BATTLESHIP_COMPILE_OPTIONS})
