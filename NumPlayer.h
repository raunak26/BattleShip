//
// Created by Raunak Anand on 2019-06-01.
//

#ifndef BATTLESHIP_NUMPLAYER_H
#define BATTLESHIP_NUMPLAYER_H
namespace BattleShip {
class NumPlayer {

 public:
  NumPlayer(int HumanPlayers, int AiPlayers); // this constructor gives the number of human and AI players
  int HumanPlayers, AiPlayers;
};
}
#endif //BATTLESHIP_NUMPLAYER_H
