#include "Object.h"


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
    ~Person() = default;

bool wanted_item(Item&) const;

// Övriga konstruktorer är implicita. Unsure,,,,,,
/* std::string get_description() const {return description_;} */
/* std::string get_name() const {return name_;} */

private:
const bool can_carry_;
const std::string haircolour_;
const std::string dialog_;
const std::string wanted_item_name_;
const std::string recieved_item_dialog_;
};
#endif
