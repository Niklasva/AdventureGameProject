#ifndef OBJECT
#define OBJECT
#include "Entity.h"
#include "string"
class Object : public Entity
{
public:
    Object(const std::string& name, const std::string& description,
           const int& weight,const int& length)
	: Entity{name,description}, weight_{weight},length_{length}
	{}

     int get_weight();
     int get_length();


    // �vriga konstruktorer �r implicita.

private:
     int weight_,length_;
};
#endif
//Den spanska r�ven rev en annan r�v.
