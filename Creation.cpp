//
// Created by Raunak Anand on 2019-06-01.
//

#include "BattleShip.hpp"


void BattleShip::Creation::fileArguments(const std::string& gameConfigurationFile) {
  int numRows, numCols, shipLen, numOfShips;
  char shipName;
  std::map<char, int> shipAttributes;
  std::ifstream infile(gameConfigurationFile);

  infile >> numRows >> numCols >> numOfShips;

  (*this).gameArguments = Game(numRows, numCols);

  while (infile >> shipName >> shipLen) {
    shipAttributes[shipName] = shipLen;
  }
  (*this).gameArguments.setShipParameters(shipAttributes);
}

void BattleShip::Creation::changeTurn() {
  if (playerTurn == 0) {
    playerTurn = 1;
  } else {
    playerTurn = 0;
  }
}

BattleShip::Player& BattleShip::Creation::getAttackingPlayer() {
  if (playerTurn == 0) {
    return *players[0].get();
  } else {
    return *players[1].get();
  }
} // Get the current attacking player

const BattleShip::Player& BattleShip::Creation::getAttackingPlayer() const {
  if (playerTurn == 0) {
    return *players[0].get();
  } else {
    return *players[1].get();
  }
} // Get the current attacking player

// Get the current defending player
BattleShip::Player& BattleShip::Creation::getDefendingPlayer() {
  if (playerTurn == 0) {
    return *players[1].get();
  } else {
    return *players[0].get();
  }
} // Get the current defending player

const BattleShip::Player& BattleShip::Creation::getDefendingPlayer() const {
  if (playerTurn == 0) {
    return *players[1].get();
  } else {
    return *players[0].get();
  }
} // Get the current defending player as a constant

void BattleShip::Creation::endGame() {
  forcedEndGame = true;
}

void BattleShip::Creation::SetOpponents() {
  (*players[0].get()).setOpponent(*players[1].get());
  (*players[1].get()).setOpponent(*players[0].get());
}

BattleShip::Player& BattleShip::Creation::getWinner() {
  if (playerTurn == 0) {
    return *players[1].get();
  } else {
    return *players[0].get();
  }
}

bool BattleShip::Creation::isGameOver() const {
  return players[0].get()->StatusSunk() ? true : (*players[1].get()).StatusSunk();
}

BattleShip::Game BattleShip::Creation::getGameArguments() {
  return gameArguments;
}

std::unique_ptr<BattleShip::Move> BattleShip::Creation::getNextMove() {
  return std::unique_ptr<BattleShip::Move>();
}

