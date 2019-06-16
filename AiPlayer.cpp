//
// Created by mfbut on 3/9/2019.
//

#include "BattleShip.hpp"
int BattleShip::AiPlayer::nextAiId = 1;
std::mt19937 BattleShip::AiPlayer::randomNumberGenerator((time(nullptr)));



BattleShip::AiPlayer::AiPlayer(const BattleShip::Game& gameAttributes, BattleShip::View& view) :
    Player(gameAttributes, view), aiId(AiPlayer::nextAiId) {
  nextAiId++;
}


void BattleShip::AiPlayer::placeShips() {
  std::vector<char> orientation_choice{'h', 'v'};
  const int numRows = getBoard().getNumRows();
  const int numCols = getBoard().getNumCols();

  Ship placement;
  for (const auto &ship : shipHealths) {
    do {
      char orientation = *chooseRandom(orientation_choice, randomNumberGenerator);
      if (orientation == 'h') {
        placement.rowStart = getRandInt(0, numRows - 1, randomNumberGenerator);
        placement.colStart = getRandInt(0, numCols - ship.second, randomNumberGenerator);
        placement.rowEnd = placement.rowStart;
        placement.colEnd = placement.colStart + ship.second - 1;
      } else {
        placement.rowStart = getRandInt(0, numRows - ship.second, randomNumberGenerator);
        placement.colStart = getRandInt(0, numCols - 1, randomNumberGenerator);
        placement.rowEnd = placement.rowStart + ship.second - 1;
        placement.colEnd = placement.colStart;
      }
    } while (!getBoard().canPlaceShipAt(placement));
    getBoard().AddShip(ship.first, placement);
    view.updatePlacementView(*this);
  }
}

void BattleShip::AiPlayer::initializeName() {
  std::stringstream name;
  name << "AI " << aiId;
  setName(name.str());
}

void BattleShip::AiPlayer::seed_random_number_generator(int seed) {
  BattleShip::AiPlayer::randomNumberGenerator.seed(seed);
}