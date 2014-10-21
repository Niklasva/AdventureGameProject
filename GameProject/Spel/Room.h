#ifndef ROOM
#define ROOM
#include "Entity.h"
//#include "Person.h"
//#include "Object.h"
class Person;
class Object;

class Room : public  Entity
{
 public:
 Room(const std::string& name, const std::string& description)
 : Entity {name, description}{} // att se över.

  void set_persons(const Person& p) { persons_.push_back(p); }
  void set_objects(const Object& o) { objects_.push_back(o); }

 private: // Innehåller personer och objekt i rummet.
  std::vector<Person> persons_;
  std::vector<Object> objects_;
  const int  n{0},w{0},s{0},e{0};
  const int exits[4] = {n,s,w,e};
};
#endif
