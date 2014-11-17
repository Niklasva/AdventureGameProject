#ifndef ROOM
#define ROOM
#include "Entity.h"
#include "Person.h"
#include <vector>
#include <iterator>
#include <algorithm>

//#include "Object.h"
class Person;
class Object;

class Room : public  Entity
{
 public:
 Room(const std::string& name, const std::string& description)
 : Entity {name, description}{} // att se över.

  //void set_persons(const Person& p) { persons_.push_back(p); }
  void set_item(const Item& o) { items_.push_back(o); }
  void set_person(const Person& p){ persons_.push_back(p);}
  void remove_item(const int& index){items_.erase(items_.begin()+index);}
  void remove_person(const int& index){persons_.erase(persons_.begin() + index);}
  void get_directions();

  const std::vector<int> get_room_ids() {return exits;} //returnerar arrayen med utg?ngar.
  std::vector<Person>& get_persons() {return persons_;} //Returnerar en referens till personvektorn.
  std::vector<Item>& get_items(){return items_;}

  Person& get_person(const int& index){ return persons_.at(index); } //Returnerar en person.
  Item& get_item(const int& index){return items_.at(index); }

//  Room operator=(const Room&) = default;
//  Room(const Room&) = default;
//  Room& operator=(Room&&) = default;




 private:
  std::vector<Item> items_;
  std::vector<Person> persons_;
  int  n{0},w{0},s{0},e{0};
  std::vector<int> exits = {n,s,w,e};
};
#endif
