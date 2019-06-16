//
// Created by Raunak Anand on 2019-06-01.
//

#ifndef BATTLESHIP_BOARD_H
#define BATTLESHIP_BOARD_H
#include <string>
#include <vector>
#include "Ship.h"
#include "Grid.h"

namespace BattleShip {
class Board {
 public:
  Board(int numRows, int numCols, char blankChar);
  // Constructor to initialize rows, columns and blankChar
  Board(int numRows, int numCols);
  // Constructor to initialize with just rows and columns

  int getNumRows() const;
  // Returns the total number of rows of the board
  int getNumCols() const;
  // Returns the total number of rows of the board

//  void setBoard(Board& board);

  bool canPlaceShipAt(const Ship& shipPlacement) const;
  // bool to check if we can place ship at particular position

  std::vector<std::string> getHiddenBoard() const;
  // to retrieve the hidden version of the opponents board visible to player 2
  std::vector<std::string> getVisibleBoard() const;
  // to retrieve the visible version of the players board visible to player 1

  void setVals(int rows, int cols);

  void AddShip(char shipChar, const Ship& shipPlacement);
  // Add ship to the current board with a specified ship character
  bool inBounds(int row, int col) const;
  // checks if the row,column are in within the board's area
  // Returns the cell reference at (i,j)
  Grid& at(int i, int j);
  // Returns the constant cell reference at (i,j)
  const Grid& at(int i, int j) const;

  // Board operator=(Board& orig);


 protected:
  bool inBounds(const Ship& shipPlacement) const;
  // checks whether the Ship placement is within the board

  bool between(int value, int low, int high) const;

  bool canPlace(const Ship& shipPlacement) const; // checks whether you can ship placement is possible or not

  //members variables
  int numRows, numColumns;
  std::vector<std::vector<Grid>> boardState;
  const char blankChar;

};
}

//const int BOARD_SIZE = 10;
//const int numOfShips = 5;
//class Board {
// public:
//  Board();
//  Board(const Board &rhs);
//  ~Board() {}
//  void printBoard();
//  void setShip(int shipNumber, int x1, int y1, int x2, int y2);
//  bool isValidDirection(int x1, int y1, int x2, int y2);
//  bool rangeIsOccupied(int x1, int y1, int x2, int y2);
//  bool fitsOnBoard(int x1, int y1, int x2, int y2);
//  bool isSunk(int shipNumber);
//  void randomizeFleet();
//  bool allShipsPlaced();
//  bool allShipsSunk();
//  void printRemainingShips();
//  Ship& operator()(int, int);
//  Ship& getShip(int n) { return Ships[n]; }
//  Board& operator=(const Board &rhs);
//  bool operator==(const Board&);
//  bool operator!=(const Board&);
// private:
//  Ship gameBoard[BOARD_SIZE][BOARD_SIZE];
//  Ship Ships[numOfShips];
//};


#endif //BATTLESHIP_BOARD_H
