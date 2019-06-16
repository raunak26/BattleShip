//
// Created by Raunak Anand on 2019-06-01.
//

#ifndef BATTLESHIP_VIEW_H
#define BATTLESHIP_VIEW_H
#include <unordered_map>
#include "NumPlayer.h"
#include "Ship.h"
#include "Player.h"
#include "DeclareResult.h"

namespace BattleShip {
class Creation;
class Move;
class Player;
class View {
 public:
  virtual ~View(){}
  virtual NumPlayer getPlayerConfiguration() = 0;
  virtual int getAiChoice() = 0;
  virtual std::string getPlayerName(int i) = 0;
  virtual void showPlayersBoard(const Player& player) = 0;
  virtual void showAttackResult(const BattleShip::Player& attacker, const BattleShip::DeclareResult& declareResult) = 0;
  virtual Ship getShipPlacement(const Player& player, char shipChar, int health) = 0;
  virtual void updatePlacementView(const Player& player) = 0;
  virtual std::pair<int, int> getFiringCoordinate(const BattleShip::Player& attacker) = 0;
  virtual void showWinner(const Player& winner) = 0;
  virtual void showPlacementBoard(const Player& player) = 0;
};
}
#endif //BATTLESHIP_VIEW_H
