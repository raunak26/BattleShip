//
// Created by Raunak Anand on 2019-06-01.
//

#include "BattleShip.hpp"

BattleShip::HumanPlayer::HumanPlayer(const BattleShip::Game& gameAttributes, BattleShip::View& view): Player(gameAttributes, view){

}

std::unique_ptr<BattleShip::Move> BattleShip::HumanPlayer::getMove() {
  std::pair<int, int> pos = view.getFiringCoordinate(*this);
  return std::make_unique<BattleShip::AttackMove>(*this, pos.first, pos.second);
}

void BattleShip::HumanPlayer::placeShips() {
  for (auto const &itr : shipHealths) {
    Ship shipPlacement = view.getShipPlacement(*this, itr.first, itr.second);
    if (!(*this).getBoard().canPlaceShipAt(shipPlacement)) continue;
    (*this).getBoard().AddShip(itr.first, shipPlacement);
  }
  view.updatePlacementView(*this);
} // function to place every ship


void BattleShip::HumanPlayer::initializeName() {
  (*this).setName(view.getPlayerName(instances));
} // all names in vector get initialized

