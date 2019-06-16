//
// Created by Raunak Anand on 2019-06-01.
//

#ifndef BATTLESHIP_SHIP_H
#define BATTLESHIP_SHIP_H

class Ship {
 public:
  Ship();
  Ship(int rowStart, int colStart, int rowEnd, int colEnd);
  int rowStart{}, colStart{};
  int rowEnd{}, colEnd{};
 protected:
  void outOfBoard(); // this function throws an exception if rowStart > rowEnd or colStart > colEnd
};

//enum Afloat {afloat = true, sunk = false};
//
//class Ship {
// public:
//  Ship() { }
//  Ship(std::string nName, int nSize, Afloat nStatus, int nShipNumber) { name = nName; size = nSize; status = nStatus; shipNumber = nShipNumber;}
//  Ship(const Ship& rhs);
//  ~Ship() { }
//  int getSize() { return size; }
//  void setSize(int nSize) { size = nSize; }
//  std::string getName() { return name; }
//  void setName(std::string nName) { name = nName; }
//  bool getStatus() { return status; }
//  void setStatus(Afloat nStatus) { status = nStatus; }
//  bool getFiredUpon() { return firedUpon; }
//  void setFiredUpon(bool f) { firedUpon = f; }
//  int getShipNumber() { return shipNumber; }
//  void setShipNumber(int n) { shipNumber = n; }
//  Ship& operator=(const Ship&);
//  bool operator==(const Ship&);
//  bool operator!=(const Ship&);
// private:
//  int shipNumber = -1;
//  std::string name = "";
//  int size = 0;
//  //true = sunk, false = afloat
//  Afloat status = sunk;
//  bool firedUpon = false;
//};

#endif //BATTLESHIP_SHIP_H
