//
// Created by Raunak Anand on 2019-06-01.
//
#include "BattleShip.hpp"

BattleShip::CheatingAi::CheatingAi(const Game& gameAttributes, View& view) : AiPlayer(gameAttributes, view) {
  numColumns = gameAttributes.getNumCols();
  numRows = gameAttributes.getNumRows();
  declareMove = true;
}

std::unique_ptr<BattleShip::Move> BattleShip::CheatingAi::getMove() {
  if (declareMove) {
    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numColumns; j++) {
        if (this->getOpponent().getBoard().at(i, j).shipIsThere()) {
          firingLocations.emplace_back(i, j);
        }
      }
    }
    declareMove = false;
  }

  int attackRow = firingLocations[0].first;
  int attackCol = firingLocations[0].second;

  if (!firingLocations.empty()) {
    firingLocations.erase(firingLocations.begin());
  }
  std::unique_ptr<BattleShip::Move> move(new AttackMove(*this, attackRow, attackCol));
  return move;
}