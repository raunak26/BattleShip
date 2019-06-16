//
// Created by Raunak Anand on 2019-06-01.
//


#ifndef BATTLESHIP_ENDGAME_H
#define BATTLESHIP_ENDGAME_H
#include "Move.h"

namespace BattleShip{
class EndGame : public Move{
 public:
  explicit EndGame(Player& moveMaker);
  // Constructor for End game with the current move maker
  void shipHealth(Creation& model, View& view) override;
  // game ends by logic
  bool isValid() const override;
  // returns boolean of whether end game is valid or not

 protected:
  // member variables
  Player& moveMaker;
};
}

#endif //BATTLESHIP_ENDGAME_H
