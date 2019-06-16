//
// Created by Raunak Anand on 2019-06-01.
//

#ifndef BATTLESHIP_CHEATINGAI_H
#define BATTLESHIP_CHEATINGAI_H
#include "AiPlayer.h"

namespace BattleShip {
class CheatingAi  : public AiPlayer { // if AiPlayer chosen to be cheating AI
 public:
  std::unique_ptr<Move> getMove() override;
  CheatingAi(const Game& gameAttributes, View& view);
 protected:
  // member variables
  std::vector<std::pair<int, int>> firingLocations;
  bool declareMove;
  int numColumns, numRows;
};
}

#endif //BATTLESHIP_CHEATINGAI_H
