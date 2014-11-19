#include "Object.h"
#include "Item.h"

#ifndef PERSON
#define PERSON

class Person : public Object
{
public:
Person(const std::string& name,
	   const std::string& description,
	   const int& weight,
	   const int& length, //Kommer ovan.
	   const bool& can_carry,
	   const std::string& haircolour,
	   const std::string& dialog,
	   const std::string& wanted_item_name_,
	   const std::string& recieved_item_dialog)
    : Object{name,description,weight,length},//Skickar upp i hierarkin
    can_carry_{can_carry}, haircolour_{haircolour},
    dialog_{dialog}, wanted_item_name_{wanted_item_name_},
    recieved_item_dialog_{recieved_item_dialog}
{}

std:: string get_dialog(){return dialog_;}

bool wanted_item(Item&);

// �vriga konstruktorer �r implicita. Unsure,,,,,,
/* std::string get_description() const {return description_;} */
/* std::string get_name() const {return name_;} */

private:
     bool can_carry_;
     std::string haircolour_;
     std::string dialog_;
     std::string wanted_item_name_;
     std::string recieved_item_dialog_;
};
#endif
