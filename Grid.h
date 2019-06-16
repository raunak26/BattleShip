//
// Created by Raunak Anand on 2019-06-01.
//

#ifndef BATTLESHIP_GRID_H
#define BATTLESHIP_GRID_H

namespace BattleShip {
class Grid {
 public:
  Grid(char contents, char marker, char hit, char miss);
  // Constructor for setting the content of the Grid, the hidden marker, the hit marker and the miss Marker
  explicit Grid(char contents);
  // Grid Constructor for setting the content of the Grid; everything else as default


  char getContents() const;
  // Return the content of the cell
  void setContents(char contents);
  // Sets the content of the cell

  char gethit() const; // gets the hit marker
  char getmarker() const; // gets the hidden marker
  char getmiss() const; // gets the miss marker
  

  char hiddenContents() const;
  char visibleContents() const;


  bool alreadyFiredAt() const;
  // Returns whether the cell has been fired at or not
  void setalreadyFiredAt(bool alreadyFiredAt); // Sets the cell has been firedAt boolean

  bool shipIsThere()const;
  // Returns whether the cell has a ship or not

 protected:

  // member variables
  char contents;
  bool firedAt;
  const char marker;
  const char hit;
  const char miss;

};
}

#endif //BATTLESHIP_GRID_H
