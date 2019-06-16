//
// Created by Raunak Anand on 2019-06-01.
//

#include "BattleShip.hpp"

BattleShip::HuntDestroyAI::HuntDestroyAI(const BattleShip::Game& gameArguments, BattleShip::View& view) : RandomAI(gameArguments, view), huntGameMode(true), shipsToBeDestroyed('\0'){

}

std::vector<std::pair<int, int>> BattleShip::HuntDestroyAI::getArea(const std::pair<int, int>& area) const {
  std::vector<std::pair<int, int>> firingQueue;
  if (area.second - 1 >= 0 && !(getOpponent().getBoard().at(area.first, area.second - 1).alreadyFiredAt())) {
    firingQueue.emplace_back(area.first, area.second - 1);
  }
  if (area.first - 1 >= 0 && !(getOpponent().getBoard().at(area.first - 1, area.second).alreadyFiredAt())) {
    firingQueue.emplace_back(area.first - 1, area.second);
  }
  if (area.second + 1 < getBoard().getNumCols()
      && !(getOpponent().getBoard().at(area.first, area.second + 1).alreadyFiredAt())) {
    firingQueue.emplace_back(area.first, area.second + 1);
  }
  if (area.first + 1 < getBoard().getNumRows()
      && !(getOpponent().getBoard().at(area.first + 1, area.second).alreadyFiredAt())) {
    firingQueue.emplace_back(area.first + 1, area.second);
  }
  return firingQueue;
}

std::unique_ptr<BattleShip::Move> BattleShip::HuntDestroyAI::getMove() { // TODO : Work on this code!!
  if (huntGameMode) {
    std::pair<int, int> pos = *chooseRandom(firingLocations, randomNumberGenerator);
    firingLocations.erase(std::remove(firingLocations.begin(), firingLocations.end(), pos), firingLocations.end());
    std::unique_ptr<BattleShip::Move> move(new AttackMove(*this, pos.first, pos.second));
    bool hitOrNo = (*move).didItHit();
    if (hitOrNo) {
      std::pair<int, int> coordinates((*move).getRowAttack(), (*move).getColAttack());
      huntGameMode = false;
      for (auto const &x:getArea(coordinates)) {
        firingQueue.push_back(x);
      }
      if (firingQueue.empty()) {
        huntGameMode = true;
      }
    }
    return move;
  } else {
    std::pair<int, int> pos = firingQueue.front();
    firingQueue.erase(firingQueue.begin());
    firingLocations.erase(std::remove(firingLocations.begin(), firingLocations.end(), pos), firingLocations.end());
    std::unique_ptr<BattleShip::Move> move(new AttackMove(*this, pos.first, pos.second));
    if ((*move).didItHit()) {
      for (auto const &x:getArea(pos)) {
        firingQueue.push_back(x);
      }
    }
    if (firingQueue.empty()) {
      huntGameMode = true;
    }
    return move;
  }
}


