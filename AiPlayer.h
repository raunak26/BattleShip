//
// Created by mfbut on 3/9/2019.
//

#ifndef BATTLESHIP_AIPLAYER_H
#define BATTLESHIP_AIPLAYER_H
#include <random>
#include "Player.h"
#include "View.h"
#include "Game.h"
namespace BattleShip {
class Move;
class AiPlayer : public Player {
 public:
  AiPlayer();
  virtual ~AiPlayer(){}
  static void seed_random_number_generator(int seed);
  AiPlayer(const Game& gameAttributes, View& view);
  virtual void placeShips() override;
  virtual void initializeName() override;

 protected:
  static std::mt19937 randomNumberGenerator;

 private:
  static int nextAiId;
  const int aiId;
};
}
#endif //BATTLESHIP_AIPLAYER_H
