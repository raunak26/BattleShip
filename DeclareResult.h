//
// Created by Raunak Anand on 2019-06-01.
//


#ifndef BATTLESHIP_DECLARERESULT_H
#define BATTLESHIP_DECLARERESULT_H

#include "AttackMove.h"

namespace BattleShip {
class DeclareResult {

 public:
  DeclareResult()= default; // default constructor for declaring results
  DeclareResult(bool hit, bool destroy, char ship);

  // member variables
  bool hit;
  bool destroy;
  char ship;
};
}

#endif //BATTLESHIP_DECLARERESULT_H
