//
// Created by Raunak Anand on 2019-06-01.
//

#include "BattleShip.hpp"


int BattleShip::Player::instances = 0;


BattleShip::Player::Player(const Game& gameAttributes, View& view) : id(instances), view(view), board(Board(gameAttributes.getNumRows(),gameAttributes.getNumCols())) {
  ++instances;
  shipHealths = gameAttributes.getShipParameters();
}

BattleShip::Player& BattleShip::Player::getOpponent() {
  return *opponent;
}

const BattleShip::Player& BattleShip::Player::getOpponent() const {
  return *opponent;
}

void BattleShip::Player::setOpponent(BattleShip::Player& opponent) {
  (*this).opponent = &opponent;
}

void BattleShip::Player::setName(const std::string& name) {
  (*this).playername = name;
}

const BattleShip::Board& BattleShip::Player::getBoard() const {
  return board;
}

bool BattleShip::Player::operator==(const Player& rhs) const {
  return ((*this).getId() == rhs.getId());
}

const std::string& BattleShip::Player::getName() const {
  return playername;
}

BattleShip::Board& BattleShip::Player::getBoard() {
  return board;
}

bool BattleShip::Player::operator!=(const Player& rhs) const {
  return ((*this).getId() != rhs.getId());
}

bool BattleShip::Player::StatusSunk() const {
  for (auto const &itr: shipHealths) {
    if (itr.second != 0) {
      return false;
    }
  }
  return true;
}

BattleShip::DeclareResult BattleShip::Player::fire(int row, int column){
  std::map<char, int> preAttackHealth = getOpponent().shipHealths;
  auto preIt = preAttackHealth.begin();
  AttackMove attack(*this, row, column);
  attack.shipHealth((*this).getOpponent(), view);
  auto it=getOpponent().shipHealths.begin();
  while(it!=getOpponent().shipHealths.end() && preIt!=preAttackHealth.end()){
    if((*it).second!=(*preIt).second){

      return DeclareResult(true, (*it).second == 0, (*it).first);
    }
    ++it;
    ++preIt;
  }
  return {false, false, '*'};
}


bool BattleShip::Player::hit(char shipChar) {
  return (shipHealths.at(shipChar) != 3);
}

const int BattleShip::Player::getId() const {
  return id;
}

//Ship& Player::operator()(int x, int y) {
//  return getBoard()(y, x);
//}
//
//Player& Player::operator=(const Player &rhs) {
//  if(this != &rhs) {
//    playerType = rhs.playerType;
//    id = rhs.id;
//    turn = rhs.turn;
//    playerBoard = rhs.playerBoard;
//  }
//  return *this;
//}
//
//Player::Player(const Player &rhs) {
//  playerType = rhs.playerType;
//  id = rhs.id;
//  turn = rhs.turn;
//  playerBoard = rhs.playerBoard;
//}
//
//bool Player::operator==(const Player&rhs) {
//  if((playerBoard != rhs.playerBoard) || (playerType != rhs.playerType) || (id != rhs.id) || (turn != rhs.turn)) {
//    return false;
//  }
//  return true;
//}
//
//bool Player::operator!=(const Player& rhs) {
//  return !(*this == rhs);
//}