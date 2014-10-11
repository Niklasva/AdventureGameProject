#include <Entity.h>
//Inkluderar entity.
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
    item  get_item_from_inventory(const int& index);
    void read_input(const string& input); 
    void print_specific_item(const int& index);
    void print_money();
    int get_money();
    

private:
    int money_{0};  //Spelaren valutareserv.
    vector <Item> inventory_; //För äventyrskorgen
}

#endif
