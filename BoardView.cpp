//
// Created by Raunak Anand on 2019-06-01.
//

#include "BattleShip.hpp"


BattleShip::BoardView::BoardView(): View(), in(std::cin), out(std::cout) {}

BattleShip::BoardView::BoardView(std::istream& in, std::ostream& out) : in(in), out(out){}

BattleShip::NumPlayer BattleShip::BoardView::getPlayerConfiguration() {
  int choice;
  out << "What type of game do you want to play?\n1. Human vs Human\n2. Human vs AI\n3. AI vs AI\nYour choice: ";
  in >> choice;
  if (choice == 1) {
    return NumPlayer(2, 0);
  } else if (choice == 2) {
    return NumPlayer(1, 1);
  } else {
    return NumPlayer(0, 2);
  }
}

std::pair<int, int> BattleShip::BoardView::getFiringCoordinate(const BattleShip::Player& attacker) {
  int attackRow, attackCol;
  out << attacker.getName() << ", where would you like to fire?\n";
  out << "Enter your attack coordinate in the form row col: ";
  in >> attackRow >> attackCol;
  return std::pair<int, int>(attackRow, attackCol);
}

void BattleShip::BoardView::printVisibleBoard(const Board& board) {
  std::vector<std::string> boardVec = board.getVisibleBoard();
  auto itr = boardVec.begin();
  int rowNum = 0;
  out << "  ";
  for (int j = 0; j < board.getNumCols(); j++) {
    out << j << " ";
  }
  out << "\n";
  for (auto i = itr; i != boardVec.end(); i++) {
    out << rowNum << " " << *i << '\n';
    rowNum++;
  }
}

void BattleShip::BoardView::printHiddenBoard(const Board& board) {
  std::vector<std::string> boardVec = board.getHiddenBoard();
  auto itr = boardVec.begin();
  int rowNum = 0;
  out << "  ";
  for (int j = 0; j < board.getNumCols(); j++) {
    out << j << " ";
  }
  out << "\n";
  for (auto i = itr; i != boardVec.end(); i++) {
    out << rowNum << " " << *i << '\n';
    rowNum++;
  }
}

void BattleShip::BoardView::showAttackResult(const BattleShip::Player& attacker, const BattleShip::DeclareResult& declareResult) {
  if (declareResult.hit) {
    out << attacker.getName() << " hit " << attacker.getOpponent().getName() << "'s " << declareResult.ship << "!\n";
    if (declareResult.destroy) {
      out << attacker.getName() << " destroyed " << attacker.getOpponent().getName() << "'s " << declareResult.ship
          << "!\n";
    }
    out << "\n";
  } else {
    out << "Missed.\n\n";
  }
}

void BattleShip::BoardView::printBoard(const std::vector<std::string>& board) {
  auto itr = board.begin();
  int rowNum = 0;
  out << " ";
  for (int j = 0; j < (int) board.size(); j++) {
    if (j == (int) board.size() - 1) {
      out << j;
      break;
    }
    out << j << " ";
  }
  out << '\n';
  for (auto i = itr; i != board.end(); i++) {
    out << rowNum << " " << *i << '\n';
    rowNum++;
  }
}

void BattleShip::BoardView::showWinner(const BattleShip::Player& winner) {
  out << winner.getName() << " won the game!\n";
}

Ship BattleShip::BoardView::getShipPlacement(const Player& player, char shipChar, int health) {
  char horzOrVert;
  int placeRow, placeCol;
  Ship shipPlacement;
  updatePlacementView(player);
  out << player.getName() << ", do you want to place " << shipChar
      << " horizontally or vertically?\nEnter h for horizontal or v for vertical\nYour choice: ";
  in >> horzOrVert;
  out << player.getName() << ", enter the row and column you want to place " << shipChar << ", which is " << health
      << " long, at with a space in between row and col: ";
  in >> placeRow >> placeCol;
  shipPlacement.rowStart = placeRow;
  shipPlacement.colStart = placeCol;
  if (horzOrVert == 'h') {
    shipPlacement.rowEnd = placeRow;
    shipPlacement.colEnd = placeCol + health - 1;
  } else if (horzOrVert == 'v') {
    shipPlacement.rowEnd = placeRow + health - 1;
    shipPlacement.colEnd = placeCol;
  }
  return shipPlacement;
}

void BattleShip::BoardView::updatePlacementView(const Player& player) {
  int status;
  std::string className = abi::__cxa_demangle(typeid(player).name(), nullptr, nullptr, &status);
  if (strncmp(className.c_str(), "BattleShip::HumanPlayer", 16) != 0) {
    out << player.getName() << "'s Board\n";
  }
  printVisibleBoard(player.getBoard());
  out << "";
}

int BattleShip::BoardView::getAiChoice() {
  int choice;
  out << "What AI do you want?\n1. Cheating AI\n2. Random AI\n3. Hunt Destroy AI\nYour choice: ";
  in >> choice;
  return choice;
}

void BattleShip::BoardView::showPlacementBoard(const Player& player) {
  out << "\n\n" << player.getName() << "'s Placement Board\n";
  printVisibleBoard(player.getBoard());
}

void BattleShip::BoardView::showPlayersBoard(const Player& player) {
  out << player.getName() << "'s Firing Board\n";
  printHiddenBoard(player.getOpponent().getBoard());
}

std::string BattleShip::BoardView::getPlayerName(int i) {
  std::string playerName;
  out << "Player " << i << " please enter your name: ";
  in >> playerName;
  return playerName;
}
