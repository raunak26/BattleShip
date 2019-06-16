//
// Created by Raunak Anand on 2019-06-01.
//

#include "BattleShip.hpp"


BattleShip::Board::Board(int numRows, int numColumns, char blankChar): numRows(numRows), numColumns(numColumns), blankChar(blankChar) {
  Grid cell(blankChar);
  std::vector<BattleShip::Grid> places;
  for (int i = 0; i < getNumRows(); i++) {
    for (int j = 0; j < getNumCols(); j++) {
      places.push_back(cell);
    }
    boardState.push_back(places);
  } // creation of the board depending on the number of rows and columns
}

BattleShip::Board::Board(int numRows, int numColumns): numRows(numRows), numColumns(numColumns), blankChar('*') {
  Grid cell('*');
  std::vector<BattleShip::Grid> places;
  for (int i = 0; i < getNumRows(); i++) {
    for (int j = 0; j < getNumCols(); j++) {
      places.push_back(cell);
    }
    boardState.push_back(places);
  } // creation of the board depending on the number of rows and columns with the '*' symbolizing each piece
}

int BattleShip::Board::getNumRows() const {
  return numRows; // returns the number of rows for the board
}

int BattleShip::Board::getNumCols() const {
  return numColumns; // returns the number of columns for the board
}

bool BattleShip::Board::inBounds(int row, int col) const {
  return (col >= getNumCols() || row >= getNumRows() || row < 0 || col < 0);
}

bool BattleShip::Board::inBounds(const Ship& shipPlacement) const {
  return ((shipPlacement.rowStart < getNumRows() && shipPlacement.rowStart >= 0 && shipPlacement.rowEnd < getNumRows()
      && shipPlacement.rowEnd >= 0)
      && (shipPlacement.colStart < getNumCols() && shipPlacement.colStart >= 0 && shipPlacement.colEnd < getNumCols()
          && shipPlacement.colEnd >= 0));
}

bool BattleShip::Board::canPlace(const Ship& shipPlacement) const {
  for (int i = shipPlacement.rowStart; i <= shipPlacement.rowEnd; i++) {
    for (int j = shipPlacement.colStart; j <= shipPlacement.colEnd; j++) {
      if (boardState.at(i).at(j).getContents() != '*') {
        return false;
      }
    }
  }
  return true;
}

bool BattleShip::Board::canPlaceShipAt(const Ship& shipPlacement) const {
  if (inBounds(shipPlacement)) {
    if (canPlace(shipPlacement)) {
      return true;
    }
  }
  return false;
}

bool BattleShip::Board::between(int value, int low, int high) const {
  return (value <= high && value >= low);
}

BattleShip::Grid& BattleShip::Board::at(int i, int j) {
  return (boardState.at(i)).at(j);
}

const BattleShip::Grid& BattleShip::Board::at(int i, int j) const {
  return (boardState.at(i)).at(j);
}

void BattleShip::Board::AddShip(char shipChar, const Ship& shipPlacement) {
  if (canPlaceShipAt(shipPlacement)) {
    for (int i = shipPlacement.rowStart; i <= shipPlacement.rowEnd; i++) {
      for (int j = shipPlacement.colStart; j <= shipPlacement.colEnd; j++) {
        this->at(i, j).setContents(shipChar);
      }
    }
  } else {
    throw std::out_of_range("Can't place ship here");
  }
}

std::vector<std::string> BattleShip::Board::getHiddenBoard() const {
  std::vector<std::string> board;
  std::string row;
  for (int i = 0; i < getNumRows(); i++) {
    for (int j = 0; j < getNumCols(); j++) {
      row = row + at(i, j).hiddenContents() + " ";
    }
    board.push_back(row);
    row = "";
  }
  return board;
}

std::vector<std::string> BattleShip::Board::getVisibleBoard() const {
  std::vector<std::string> board;
  std::string row;
  for (int i = 0; i < getNumRows(); i++) {
    for (int j = 0; j < getNumCols(); j++) {
      row = row + at(i, j).visibleContents() + " ";
    }
    board.push_back(row);
    row = "";
  }
  return board;
}

void BattleShip::Board::setVals(int rows, int columns) {
  (*this).numRows = rows;
  (*this).numColumns = columns;
}

//Board::Board(const Board &rhs) {
//  for(int i = 0; i < BOARD_SIZE; i++) {
//    for(int k = 0; k < BOARD_SIZE; k++) {
//      gameBoard[i][k] = rhs.gameBoard[i][k];
//    }
//  }
//  for(int i = 0; i < numOfShips; i++) {
//    Ships[i] = rhs.Ships[i];
//  }
//}
//
////x = hit ship
////o = ship on board
////m = empty space
//void Board::printBoard() {
//  std::cout << "x = hit ship\no = ship on board\nm = empty space\n";
//  std::cout << border;
//  std::cout << "   ";
//  for(int i = 0; i < BOARD_SIZE; i++) {
//    std::cout << '|' << alphabet[i] << "|";
//    if(i != BOARD_SIZE - 1) { std::cout << ' '; }
//  }
//  std::cout << "\n";
//  for(int j = 0; j < BOARD_SIZE; j++) {
//    std::cout << j << " - ";
//    for(int k = 0; k < BOARD_SIZE; k++) {
//      if(gameBoard[j][k].getShipNumber() != -1 && gameBoard[j][k].getFiredUpon()) {
//        std::cout << 'x';
//      }
//      else if(!gameBoard[j][k].getStatus()) { std::cout << 'm'; } //empty spaces
//      else { std::cout << 'o'; } //ships that are afloat
//      if(k != BOARD_SIZE - 1) { std::cout << "   "; }
//    }
//    std::cout << "\n";
//  }
//  std::cout << border;
//}
//
//Board::Board() {
//  Ships[0] = Ship("Carrier", 5, sunk, 0);
//  Ships[1] = Ship("Battleship", 4, sunk, 1);
//  Ships[2] = Ship("Cruiser", 3, sunk, 2);
//  Ships[3] = Ship("Submarine", 3, sunk, 3);
//  Ships[4] = Ship("Destroyer", 2, sunk, 4);
//}
//
//Ship& Board::operator()(int x, int y) {
//  return gameBoard[y][x];
//}
//
////returns bool based on if coords are valid direction
//bool Board::isValidDirection(int x1, int y1, int x2, int y2) {
//  if(x1 == x2 || y1 == y2) { return true; }
//  return false;
//}
//
////returns bool based on if range is occupied or not
//bool Board::rangeIsOccupied(int x1, int y1, int x2, int y2) {
//  //if horizontal
//  if(y1 == y2) {
//    while(x1 != x2) {
//      if(gameBoard[y1][x1].getStatus()) {
//        return true;
//      }
//      if(x1 > x2) {
//        x1--;
//      }
//      else {
//        x1++;
//      }
//    }
//    if(gameBoard[y1][x1].getStatus()) {
//      return true;
//    }
//  }
//
//    //if vertical
//  else {
//    while(y1 != y2) {
//      if(gameBoard[y1][x1].getStatus()) {
//        return true;
//      }
//      if(y1 > y2) {
//        y1--;
//      }
//      else {
//        y1++;
//      }
//    }
//    if(gameBoard[y1][x1].getStatus()) {
//      return true;
//    }
//
//  }
//  return false;
//}
//
//bool Board::fitsOnBoard(int x1, int y1, int x2, int y2) {
//  if((x1 >= 0 && x1 < BOARD_SIZE) && (x2 >= 0 && x2 < BOARD_SIZE) && (y1 >= 0 && y1 < BOARD_SIZE) && (y2 >= 0 && y2 < BOARD_SIZE)) { return true; }
//  return false;
//}
//
//bool Board::isSunk(int shipNumber) {
//  return !Ships[shipNumber].getStatus();
//}
//
//bool Board::allShipsPlaced() {
//  for(int i = 0; i < numOfShips; i++) {
//    if(!Ships[i].getStatus()) {
//      return false;
//    }
//  }
//  return true;
//}
//
//bool Board::allShipsSunk() {
//  for(int i = 0; i < BOARD_SIZE; i++) {
//    for(int k = 0; k < BOARD_SIZE; k++) {
//      if(gameBoard[i][k].getStatus()) {
//        return false;
//      }
//    }
//  }
//  return true;
//}
//
//bool Board::operator==(const Board& rhs) {
//  for(int i = 0; i < BOARD_SIZE; i++) {
//    for(int k = 0; k < BOARD_SIZE; k++) {
//      if(gameBoard[i][k] != rhs.gameBoard[i][k]) {
//        return false;
//      }
//    }
//  }
//  for(int r = 0; r < numOfShips; r++) {
//    if(Ships[r] != rhs.Ships[r]) {
//      return false;
//    }
//  }
//  return true;
//}
//
//bool Board::operator!=(const Board& rhs) {
//  return !(*this == rhs);
//}
//
//Board& Board::operator=(const Board &rhs) {
//  if(this != &rhs) {
//    for(int i = 0; i < BOARD_SIZE; i++) {
//      for(int k = 0; k < BOARD_SIZE; k++) {
//        gameBoard[i][k] = rhs.gameBoard[i][k];
//      }
//    }
//    for(int i = 0; i < numOfShips; i++) {
//      Ships[i] = rhs.Ships[i];
//    }
//  }
//  return *this;
//}
//
//void Board::setShip(int shipNumber, int x1, int y1, int x2, int y2) {
//  //checks if valid placement first
//  if(!rangeIsOccupied(x1, y1, x2, y2) && fitsOnBoard(x1, y1, x2, y2) && isValidDirection(x1, y1, x2, y2)) {
//    Ship shipToPlace = Ship(Ships[shipNumber].getName(), Ships[shipNumber].getSize(), afloat, shipNumber);
//    //place ship
//    while((x1 != x2 || y1 != y2)) {
//      gameBoard[y1][x1] = shipToPlace;
//      gameBoard[y1][x1].setShipNumber(shipNumber);
//      if(x1 > x2) {
//        x1--;
//      }
//      else if(x2 > x1) {
//        x1++;
//      }
//      else if(y1 > y2) {
//        y1--;
//      }
//      else if(y2 > y1) {
//        y1++;
//      }
//    }
//    gameBoard[y1][x1] = shipToPlace;
//    Ships[shipNumber].setStatus(afloat);
//  }
//  else {
//    return;
//  }
//}
//
//void Board::randomizeFleet() {
//  srand(static_cast<unsigned int>(time(NULL)));
//  for(int i = 0; i < numOfShips; i++) {
//    int startX = rand() % BOARD_SIZE;
//    int startY = rand() % BOARD_SIZE;
//    int endX = startX;
//    int endY = startY;
//
//    //go vert
//    if(rand() % 2 == 0) {
//      //go up
//      if(rand() % 2 == 0) {
//        endX -= (Ships[i].getSize() - 1);
//      }
//        //go down
//      else {
//        endX += (Ships[i].getSize() - 1);
//      }
//    }
//      //go horiz
//    else {
//      //go left
//      if(rand() % 2 == 0) {
//        endY -= (Ships[i].getSize() - 1);
//      }
//        //go right
//      else {
//        endY += (Ships[i].getSize() - 1);
//      }
//    }
//    setShip(i, startX, startY, endX, endY);
//    //don't incrment i unless ship is placed
//    if(!Ships[i].getStatus()) {
//      i--;
//    }
//  }
//}
//
//void Board::printRemainingShips() {
//  for(int i = 0; i < numOfShips; i++) {
//    if(!Ships[i].getStatus()) {
//      std::cout << Ships[i].getShipNumber() << ". " << Ships[i].getName() << " | Size = " << Ships[i].getSize() << "\n";
//    }
//  }
//}
//
