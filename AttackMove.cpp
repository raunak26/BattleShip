//
// Created by Raunak Anand on 2019-06-01.
//

#include "BattleShip.hpp"

BattleShip::AttackMove::AttackMove(BattleShip::Player& attacker, int row, int column) : Move(attacker), row(row), column(column) {

}

const int BattleShip::AttackMove::getRow() const {
  return row;
}

const int BattleShip::AttackMove::getCol() const {
  return column;
}

bool BattleShip::AttackMove::isValid() const {
  return (column >= moveMaker.getBoard().getNumCols() || row >= moveMaker.getBoard().getNumRows() || row < 0
      || column < 0);
}

void BattleShip::AttackMove::shipHealth(BattleShip::Creation& model, BattleShip::View& view) {
  if (model.getDefendingPlayer().getBoard().at(row, column).shipIsThere()) {
    model.getDefendingPlayer().getBoard().at(row, column).setContents(model.getDefendingPlayer().getBoard().at(row,
                                                                                                               column).gethit());
    hit = true;
  } else {
    model.getDefendingPlayer().getBoard().at(row, column).setContents(model.getDefendingPlayer().getBoard().at(row,
                                                                                                               column).getmiss());
    hit = false;
  }
}

void BattleShip::AttackMove::shipHealth(BattleShip::Player& defender, BattleShip::View& view) {
  if (defender.getBoard().at(row, column).shipIsThere()) {
    defender.shipHealths[defender.getBoard().at(row, column).getContents()] -= 1;
    defender.getBoard().at(row, column).setalreadyFiredAt(true);
  }
  defender.getBoard().at(row, column).setalreadyFiredAt(true);
}

int BattleShip::AttackMove::getColAttack() const {
  return column;
}

int BattleShip::AttackMove::getRowAttack() const {
  return row;
}

bool BattleShip::AttackMove::didItHit() {
  return Move::moveMaker.getOpponent().getBoard().at(getRow(), getCol()).shipIsThere();
}