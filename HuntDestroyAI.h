//
// Created by Raunak Anand on 2019-06-01.
//

#ifndef BATTLESHIP_HUNTDESTROYAI_H
#define BATTLESHIP_HUNTDESTROYAI_H
#include <vector>
#include <algorithm>
#include "RandomAI.h"

namespace BattleShip {
class HuntDestroyAI : public RandomAI{
 public:

  HuntDestroyAI(const Game& gameArguments, View& view); // Constructor for the Hunt and Destroy AI with game parameters and its view
  // Gets the hunt and destroy AI's move
  std::unique_ptr<Move> getMove() override;
 protected:

  std::vector<std::pair<int, int>> getArea(const std::pair<int, int>& center) const;
  // this vector stores surrounding area

  //member variables
  std::vector<std::pair<int,int>> firingQueue;
  bool huntGameMode;
  char shipsToBeDestroyed;

};
}

#endif //BATTLESHIP_HUNTDESTROYAI_H
