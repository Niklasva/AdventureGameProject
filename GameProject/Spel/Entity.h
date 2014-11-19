#ifndef ENTITY
#define ENTITY
#include <vector>
#include <string>
class Entity
{
 public:
  //~Entity() = default;

  // �vriga konstruktorer �r implicita.
  std::string get_description() const {return description_;}
  std::string get_name() const {return name_;}

 protected:
  Entity(const std::string& name, const std::string& description):
   description_{description}, name_{name}
   {}

 private:
     std::string name_,description_;
};
#endif
