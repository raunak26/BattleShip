//
// Created by Raunak Anand on 2019-06-01.
//

#ifndef BATTLESHIP_BEGINGAME_H
#define BATTLESHIP_BEGINGAME_H
#include <memory>
#include <string>
#include "Creation.h"
#include "View.h"
#include "Player.h"
#include "Move.h"

namespace BattleShip {
class View;
class Creation;
class BeginGame {
 public:
  BeginGame(bool beginGame); // constructor for whether game will start
  BeginGame();

  void setupGame(const std::string& GameConfigurationFile, int seed);
  // Sets up the game with a game configuration file and a seed for the rng
  void setupGame(const std::string& GameConfigurationFile); // Sets up the game with default randomizer as time

  void setupGame(); // starts the game without any argument; nothing will happen
  void play();

 protected:

  //member variables
  bool beginGame;
  Creation creation;
  std::unique_ptr<View> view;

};
}

#endif //BATTLESHIP_BEGINGAME_H
