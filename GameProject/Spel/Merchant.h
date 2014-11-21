#ifndef MERCHANT
#define MERCHANT
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


  // Övriga konstruktorer är implicita. Unsure,,,,,,
  /* std::string get_description() const {return description_;} */
  /* std::string get_name() const {return name_;} */

  //*******
  void barter();
  //*******


 private:
  std::vector<Item> items_for_sale;
};
#endif
