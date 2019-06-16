//
// Created by Raunak Anand on 2019-06-01.
//

#include "BattleShip.hpp"

BattleShip::Grid::Grid(char contents, const char marker, const char hit, const char miss): contents(contents), marker(marker), hit(hit), miss(miss) {
  firedAt = false;
}

BattleShip::Grid::Grid(char contents) : contents(contents), marker('*'), hit('X'), miss('O') {
  firedAt = false;
}

char BattleShip::Grid::getContents() const {
  return contents; // to retrieve the status of the board whether places have a hit, miss or normal marker 
}

void BattleShip::Grid::setContents(char blankChar) {
  (*this).contents = blankChar; // normal marker '*'
}

char BattleShip::Grid::visibleContents() const {
  if (firedAt) {
    if (shipIsThere()) {
      return hit;
    } else {
      return miss;
    }
  } else {
    return contents;
  }
}

char BattleShip::Grid::hiddenContents() const {
  if (firedAt) {
    if (shipIsThere()) {
      return hit;
    } else {
      return miss;
    }
  } else {
    return marker;
  }
}

char BattleShip::Grid::gethit() const {
  return hit;
} // if the ship has been hit return hit 'X'

char BattleShip::Grid::getmarker() const {
  return marker;
} // return the normal marker '*'

char BattleShip::Grid::getmiss() const {
  return miss;
} // if missed, return the marker 'O'

bool BattleShip::Grid::alreadyFiredAt() const {
  return firedAt;
}

void BattleShip::Grid::setalreadyFiredAt(bool alreadyFiredAt) {
  (*this).firedAt = alreadyFiredAt;
}

bool BattleShip::Grid::shipIsThere() const {
  return (contents != marker && contents != hit && contents != miss);
}

