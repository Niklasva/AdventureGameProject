#ifndef GAME
#define GAME
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <functional>
#include <exception>
#include <QString>
#include <QFile>
#include <QDebug>
#include "Player.h"
#include "Entity.h"


class Game
{
 public:
  Game() = default;
  void get_help();
  Room& get_room(const int& index){return rooms_.at(index);} //Returnerar rum id
  void add_room(const Room& R)
  {
    if(size_t(number_of_rooms) == rooms_.size())
    {
        rooms_.resize(number_of_rooms*2);

    }
        rooms_.at(number_of_rooms+1) = R;
        ++number_of_rooms;
  }

  int number_of_rooms{0};
  void read_file(const QString& filename);
  std::vector<Room> rooms_{100};

};


#endif
