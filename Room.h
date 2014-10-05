#include "Entity.h"
#ifndef ROOM
#define ROOM

class Room : public  Entity 
{
 public:
 Room(const std::string& name, const std::string& description) : Entity {name_, description_}{} // att se över.

  void set_persons(const Person& p) { persons_.push_back(p); }
  void set_objects(const Object& o) { objects_.push_back(p); }

 private: // Innehåller personer och objekt i rummet.
  std::vector<Person> persons_;
  std::vector<Object> objects_;
  const int  n{0},w{0},s{0},e{0};
  const int exits = [n,s,w,e]; 
}
#endif
