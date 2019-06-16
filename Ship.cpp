//
// Created by Raunak Anand on 2019-06-01.
//

#include "BattleShip.hpp"

Ship::Ship() = default;

Ship::Ship(int rowStart, int colStart, int rowEnd, int colEnd) : rowStart(rowStart), colStart(colStart), rowEnd(rowEnd), colEnd(colEnd) {}

void Ship::outOfBoard() {
  if (rowStart > rowEnd || colStart > colEnd) {
    throw std::out_of_range("Start can't be greater than the end");
  }
}

//Ship::Ship(const Ship& rhs) {
//  shipNumber = rhs.shipNumber;
//  name = rhs.name;
//  size = rhs.size;
//  status = rhs.status;
//  firedUpon = rhs.firedUpon;
//}
//
//Ship& Ship::operator=(const Ship &rhs) {
//  if(this != &rhs) {
//    shipNumber = rhs.shipNumber;
//    name = rhs.name;
//    size = rhs.size;
//    status = rhs.status;
//    firedUpon = rhs.firedUpon;
//  }
//  return *this;
//}
//
//bool Ship::operator==(const Ship& rhs) {
//  if((name != rhs.name) || (size != rhs.size) || (status != rhs.status)) {
//    return false;
//  }
//  return true;
//}
//
//bool Ship::operator!=(const Ship& rhs) {
//  return !(*this == rhs);
//}