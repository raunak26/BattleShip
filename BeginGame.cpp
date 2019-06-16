//
// Created by Raunak Anand on 2019-06-01.
//

#include "BattleShip.hpp"

BattleShip::BeginGame::BeginGame(bool beginGame): beginGame(beginGame), view(std::make_unique<BoardView>(std::cin, std::cout)){

}

BattleShip::BeginGame::BeginGame(){

}

void BattleShip::BeginGame::setupGame(const std::string& GameConfigurationFile, int seed) {
  BattleShip::AiPlayer::seed_random_number_generator(seed);
  setupGame(GameConfigurationFile);
}

void BattleShip::BeginGame::setupGame(const std::string& GameConfigurationFile) {
  creation.fileArguments(GameConfigurationFile);
  NumPlayer config = (*view).getPlayerConfiguration();
  for (int i = 0; i < config.HumanPlayers; i++) {
    creation.addPlayer<HumanPlayer>((*view));
  }
  for (int j = 0; j < config.AiPlayers; j++) {
    int choice = (*view).getAiChoice();
    if (choice == 1) {
      creation.addPlayer<CheatingAi>((*view));
    } else if (choice == 2) {
      creation.addPlayer<RandomAI>((*view));
    } else if (choice == 3) {
      creation.addPlayer<HuntDestroyAI>((*view));
    }
  }
  creation.SetOpponents();
  beginGame = true;
}

void BattleShip::BeginGame::setupGame() {

}



void BattleShip::BeginGame::play() {
  while (!creation.isGameOver()) {
    DeclareResult result;
    Player &attacker = creation.getAttackingPlayer();
    int status;
    std::string className = abi::__cxa_demangle(typeid(attacker).name(), 0, 0, &status);
    if (strncmp(className.c_str(), "BattleShip::HumanPlayer", 16) == 0) {
      (*view).showPlayersBoard(attacker);
      (*view).showPlacementBoard(attacker);
      std::pair<int, int> pos = (*view).getFiringCoordinate(attacker);
      while (true) {
        if (attacker.getOpponent().getBoard().at(pos.first, pos.second).alreadyFiredAt()) {
          pos = (*view).getFiringCoordinate(attacker);
        } else {
          break;
        }
      }
      result = attacker.fire(pos.first, pos.second);
      (*view).showPlayersBoard(attacker);
      (*view).showPlacementBoard(attacker);
    } else {
      std::unique_ptr<Move> move = attacker.getMove();
      while (true) {
        if (attacker.getOpponent().getBoard().at((*move).getRowAttack(), (*move).getColAttack()).alreadyFiredAt()) {
          move = attacker.getMove();
        } else {
          break;
        }
      }
      result = attacker.fire((*move).getRowAttack(), (*move).getColAttack());
      (*view).showPlayersBoard(attacker);
      (*view).showPlacementBoard(attacker);
    }

    (*view).showAttackResult(attacker, result);

    creation.changeTurn();
  }
  (*view).showWinner(creation.getWinner());
}

