#include "Entity.h"
#include "Item.h"
#include "Room.h"
#include "Person.h"
#include "Merchant.h"
#include "adventurewindow.h"
#include "ui_adventurewindow.h"

#ifndef PLAYER_H
#define PLAYER_H

class Game;
class AdventureWindow;
class Player
{
public:
    Player() = default;
    ~Player() = default;



    //Instansen skall skapas först
    //Sedan tilldelas spelaren sina föremål & pengar.
    void  put_inventory(const Item& item){inventory_.push_back(item);}
    void remove_from_inventory(const int& index);
    void print_inventory();
    QString read_input(QString& input,Game& G);
    void print_specific_item(const int& index);
    void print_money();
    QString set_location(const QString& new_location, Game& G, Room& R);
    Item get_item_from_inventory(const int& index);
    int get_money();
    QString look(QString &thing_to_look_at, Game &G);
    std::vector<Item> get_inventory() {return inventory_;}

private:
    int money_{0};
    int location_{1};
    std::vector <Item> inventory_;

    QString decide_direction(QString&, Game& G);
    QString give(QString &, const QString&, Game &);
    QString talk(QString &person_to_talk_with,Game&);
    QString take(QString &thing_to_pick_up, Game&);
    QString toss(QString &item, Game&);


};



#endif // PLAYER_H
