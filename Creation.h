//
// Created by Raunak Anand on 2019-06-01.
//
// Taken help on templating from CSIF

#ifndef BATTLESHIP_CREATION_H
#define BATTLESHIP_CREATION_H
#include <vector>
#include <memory>
#include "View.h"
#include "Player.h"
#include "Game.h"

namespace BattleShip {
class Move;
class Player;
class View;
class Creation {

 public:
  Creation() = default;

  Game getGameArguments();



  void fileArguments(const std::string& gameConfigurationFile);
  // Loads the game arguments from the configuration files


  template <typename PlayerType>

  void addPlayer(View& view);
  // Adds player 1 and player 2 to the game

  void SetOpponents();
  // Set the players as each other's opponents
  std::vector<std::unique_ptr<Player>> players;
  // vector of the players playing the game


  Player& getAttackingPlayer();
  // Get the current attacking player
  const Player& getAttackingPlayer() const;
  // Get the current attacking player as constant


  Player& getDefendingPlayer();
  // Get the current defending player
  const Player& getDefendingPlayer() const;
  // Get the current defending player as a constant

  void changeTurn();
  // changes the turn between the two players

  void endGame();
  // Ends the game
  std::unique_ptr<Move> getNextMove();
  // Gets the next move of either of the players

  bool isGameOver() const;
  // Checks whether the game is over or not

  Player& getWinner();
  // Gets the winner

 protected:
  Game gameArguments;
  int playerTurn = 0;
  bool forcedEndGame;
};

template<typename PlayerType>
void BattleShip::Creation::addPlayer(View& view) {
  std::unique_ptr<PlayerType> player = std::make_unique<PlayerType>(gameArguments, view);
  (*player).initializeName();
  (*player).placeShips();
  players.push_back(std::move(player));
}

}
#endif //BATTLESHIP_CREATION_H
