//
// Created by Raunak Anand on 2019-06-01.
//

#ifndef BATTLESHIP_RANDOMAI_H
#define BATTLESHIP_RANDOMAI_H
#include <vector>
#include <algorithm>
#include "AiPlayer.h"

namespace BattleShip {

class RandomAI : public AiPlayer {
 public:
  RandomAI(const Game &gameAttributes, View &view); // Constructor for Random AI with game attributes and view
  // get AI move
  virtual std::unique_ptr<Move> getMove() override;
 protected:
  std::vector<std::pair<int, int>> firingLocations;
};
}

#endif //BATTLESHIP_RANDOMAI_H
