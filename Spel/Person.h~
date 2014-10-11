#include <Object.h>


#ifndef PERSON
#define PERSON

class Person : Public Object
{
public:
Person(const std::string& name,
	   const std::string& description,
	   const std::string& weight,
	   const std::string& length, //Kommer ovan.
	   const bool& can_carry,
	   const std::string& haircolour,
	   const std::string& dialog,
	   const std::string& wanted_item,
	   const std::string& recieved_item_dialog)
    : Object{name,description,weight,length},//Skickar upp i hierarkin
    can_carry_{can_carry}, haircolour_{haircolour},
    dialog_{dialog}, wanted_item_{wanted_item},
    recieved_item_dialog_{recieved_item_dialog}
{}
    ~Person() = default;

bool wanted_item(Item&) const;
    
// Övriga konstruktorer är implicita. Unsure,,,,,,  
/* std::string get_description() const {return description_;} */
/* std::string get_name() const {return name_;} */

private:
const bool can_carry_;
const string haircolour_;
const string dialog_;
const string wanted_item_name_;
const string recieved_item_dialog_;
}
#endif
