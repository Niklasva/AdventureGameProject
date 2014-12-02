#include "Player.h"

#ifndef GAME_H
#define GAME_H

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
#include "adventurewindow.h"
#include "Entity.h"





class Game
{
public:
    Room& get_room(const int& index){return rooms_.at(index);} //Returnerar rum id
    Room* get_room_ptr(const size_t& index) {return &rooms_.at(index);}
    void add_room(const Room& R){rooms_.push_back(R);}
    void read_file(const QString& filename);

    int number_of_rooms{1};
    std::vector<Room> rooms_{1};
    QString& get_help(){return help_;}
    void set_help(QString help) {help_ = help;}
private:
    QString help_;
};



#endif // GAME_H
