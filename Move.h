//
// Created by Raunak Anand on 2019-06-01.
//

#ifndef BATTLESHIP_MOVE_H
#define BATTLESHIP_MOVE_H
#include "Player.h"
#include "Creation.h"
#include "View.h"

namespace BattleShip {
class Player;
class AiPlayer;
class HumanPlayer;
class Creation;
class View;

class Move {
 public:
  Move();
  virtual ~Move()= default;

  Move(Player& moveMaker);
  // Performs the current move
  virtual void shipHealth(Creation& model, View& view) = 0;
  virtual void shipHealth(Player& defender, View& view) = 0;

  virtual bool isValid() const = 0;
  // Checks whether the current move is valid or not

  virtual int getRowAttack() const = 0;
  virtual int getColAttack() const = 0;
  virtual bool didItHit() = 0;

 protected:
  Player& moveMaker;
};
}

#endif //BATTLESHIP_MOVE_H