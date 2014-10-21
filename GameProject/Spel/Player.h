#include "Entity.h"
#include "Item.h"
#include "Room.h"
#include "Person.h"
#include "Merchant.h" //bör krav skall fixas sist obs obs obs obs.
#include "Game.h"
//Inkluderar massa skit
#ifndef PLAYER
#define PLAYER
class Game;
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
  void read_input(std::string input,Game& G);
  void print_specific_item(const int& index);
  void print_money();
  Item get_item_from_inventory(const int& index);
  int get_money();


 private:
  int money_{0};  //Spelaren valutareserv.
  std::vector <Item> inventory_; //För äventyrskorgen
};

#endif
