#include "BattleShip.hpp"

int main(int argc, char** argv) {
  BattleShip::BeginGame game(false);
  char *INFile  = argv[1];

  if(argc == 3){
    int rng = atoi(argv[2]);
    game.setupGame(INFile,rng);
  }else{
    game.setupGame(INFile);
  }
  
  game.play();
  return 0;
}
