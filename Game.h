//
// Created by Raunak Anand on 2019-06-01.
//

#ifndef BATTLESHIP_GAME_H
#define BATTLESHIP_GAME_H
#include <istream>
#include <map>

//class Game {
// public:
//  Game();
//  Player& getPlayer(int id);
//  void fire(Player&, int, int); //attacks enemy ship
// private:
//  Player p1;
//  Player p2;
//};

namespace BattleShip {
class Game {
 public:
  explicit Game(std::istream& in);// Constructor to initialize Game with given number of rows and columns along with ships through an input stream
  // main constructor

  Game(); // done for fun please ignore // CSIF
  // Constructor to initialize Game with the default configuration
  Game(int numRows, int numCols); // done for fun please ignore // CSIF
  // Constructor to initialize Game with given number of rows and columns


  // ^^required constructors - don't delete

  int getNumCols() const;
  // Returns the number of cols in the board
  void setNumCols(int numCols);
  // Sets the number of cols in the board

  int getNumRows() const;
  // returns the number of rows on the board
  void setNumRows(int numRows);
  // sets the number of rows on the board

  int getShipSize(char ShipChar) const;
  // Returns the size of a ship specified by a character in config file

  const std::map<char, int>& getShipParameters() const;
  // creation of map of character denoting ship to its size

  void setShipParameters(std::map<char, int> shipParameters);

 private:
  //member variables
  int numRows, numColumns;
  std::map<char, int> shipParameters;
};

std::istream& operator>>(std::istream& in, Game& gameArguments);

}

#endif //BATTLESHIP_GAME_H
