//
// Created by Raunak Anand on 2019-06-01.
//

 #ifndef BATTLESHIP_ATTACKMOVE_H
 #define BATTLESHIP_ATTACKMOVE_H
 #include "Move.h"
 #include "Player.h"

 namespace BattleShip {
 class AttackMove : public Move {
  public:
   ~AttackMove() override = default;
   AttackMove(BattleShip::Player &attacker, int row, int col);
   // carries out attack
   bool didItHit() override;
   bool isValid() const override;
   // checks if the attack was valid or not
   void shipHealth(Creation &model, View &view) override; // ship's health goes down by 1
   void shipHealth(Player &defender, View &view) override; // if opponent hits it
   const int getRow() const;
   int getRowAttack() const override;
   // Returns the row of the attack
   int getColAttack() const override;
   const int getCol() const;
   // Returns the col of the attack
  protected:
   const int row, column;
   bool hit; // bool for if the target was hit or not
 };
 }


 #endif //BATTLESHIP_ATTACKMOVE_H
