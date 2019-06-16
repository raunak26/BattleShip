//
// Created by Raunak Anand on 2019-06-01.
//

#ifndef BATTLESHIP_HUMANPLAYER_H
#define BATTLESHIP_HUMANPLAYER_H
#include "Player.h"
#include "View.h"
#include "Game.h"

namespace BattleShip {
class Move; // forward declaration
class Player;

class HumanPlayer : public Player {
 public:
  HumanPlayer(const Game& gameArguments, View& view);

  std::unique_ptr<BattleShip::Move> getMove() override;
  // retrieves the current player's move

  void placeShips() override;
  // Places all of the users ships once the player has inputted all their coordinates
  void initializeName() override;
  // to initialize the name of the players
};
}

#endif //BATTLESHIP_HUMANPLAYER_H
