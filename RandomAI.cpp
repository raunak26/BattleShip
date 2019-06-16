//
// Created by Raunak Anand on 2019-06-01.
//

#include "BattleShip.hpp"

std::unique_ptr<BattleShip::Move> BattleShip::RandomAI::getMove() {
  std::pair<int, int> pos = *chooseRandom(firingLocations, randomNumberGenerator);
  firingLocations.erase(std::remove(firingLocations.begin(), firingLocations.end(), pos), firingLocations.end());
  std::unique_ptr<BattleShip::Move> move(new AttackMove(*this, pos.first, pos.second));
  return move;
}


BattleShip::RandomAI::RandomAI(const Game& gameAttributes, View& view) : AiPlayer(gameAttributes, view) {
  int numCols = gameAttributes.getNumCols();
  int numRows = gameAttributes.getNumRows();
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numCols; j++) {
      firingLocations.emplace_back(i, j);
    }
  }
}
