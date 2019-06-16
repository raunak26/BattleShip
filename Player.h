//
// Created by Raunak Anand on 2019-06-01.
//
// took help from CSIF

#ifndef BATTLESHIP_PLAYER_H
#define BATTLESHIP_PLAYER_H
#include <functional>
#include <string>
#include <memory>
#include <map>
#include "Creation.h"
#include "Move.h"
#include "Game.h"
#include "View.h"
#include "Board.h"
#include "DeclareResult.h"

namespace BattleShip {
class View; 
class Move;
class Board;
class Creation;
class Player {
 public:
  virtual ~Player(){}
  Player(const Game& gameAttributes, View& view);

  const std::string& getName() const;
  // gets the constant player name
  void setName(const std::string& name);
  // Sets the constant player name

  Player& getOpponent();
  // Gets the current player's opponent
  const Player& getOpponent() const;
  // Gets the current player's opponent as a constant
  void setOpponent(Player& opponent);

  const int getId() const; // Returns player Id

  const Board& getBoard() const;
  Board& getBoard();
  // Returns the board


  bool operator==(const Player& rhs) const;
  bool operator!=(const Player& rhs) const;

  virtual std::unique_ptr<BattleShip::Move> getMove() = 0;
  //Function to place the ships in the respective positions
  virtual void placeShips() = 0;
  virtual void initializeName() = 0;

  virtual bool StatusSunk() const;
  // checks if all the ships have sunk or not

  virtual BattleShip::DeclareResult fire(int row, int col);

  std::map<char, int> shipHealths;

 protected:
  virtual bool hit(char shipChar); // checks if a ship has been hit or not
  static int instances;
  const int id;
  std::string playername;
  
  View& view;
  Board board;
  Player* opponent;
};
}


//template <>
//class std::hash<BattleShip::Player&>{
//  std::size_t operator()(const BattleShip::Player& player) const {
//    return player.getId();
//  }
//};
//
//class Player {
// public:
//  Player() { }
//  Player(int nID) { id = nID; }
//  Player(std::string nType, int nID) { playerType = nType; id = nID; }
//  Player(const Player &rhs);
//  std::string getPlayerType() { return playerType; }
//  void setPlayerType(std::string nType) { playerType = nType; }
//  int getID() { return id; }
//  void setID(int nID) { id = nID; }
//  bool getTurn() { return turn; }
//  void setTurn(bool nTurn) { turn = nTurn; }
//  Board& getBoard() { return playerBoard; }
//  Ship& operator()(int, int);
//  Player& operator=(const Player &p);
//  bool operator==(const Player &rhs);
//  bool operator!=(const Player&);
// private:
//  Board playerBoard;
//  std::string playerType = "";
//  int id = -1;
//  bool turn = false;
//};



#endif //BATTLESHIP_PLAYER_H

