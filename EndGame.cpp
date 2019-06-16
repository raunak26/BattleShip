//
// Created by Raunak Anand on 2019-06-01.
//


#include "BattleShip.hpp"

BattleShip::EndGame::EndGame(Player& moveMaker): moveMaker(moveMaker){

}

void BattleShip::EndGame::shipHealth(Creation& model, View& view) {
  view.showWinner(moveMaker); // shows winner as the current move maker
  model.endGame(); // ends game
}

bool BattleShip::EndGame::isValid() const {
  return moveMaker.StatusSunk() ? true : moveMaker.getOpponent().StatusSunk();
  // end game is only valid if either players' all ships sank
}