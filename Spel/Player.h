#include "Entity.h"
#include "Item.h"
#include "Room.h"
#include "Person.h"
#include "Merchant.h" //bör krav skall fixas sist obs obs obs obs.

//Inkluderar massa skit
#ifndef PLAYER
#define PLAYER

class Player
{
public:
    Player() = default;
    ~Player() = default;
//Instansen skall skapas först
//Sedan tilldelas spelaren sina föremål & pengar.
    void  put_inventory(const Item& item);
    void remove_from_inventory(const int& index);
    void print_inventory();
    Item  get_item_from_inventory(const int& index);
    void read_input(const std::string& input);
    void print_specific_item(const int& index);
    void print_money();
    int get_money();


private:
    int money_{0};  //Spelaren valutareserv.
 std::vector <Item> inventory_; //För äventyrskorgen
};

#endif
