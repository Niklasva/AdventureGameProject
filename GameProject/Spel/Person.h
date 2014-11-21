#include "Object.h"
#include "Item.h"
#include <QString>

#ifndef PERSON
#define PERSON

class Person : public Object
{
public:
Person(const QString& name,
       const QString& description,
	   const int& weight,
	   const int& length, //Kommer ovan.
	   const bool& can_carry,
       const QString& haircolour,
       const QString& dialog,
       const QString& wanted_item_name_,
       const QString& recieved_item_dialog)
    : Object{name,description,weight,length},//Skickar upp i hierarkin
    can_carry_{can_carry}, haircolour_{haircolour},
    dialog_{dialog}, wanted_item_name_{wanted_item_name_},
    recieved_item_dialog_{recieved_item_dialog}
{}

 Person() = default;

QString get_dialog(){return dialog_;}
QString get_recieved_item_dialog(){return recieved_item_dialog_;}

void set_dialog(const QString& dialog){dialog_ = dialog;}
void set_received_item_dialog(const QString& item_dialog){recieved_item_dialog_ = item_dialog;}
void set_haircolour(const QString& haircolour){haircolour_ = haircolour;}
void set_wanted_item_name(const QString& item_name){wanted_item_name_ = item_name;}



bool wanted_item(Item&);

// Övriga konstruktorer är implicita. Unsure,,,,,,





private:
     bool can_carry_;
     QString haircolour_;
     QString dialog_;
     QString wanted_item_name_;
     QString recieved_item_dialog_;
};
#endif
