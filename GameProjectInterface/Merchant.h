#ifndef MERCHANT_H
#define MERCHANT_H

#include "Person.h"


class Merchant : public Person
{
public:
    Merchant(const QString& name,
             const QString& description,
             const int& weight,
             const int& length, //Kommer ovan.
             const bool& can_carry,
             const QString& haircolour,
             const QString& dialog,
             const QString& wanted_item,
             const QString& recieved_item_dialog)
        : Person{name,description,weight,length,can_carry,haircolour,dialog,
                 wanted_item,recieved_item_dialog}//Skickar upp i hierarkin

    {}

    Merchant() = default;


    void add_item(const Item& I){items_for_sale_.push_back(I);}
    void remove_item(const int& index){items_for_sale_.erase(items_for_sale_.begin()+index);}
    std::vector<Item> get_items_for_sale(){ return items_for_sale_;}
    Item get_item(const int& index)& {return items_for_sale_.at(index);}


private:
    std::vector<Item> items_for_sale_;
};



#endif // MERCHANT_H
