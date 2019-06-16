//
// Created by Raunak Anand on 2019-06-01.
//

#ifndef BATTLESHIP_BOARDVIEW_H
#define BATTLESHIP_BOARDVIEW_H
#include <iostream>
#include <utility>
#include "NumPlayer.h"
#include "View.h"
#include "Creation.h"

namespace BattleShip  {
class Creation;
class BoardView : public View{
 public:
  // Default Constructor
  BoardView();
  BoardView(std::istream& in, std::ostream& out); // Constructor for initializing in and out stream

  NumPlayer getPlayerConfiguration() override;
  // Returns the player configuration

  std::string getPlayerName(int i) override; // Returns the given player's name

  void showPlayersBoard(const Player& player) override;
  // Show a player's placement board
  void showPlacementBoard(const Player& player) override;
 protected:
  // Print the board
  void printBoard(const std::vector<std::string>& board);
  // Print the placement board visible to the user
  void printVisibleBoard(const Board& board);
  // Print the firing board not visible to the user
  void printHiddenBoard(const Board& board);

  Ship getShipPlacement(const Player& player, char shipChar, int health) override;
  // function provides option to place ship vertically or horizontally
  void updatePlacementView(const Player& player) override;
  // Updates board after placing a ship
  // Gets the attackers firing coordinates
  std::pair<int, int> getFiringCoordinate(const BattleShip::Player& attacker) override;
  // Print the winner of the game
  void showWinner(const Player& winner) override;
  // Prints the result of the attack
  void showAttackResult(const BattleShip::Player& attacker,
                                    const BattleShip::DeclareResult& attackResult) override;

 public:
  int getAiChoice() override;
 protected:
  // Clears the given input by the user
  void input();
  std::istream& in;
  std::ostream& out;
};
}

#endif //BATTLESHIP_BOARDVIEW_H
